from .display import print_usage


def check_args(argv):
    if len(argv) == 2 and argv[1] == "-h":
        print_usage()
        return 0

    if len(argv) == 3:
        try:
            int(argv[1])
            float(argv[2])
        except ValueError:
            return 1
        if int(argv[1]) >= 0 and 1 <= float(argv[2]) <= 4:
            return 0
        return 1
    if len(argv) == 4:
        try:
            int(argv[1])
            int(argv[2])
            int(argv[3])
        except ValueError:
            return 1
        if int(argv[1]) >= 0 and 0 <= float(argv[2]) <= float(argv[3]):
            return 0
        return 1
