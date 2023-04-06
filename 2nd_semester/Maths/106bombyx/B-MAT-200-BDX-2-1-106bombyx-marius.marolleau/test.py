#!/usr/bin/env python3
import argparse

def get_args():
    parser = argparse.ArgumentParser(usage="%(prog)s\n\t./106bombyx n [k | i0 i1]")
    parser.add_argument("n", type=int, help="number of the first genration individuals")
    parser.add_argument("k", type=float, help="growth rate 1 to 4")
    parser.add_argument("i0", type=int, help="initial generation (included)")
    parser.add_argument("i1", type=int, help="final generation (included)")

    try:
        args = parser.parse_args(None, None)
    except SystemExit:
        exit(84)
    return args

def logistic_increment(x_prev, k):
    return k * x_prev * (1000 - x_prev) / 1000


def population(n, k, i0, i1):
    x1 = n
    x_next = x1
    res = []
    res.append([1, k, x1])

    for i in range(1, i1):
        x_next = logistic_increment(x_next, k)
        res.append([i + 1, k, x_next])
    return res[i0:i1 + 1]

def test_k(n, k, i0, i1):
    res = []
    while(k <= 4):
        res += population(n, k, i0, i1)
        k += 0.01
    return res

def with_rate(n, k):
    res = population(n, k, 0, 100)
    for elt in res:
        print(elt[0], elt[2])
    return

def with_borne(n, i0, i1):
    res = test_k(n, 1, i0, i1)
    for elt in res:
        print(elt[1], elt[2])
    return

args = get_args()
if (len(args) == 2):
    print("3")
if (len(args) == 3):
    print("4")


with_rate(10, 3.3)
# with_borne(10, 10000, 10010)
