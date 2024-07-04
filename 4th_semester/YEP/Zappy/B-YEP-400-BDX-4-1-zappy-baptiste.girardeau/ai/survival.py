from .priority import food_dico_to_priority_dico, resources_dico_to_priority_dico, search_mov, calculate_priorities, execute_highest_priority_move
from .utils import (
    parse_line,
    list_to_coos_dict,
    view,
    dico_to_food_dico,
    dico_to_resources_dico,
    count_food,
    send_actions,
    search_from_coos
)

def survie(ai, result):
    time_unit = 10
    response = ai.look
    parsed_output = parse_line(response)
    result = list_to_coos_dict(parsed_output, view)
    food_dico = dico_to_food_dico(result)
    if not food_dico:
        return "ko"

    priority_dico = food_dico_to_priority_dico(food_dico, 100)
    while True:
        if not priority_dico:
            print("Can't eat")
            return "ko"
        better = search_mov(priority_dico)
        if better[1][0] == 1000 or time_unit > better[1][0]:
            return send_actions(ai, better[1][1], count_food(search_from_coos(better[0], food_dico)))
        print("retry\n")