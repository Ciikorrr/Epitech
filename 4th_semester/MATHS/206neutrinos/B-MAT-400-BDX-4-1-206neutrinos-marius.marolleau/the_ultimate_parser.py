#!/bin/python
import argparse

def get_args():
    parser = argparse.ArgumentParser(
        usage="%(prog)s\n\t./206neutrios n a h sd"
    )
    parser.add_argument(
        "n",
        type=int,
        help="number of values",
    )
    parser.add_argument(
        "a",
        type=int,
        help="arithmetic mean",
    )
    parser.add_argument(
        "h",
        type=int,
        help="harmonic mean",
    )
    parser.add_argument(
        "sd",
        type=int,
        help="standard deviation",
    )
    try:
        args = parser.parse_args(None, None)
    except:
        exit(84)
    if (args.n < 0 or args.a < 0 or args.h < 0 or args.sd < 0):
        exit(84)
    return args

def main2():
    args = get_args()

if __name__ == "__main__":
    main2()
