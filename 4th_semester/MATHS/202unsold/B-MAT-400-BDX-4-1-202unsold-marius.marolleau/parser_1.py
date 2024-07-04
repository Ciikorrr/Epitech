import argparse

def get_args():
    parser = argparse.ArgumentParser(
        usage="%(prog)s\n\t./202unsold a b"
    )
    parser.add_argument(
        "a",
        type=int,
        help="constant computed from past results",
    )
    parser.add_argument(
        "b",
        type=int,
        help="constant computed from past results",
    )
    try:
        args = parser.parse_args(None, None)
    except:
        exit(84)
    if (args.a <= 50 or args.b <= 50):
        exit(84)
    return args

def main():
    args = get_args()

if __name__ == "__main__":
    main()
