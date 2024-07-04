#!/bin/python

import argparse

def checkrange(value):
    """Fonction de vérification personnalisée pour argparse"""
    try:
        fvalue = float(value)
    except ValueError:
        raise argparse.ArgumentTypeError(f"{value} n'est pas un nombre flottant valide")
    if fvalue < 0 or fvalue > 2.5:  # Définir la plage comme [0, 100] par exemple
        raise argparse.ArgumentTypeError(f"La valeur {value} n'est pas dans la plage autorisée [0, 2.5]")
    return fvalue

def get_args():
    parser = argparse.ArgumentParser(
        usage="%(prog)s\n\t./204ducks a"
    )
    parser.add_argument(
        "a",
        type=checkrange,
        help="constant computed from past results",
    )
    try:
        args = parser.parse_args(None, None)
    except:
        exit(84)
    return args

def main():
    args = get_args()

if __name__ == "__main__":
    main()
