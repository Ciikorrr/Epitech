#!/bin/python

def display(args, variance, interval_1, interval_2):
    print(f"Population size:\t {args.pSize}")
    print(f"Sample size:\t\t {args.sSize}")
    print(f"Voting intention:\t {args.p:.2f}%")
    print(f"Variance:\t\t {variance:.6f}")
    print(f"95% confidence interval: [{interval_1[0]:.2f}%; {interval_1[1]:.2f}%]")
    print(f"99% confidence interval: [{interval_2[0]:.2f}%; {interval_2[1]:.2f}%]")
