import sys
from math import sqrt
from trigo.calcul_functions import *

def product_matrix(A,B):
    C = [[0]*len(B[0]) for i in range(len(A))]

    for i in range(len(A)):
        for j in range(len(B[0])):
            for k in range(len((B))):
                C[i][j] += A[i][k] * B[k][j]
    return C

def power_matrix(A, pow):
    res = A
    for i in range(pow - 1):
        res = product_matrix(A, res)
    return res

def print_matrix(A, padding=6):
    string = '\n'.join('\t'.join(f'{elt:.2f}' for elt in line) for line in A)
    print(string)
    return string

def get_identite(A):
    res = []
    for i in range (len(A)):
        res.append([0 for j in range(len(A))])
    for i in range(len(res)):
        res[i][i] = 1
    return res

def sum_matrix(A, B):
    res = [[0 for i in range(len(A[0]))] for i in range(len(A))]
    for i in range(len(A)):
        for j in range(len(A[0])):
            res[i][j] = A[i][j] + B[i][j]
    return res

def mul_matrix(A, nb):
    B = [[A[i][j] * nb for j in range (len(A[0]))] for i in range(len(A))]
    return B

def get_precision_matrix(A):
    max = A[0][0]
    for i in range(len(A)):
        for j in range(len(A[0])):
            if A[i][j] > max:
                max = A[i][j]
    return max

def create_matrix(args):
    a = int(sqrt(len(sys.argv) - 2))
    index = 0
    matrix = [[0 for i in range(a)] for i in range(a)]
    for i in range(len(matrix)):
        for j in range(len(matrix[0])):
            matrix[i][j] = args.ai[index]
            index += 1
    return matrix
