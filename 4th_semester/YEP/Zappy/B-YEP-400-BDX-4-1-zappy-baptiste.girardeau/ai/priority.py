from .utils import count_food, move_to_broadcaster, get_caost_to_tile, search_from_coos, dico_to_resources_dico, dico_to_food_dico, move_to, send_actions, parse_line, parse_line_separator
from .network import ZappyAI
import random
import time

resources_per_level = {
    1: {"linemate": 1, "deraumere": 0, "sibur": 0, "mendiane": 0, "phiras": 0, "thystame": 0},
    2: {"linemate": 1, "deraumere": 1, "sibur": 1, "mendiane": 0, "phiras": 0, "thystame": 0},
    3: {"linemate": 2, "deraumere": 0, "sibur": 1, "mendiane": 0, "phiras": 2, "thystame": 0},
    4: {"linemate": 1, "deraumere": 1, "sibur": 2, "mendiane": 0, "phiras": 1, "thystame": 0},
    5: {"linemate": 1, "deraumere": 2, "sibur": 1, "mendiane": 3, "phiras": 0, "thystame": 0},
    6: {"linemate": 1, "deraumere": 2, "sibur": 3, "mendiane": 0, "phiras": 1, "thystame": 0},
    7: {"linemate": 2, "deraumere": 2, "sibur": 2, "mendiane": 2, "phiras": 2, "thystame": 1},
}

needed_player_per_level = {
    2 : 1,
    3 : 2,
    4 : 2,
    5 : 4,
    6 : 4,
    7 : 6,
    8 : 6,
}

def count_player(content):
    if 0 not in content:
        return 0
    count = 0
    for elem in content[0]:
        if elem == "player":
            count += 1
    return count

def drop_all_items_needed(ai):
    for key_bis, value_bis in resources_per_level[ai.level].items():
        for _ in range(value_bis):
            to_drop = "Set " + key_bis
            ai.send_command(to_drop)

def incantation_bis(ai, look, bouffe):
    print("Sufficient resources to level up.")
    tile_content = look.get((0, 0), [])
    if tile_content is None:
        tile_content = []
    elif isinstance(tile_content, str):
        tile_content = tile_content.split()
    nb_player = count_player({0: tile_content})
    #print(f"Number of players: {nb_player}")
    if nb_player >= needed_player_per_level[ai.level + 1]:
        if (bouffe > 15):
            #print("Starting incantation")
            drop_all_items_needed(ai)
            ai.send_command("Incantation")
            return "ok"
    return "ko"


def survie(ai, view_dict, lifetime_unit, mov):
    # print("Searching for food.")
    food_dico = dico_to_food_dico(view_dict)
    if not food_dico:
        ai.send_command(random.choice(mov))
        # print("No food found nearby.")
        return "ko"
    food_priority_dico = food_dico_to_priority_dico(food_dico)
    better = search_mov(food_priority_dico)
    if better is None:
        # print("No valid food positions found.")
        return "ko"
    if better[1][0] == 1000 or lifetime_unit > better[1][0]:
        return send_actions(ai, better[1][1], count_food(search_from_coos(better[0], food_dico)))
    return "ko"

def parse_inventory(response):
    inventory = {}
    cleaned_response = response.strip().strip('[]{}')
    items = cleaned_response.split(',')
    for item in items:
        parts = item.strip().split()
        if len(parts) != 2:
            # print(f"Skipping invalid inventory item: {item}")
            continue
        resource, amount = parts
        try:
            inventory[resource] = int(amount)
        except ValueError:
            # print(f"Skipping invalid inventory amount: {item}")
            continue
    return inventory

def check_inventory_for_upgrade(ai, current_level):
    resources_needed = resources_per_level.get(current_level, {})
    for resource, required_amount in resources_needed.items():
        available_amount = ai.inventory.get(resource, 0)
        if available_amount < required_amount:
            return False
    return True

def minerais(ai, view_dict, mov, level):
    if check_inventory_for_upgrade(ai, level):
        return "incantation"
    # print("Searching for resources.")
    resources_dico = dico_to_resources_dico(view_dict)
    if not resources_dico:
        ai.send_command(random.choice(mov))
        # print("No resources found nearby.")
        return "ko"
    resources_priority_dico = resources_dico_to_priority_dico(resources_dico, level)
    if not resources_priority_dico:
        ai.send_command(random.choice(mov))
        # print("No resources found nearby.")
        return "ko"
    return execute_highest_priority_move(ai, resources_priority_dico)

def eat_or_mine(ai, view_dict, lifetime_unit, level, mode):
    mov = ["Left", "Right", "Forward"]
    if mode == 0:
        return survie(ai, view_dict, lifetime_unit, mov)
    elif mode == 1 or mode == 2:
        return minerais(ai, view_dict, mov, level)
    else:
        return "ok"

def search_mov(dico):
    better = None
    highest_priority = -1
    key_save = None
    for key, resources in dico.items():
        for resource, (priority, movements) in resources.items():
            if priority > highest_priority:
                highest_priority = priority
                better = (key, (priority, movements))
                key_save = key

    if key_save is not None:
        dico.pop(key_save)
    return better

def food_dico_to_priority_dico(food_dico):
    priority_dico = {}
    for key, value in food_dico.items():
        if value is None:
            continue
        count = count_food(value)
        deplacement = get_caost_to_tile(key)
        if deplacement[0] == 0:
            rapport = 1000
        else:
            rapport = count / deplacement[0]
        if key not in priority_dico:
            priority_dico[key] = {}
        priority_dico[key]["food"] = (round(rapport, 2), deplacement[1])
    return priority_dico

def resources_dico_to_priority_dico(resources_dico, level):
    priority_dico = {}
    resources_needed = resources_per_level.get(level, {})
    for key, value in resources_dico.items():
        count_dict = {resource: value.count(resource) for resource in set(value)}
        for resource, count in count_dict.items():
            if resource in resources_needed and resources_needed[resource] > 0:
                deplacement = get_caost_to_tile(key)
                if deplacement[0] == 0:
                    rapport = 1000
                else:
                    rapport = count / deplacement[0]
                if key not in priority_dico:
                    priority_dico[key] = {}
                priority_dico[key][resource] = (round(rapport, 2), deplacement[1])
    return priority_dico

def find_highest_priority_position(priority_dico):
    highest_priority = -1
    best_position = None
    for position, resources in priority_dico.items():
        for resource, (priority, movements) in resources.items():
            if priority > highest_priority:
                highest_priority = priority
                best_position = position
    return best_position

def execute_highest_priority_move(ai, priority_dico):
    best_position = find_highest_priority_position(priority_dico)
    if best_position is not None:
        movements = move_to(best_position)
        if not movements:
            resources = priority_dico[best_position]
            for resource in list(resources.keys()):
                response = ai.send_command(f"Take {resource}")
                if response is None:
                    continue
                if response.strip() == "ok":
                    del resources[resource]
            return "ok"
        for move in movements:
            response = ai.send_command(move)
            if response is None:
                continue
        resources = priority_dico[best_position]
        for resource in list(resources.keys()):
            if response is None:
                continue
            if response.strip() == "ok":
                del resources[resource]
        return "ok"
    else:
        return "ko"

def calculate_priorities(food_dico, resources_dico, f, level):
    food_priority_dico = food_dico_to_priority_dico(food_dico, f)
    resources_priority_dico = resources_dico_to_priority_dico(resources_dico, f, level)
    return food_priority_dico, resources_priority_dico
