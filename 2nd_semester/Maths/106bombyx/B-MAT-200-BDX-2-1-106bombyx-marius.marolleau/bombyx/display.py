from .calcul import *


def print_usage():
    print(
        "USAGE\n",
        "\t./106bombyx n [k | i0 i1]\n\n"
        "DESCRIPTION\n"
        "\tn\tnumber of first generation individuals\n"
        "\tk\tgrowth rate from 1 to 4\n"
        "\ti0\tinitial generation (included)\n"
        "\ti1\tfinal generation (included)",
    )
    return


def with_rate(n, k):
    x1 = n
    print(f"{1} {x1:.2f}")
    for i in range(1, 100):
        x1 = logistic_increment(x1, k)
        print(f"{i + 1} {x1:.2f}")
    return
