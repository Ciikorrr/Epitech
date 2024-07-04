#!/bin/python

import sys

def get_args():
    try:
        list = []
        if (len(sys.argv) > 5 or len(sys.argv) < 3):
            exit(84)

        if (float(sys.argv[1]) <= 0 or float(sys.argv[1]) > 200 or float(sys.argv[2]) <= 0):
            exit(84)
        list.append(float(sys.argv[1]))
        list.append(float(sys.argv[2]))
        if (len(sys.argv) == 3):
            return list
        if (float(sys.argv[3]) > 200 or float(sys.argv[3]) < 0):
            exit(84)
        list.append(float(sys.argv[3]))
        if (len(sys.argv) == 4):
            return list
        if (float(sys.argv[4]) > 200 or float(sys.argv[4]) < 0 or float(sys.argv[3]) > float(sys.argv[4])):
            exit(84)
        list.append(float(sys.argv[4]))
        return list
    except ValueError:
            exit(84)
