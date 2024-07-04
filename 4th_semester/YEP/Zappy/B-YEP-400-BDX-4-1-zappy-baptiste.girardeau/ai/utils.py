import time

view = {(0,0) : None,
        (-1,1) : None,
        (0,1) : None,
        (1,1) : None,
        (-2,2): None,
        (-1,2) : None,
        (0,2): None,
        (1,2): None,
        (2,2): None,
        (-3,3) : None,
        (-2,3) : None,
        (-1,3) : None,
        (0,3) : None,
        (1,3) : None,
        (2,3) : None,
        (3,3) : None,
        (-4,4) : None,
        (-3,4) : None,
        (-2,4) : None,
        (-1,4) : None,
        (0,4) : None,
        (1,4) : None,
        (2,4) : None,
        (3,4) : None,
        (4,4) : None,
        (-5,5) : None,
        (-4,5) : None,
        (-3,5) : None,
        (-2,5) : None,
        (-1,5) : None,
        (0,5) : None,
        (1,5) : None,
        (2,5) : None,
        (4,5) : None,
        (3,5) : None,
        (5,5) : None,
        (-6,6) : None,
        (-5,6) : None,
        (-4,6) : None,
        (-3,6) : None,
        (-2,6) : None,
        (-1,6) : None,
        (0,6) : None,
        (1,6) : None,
        (2,6) : None,
        (3,6) : None,
        (4,6) : None,
        (5,6) : None,
        (6,6) : None,
        (-7,7) : None,
        (-6,7): None,
        (-5,7) : None,
        (-4,7) : None,
        (-3,7) : None,
        (-2,7) : None,
        (-1,7) : None,
        (0,7) : None,
        (1,7) : None,
        (2,7) : None,
        (3,7) : None,
        (4,7) : None,
        (5,7) : None,
        (6,7) : None,
        (7,7) : None,
        (-8,8) : None,
        (-7,8) : None,
        (-6,8): None,
        (-5,8) : None,
        (-4,8) : None,
        (-3,8) : None,
        (-2,8) : None,
        (-1,8) : None,
        (0,8) : None,
        (1,8) : None,
        (2,8) : None,
        (3,8) : None,
        (4,8) : None,
        (5,8) : None,
        (6,8) : None,
        (7,8) : None,
        (8,8) : None}

mouvement_broadcast = {
    1 : ["Forward"],
    2 : ["Forward", "Left", "Forward"],
    3 : ["Left", "Forward"],
    4 : ["Left", "Forward", "Left", "Forward"],
    5: ["Left", "Left", "Forward"],
    6 : ["Right", "Forward", "Right", "Forward"],
    7 : ["Right", "Forward"],
    8 : ["Forward", "Right", "Forward"],
}

def get_caost_to_tile(tile):
    deplacement = 0
    lst = []
    to_add = 1
    x = 0
    y = 0
    while (y != tile[1]):
        y += to_add
        lst.append("Forward")
        deplacement += 1
    if (tile[0] == 0):
        return (deplacement, lst)
    if (tile[0] < 0):
        lst.append("Left")
        to_add = -1
        deplacement += 1
    else:
        lst.append("Right")
        deplacement += 1
    while (x != tile[0]):
        deplacement += 1
        lst.append("Forward")
        x += to_add
    return (deplacement, lst)

def parse_arguments(argv):
    args = {"port": None, "name": None, "hostname": "localhost"}
    try:
        for i in range(len(argv)):
            if argv[i] == "-p":
                if int(argv[i + 1]) < 0 or int(argv[i + 1]) > 65535:
                    exit(84)
                args["port"] = argv[i + 1]
            if argv[i] == "-n":
                args["name"] = argv[i + 1]
            if argv[i] == "-h":
                args["hostname"] = argv[i + 1]
        if args["port"] is None or args["name"] is None:
            raise ValueError("Port and team name must be provided")
        return args
    except:
        exit(84)

def parse_line_separator(line, separator):
    cleaned_line = line.strip().strip('[]')
    elements = cleaned_line.split(separator)
    result = []
    for element in elements:
        trimmed_element = element.strip()
        if trimmed_element:
            parts = trimmed_element.split()
            result.append(parts)
        else:
            result.append([None])
    return result

def parse_line(line):
    cleaned_line = line.strip().strip('[]')
    elements = cleaned_line.split(',')
    result = []
    for element in elements:
        trimmed_element = element.strip()
        if trimmed_element:
            parts = trimmed_element.split()
            result.append(parts)
        else:
            result.append([None])
    return result

def list_to_coos_dict(list, new_dict):
    for key, value in zip(new_dict, list):
        new_dict[key] = value
    return new_dict

def dico_to_food_dico(dico):
    food_dico = {}
    for key, value in dico.items():
        if value is None:
            continue
        for elem in value:
            if elem == "food":
                food_dico[key] = value
    return food_dico

def dico_to_resources_dico(dico):
    resources_dico = {}
    resources = ["linemate", "deraumere", "sibur", "mendiane", "phiras", "thystame"]
    for key, value in dico.items():
        if value is None:
            continue
        for elem in value:
            if elem in resources:
                if key not in resources_dico:
                    resources_dico[key] = []
                resources_dico[key].append(elem)
    return resources_dico

def search_from_coos(coos, dico):
    count = 0
    for key, value in dico.items():
        if (key == coos):
            return value

def list_to_dict(self, lst):
        result_dict = {}
        for i, sublist in enumerate(lst, 0):
            key = list(view.keys())[i]
            result_dict[key] = sublist
        return result_dict

def move_to(position):
    current_x, current_y = (0, 0)
    target_x, target_y = position
    movements = []

    dx = target_x - current_x
    dy = target_y - current_y

    for _ in range(abs(dy)):
        movements.append("Forward")

    if dx < 0:
        movements.append("Left")
        for _ in range(abs(dx)):
            movements.append("Forward")
    elif dx > 0:
        movements.append("Right")
        for _ in range(abs(dx)):
            movements.append("Forward")

    return movements

def count_food(lst):
    if lst is None:
        return 0
    count = 0
    for elem in lst:
        if elem == "food":
            count += 1
    return count

def take_resources(ai, position, resources):
    movements = ai.move_to(position)
    for move in movements:
        ai.send_command(move)
    for resource in resources:
        ai.send_command(f"Take {resource}")

def send_actions(ai, lst, nb_food):
    for elem in lst:
        response = ai.send_command(elem)
    while (nb_food != 0):
        response = ai.send_command("Take food")
        nb_food -= 1
    return "ok"

def response_parser(line, ai):
    if line is None:
        return []

    split_line = line.split("\n")
    list_message = []
    for elem in split_line:
        if not elem.strip():
            continue
        #print(f"command received : {elem}")
        ai.command_queue -= 1
        parsed_elem = parse_line(elem)
        if parsed_elem and parsed_elem[0] and parsed_elem[0][0] == 'player':
            ai.look = list_to_coos_dict(parsed_elem, view)
            for key in ai.look:
                if ai.look[key] is None:
                    ai.look[key] = []
        elif parsed_elem and parsed_elem[0] and parsed_elem[0][0] == 'food':
            ai.inventory = parse_inventory(elem)
        else:
            list_message.append(elem)
    return list_message


def parse_inventory(response):
    # print(f"Parsing inventory response: {response}")
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
    # print(f"Parsed inventory: {inventory}")
    return inventory

def is_broadcast(message):
    return message.strip().lower().startswith("message")

def move_to_broadcaster(ai, movement):
    if movement == 0:
        #print("I'm ready for incantation")
        return
    for elem in mouvement_broadcast[movement]:
        ai.send_command(elem)
        print(elem)
    return "ok"

def process_message(message, ai):
    if message in ["ok", "ko"]:
        return []

    actions = []
    if is_broadcast(message):
        tab = message.replace(",", " ").split()
        if tab[0] == 'message':
            broadcast_content = tab[2].split('@')
            if broadcast_content[0] == 'Come':
                level = int(broadcast_content[1])
                if level == ai.level:
                    move_to_broadcaster(ai, int(tab[1]))
                    ai.gamemode = 3
    else:
        tab = message.replace(':',' ').split()
        if tab[0] == "Elevation":
            print("stand by for elevation")
            ai.gamemode = 3
            time.sleep(3)
        elif tab[0] == "Current":
            print(f"---------- LEVEL UP TO LEVEL {tab[2]} ----------")
            ai.level = int(tab[2])
            ai.gamemode = 0
    return actions
