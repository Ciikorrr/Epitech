#!/bin/python
import argparse

def get_args():
    parser = argparse.ArgumentParser(
        usage="%(prog)s\n\t./209poll pSize sSize p"
    )
    parser.add_argument(
        "pSize",
        type=int,
        help="pSize     size of the population",
    )
    parser.add_argument(
        "sSize",
        type=int,
        help="sSize     size of the sample (supposedto be representative)",
    )
    parser.add_argument(
        "p",
        type=float,
        help="p     pourcentage of voting intention for a specific candidate",
    )
    try:
        args = parser.parse_args(None, None)
    except:
        exit(84)
    if (args.p < 0 or args.p > 100 or args.pSize < 0 or args.sSize < 0 or args.sSize > args.pSize):
        exit(84)
    return args
