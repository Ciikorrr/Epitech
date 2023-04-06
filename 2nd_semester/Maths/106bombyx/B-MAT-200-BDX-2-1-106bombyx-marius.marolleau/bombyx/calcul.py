from .display import *


def logistic_increment(x, k):
    x = k * x * ((1000 - x) / 1000)
    if x < 0:
        x = 0
    return x


def population(n, k, i0, i1):
    x1 = n
    for i in range(0, i0 - 2):
        x1 = k * x1 * ((1000 - x1) / 1000)
    for i in range(i0, i1 + 1):
        x1 = k * x1 * ((1000 - x1) / 1000)
        if x1 < 0:
            x1 = 0
        print(f"{k:.2f} {x1:.2f}")
    return


def test_k(n, k, i0, i1):
    res = []
    while k <= 4:
        population(n, k, i0, i1)
        k += 0.01
    return


def with_borne(n, i0, i1):
    test_k(n, 1, i0, i1)
    return
