#!/bin/python
import sys

def get_args():
    list = []
    if (len(sys.argv) != 3 and len(sys.argv) != 2):
        exit(84)
    if (len(sys.argv) == 3):
        if (sys.argv[1].isdigit() == False or sys.argv[2].isdigit() == False):
            exit(84)
        if (int(sys.argv[1]) < 0 or int(sys.argv[2]) < 0 or int(sys.argv[2]) > int(sys.argv[1])):
            exit(84)
        list.append(sys.argv[1])
        list.append(sys.argv[2])
        return list
    if (len(sys.argv) == 2):
        if sys.argv[1].isdigit() == False or (int(sys.argv[1]) <= 0):
            exit(84)
        list.append(sys.argv[1])
    return list

def main():
    args = get_args()


if __name__ == "__main__":
    main()
