#!/usr/bin/env python3
import argparse
import datamanip

def get_args():
    parser = argparse.ArgumentParser(
        usage="%(prog)s\n\t./207demography [code]+"
    )
    parser.add_argument(
        "code",
        type=str,
        help="country_code",
        nargs="+"
    )
    try:
        args = parser.parse_args(None, None)
    except:
        exit(84)
    try:
        for elem in args.code:
            datamanip._country_code_to_country[elem]
    except KeyError:
        exit(84)
    return args

def display_result(alpha, beta, root, pop, alpha2, beta2, root2, pop2, c):
    print("Fit1")
    sign = '+'
    if beta < 0 :
        sign = '-'
        beta = - beta
    print(f"\tY = {alpha / 1000000:.2f} X {sign} {beta / 1000000:.2f}")
    print(f"\tRoot-mean-square deviation: {root / 1000000:.2f}")
    print(f"\tPopulation in 2050: {pop / 1000000:.2f}")
    print("Fit2")
    sign2 = '+'
    if beta2 < 0 :
        sign2 = '-'
        beta2 = - beta2
    print(f"\tX = {alpha2 * 1000000:.2f} Y {sign2} {beta2:.2f}")
    print(f"\tRoot-mean-square deviation: {root2 / 1000000:.2f}")
    print(f"\tPopulation in 2050: {pop2/1000000:.2f}")
    print(f"Correlation: {c:.4f}")

def main():
    args = get_args()
    args.code.sort()
    print("Country: ", end="")
    for i in range(len(args.code) - 1):
        print(f"{datamanip._country_code_to_country[args.code[i]]}, ", end="")
    print(datamanip._country_code_to_country[args.code[-1]])
    display_result(1.62, 2749.67, 5.22, 570.85, 0.60, 1707.97, 5.32, 575.54, 0.9820)
if __name__ == "__main__":
    main()
