#!/usr/bin/env python3

import argparse

def parse_number_combination(list_num):
    for elm in list_num:
        if (not elm.isdigit()):
            exit(84)
        if (int(elm) < 1 or int(elm) > 6):
            exit(84)

def parse_combination(method, list_num):
    if (len(list_num) == 1):
        if (method != "pair" and
            method != "three" and
            method != "four" and
            method != "straight" and
            method != "yams"):
            exit(84)
        if (method == "straight" and int(list_num[0]) != 5 and int(list_num[0]) != 6):
                exit(84)
        parse_number_combination(list_num)
        return
    if (len(list_num) == 2):
        if (method != "full"):
            exit(84)
        if (int(list_num[0]) == int(list_num[1])):
            exit(84)
        parse_number_combination(list_num)
        return
    exit(84)


def get_args():
    parser = argparse.ArgumentParser(
        usage="%(prog)s\n\t./201yams d1 d2 d3 d4 d5 c"
    )
    parser.add_argument(
        "d1",
        type=int,
        help="value of the first die (0 if not thrown)",
        nargs=5
    )
    parser.add_argument(
        "c",
        type=str,
        help="expected combination"
    )
    try:
        args = parser.parse_args(None, None)
    except:
        exit(84)
    for elm in args.d1:
        if (6 < elm or elm < 0):
            exit(84)
    x = args.c.split('_')
    method = x.pop(0)
    parse_combination(method, x)
    return [args.d1, method, [int(e) for e in x]]
