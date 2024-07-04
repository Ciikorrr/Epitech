#!/bin/python
import argparse

def get_args():
    parser = argparse.ArgumentParser(
        usage="%(prog)s\n\t./208dowels 0i"
    )
    parser.add_argument(
        "Oi",
        type=int,
        help="0i    size of the observed class",
        nargs=9
    )
    try:
        args = parser.parse_args(None, None)
    except:
        exit(84)
    for elem in args.Oi:
        if (elem < 0):
            exit(84)
    return args