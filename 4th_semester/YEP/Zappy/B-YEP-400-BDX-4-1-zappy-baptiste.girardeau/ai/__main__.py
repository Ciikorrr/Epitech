#!/usr/bin/env python3
import os, threading, sys, time
from ai import (
    ZappyAI,
    parse_arguments,
    parse_line,
    list_to_coos_dict,
    view,
    dico_to_food_dico,
    dico_to_resources_dico,
    move_to,
    execute_highest_priority_move,
    calculate_priorities,
    move_to_broadcaster,
    process_message,
    survie,
    eat_or_mine,
    incantation_bis,
    response_parser
)

if __name__ == "__main__":
    args = parse_arguments(sys.argv)
    host = args["hostname"]
    port = int(args["port"])
    team_name = args["name"]
    ai = ZappyAI(host, port, team_name)
    ai.connect()
    while True:
        print(f"command queue : {ai.command_queue}")
        ai.send_command("Look")
        ai.send_command("Inventory")
        response = ai.receive_message()
        if response is None:
            continue
        parsed_response = response_parser(response, ai)
        ai.bouffe = ai.inventory['food']
        for response in parsed_response:
            actions = process_message(response, ai)
        if ai.bouffe < 5:
            ai.gamemode = 0
        elif ai.bouffe > 30:
            ai.gamemode = 1
        elif ai.gamemode == 0 and ai.bouffe < 30:
            ai.gamemode = 0
        elif ai.gamemode == 2 and ai.bouffe > 15:
            print('Need a player for incantation')
            info = " Come" + "@" + str(ai.level)
            ai.send_command("Broadcast" + info)
            time.sleep(1)
        result = eat_or_mine(ai, ai.look, (ai.bouffe * 126), ai.level, ai.gamemode)
        if result == "ok":
            print(f"action successful with food = {ai.bouffe}")
        if result == "incantation":
            ai.gamemode = 2
            if incantation_bis(ai, ai.look, ai.bouffe) == 'ok':
                ai.gamemode = 4