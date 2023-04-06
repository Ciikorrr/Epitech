from trigo.matrix_functions import *

def cos(A):
    res = get_identite(A)
    i = 1
    to_add = res
    while not(-0.0001 < get_precision_matrix(to_add) < 0.0001):
        to_add = mul_matrix(mul_matrix(power_matrix(A, 2*i), (-1)**i), 1 / factoriel(2*i))
        res = sum_matrix(res, to_add)
        i += 1
    return res

def cosh(A):
    res = get_identite(A)
    i = 1
    to_add = res
    while not(-0.0001 < get_precision_matrix(to_add) < 0.0001):
        to_add = mul_matrix(power_matrix(A, 2*i), 1 / factoriel(2*i))
        res = sum_matrix(res, to_add)
        i += 1
    return res

def sin(A):
    res = A
    i = 1
    to_add = res
    while not(-0.0001 < get_precision_matrix(to_add) < 0.0001):
        to_add = mul_matrix(mul_matrix(power_matrix(A, 2 * i + 1), 1 / factoriel(2 * i + 1)), (-1)**i)
        res = sum_matrix(res, to_add)
        i += 1
    return res

def sinh(A):
    res = A
    i = 1
    to_add = res
    while not(-0.0001 < get_precision_matrix(to_add) < 0.0001):
        to_add = mul_matrix(power_matrix(A, 2 * i + 1), 1 / factoriel(2 * i + 1))
        res = sum_matrix(res, to_add)
        i += 1
    return res

def exponentiel(A):
    res = get_identite(A)
    i = 1
    matrix_powered = get_identite(A)
    denominateur = i
    to_add = res
    while (get_precision_matrix(to_add) > 0.0001):
        matrix_powered = product_matrix(matrix_powered, A)
        denominateur = denominateur * i
        to_add = mul_matrix(matrix_powered, 1 / denominateur)
        res = sum_matrix(res, to_add)
        i += 1
    return res

def factoriel(nb):
    res = 1
    for i in range(1, nb + 1):
        res *= i
    return res