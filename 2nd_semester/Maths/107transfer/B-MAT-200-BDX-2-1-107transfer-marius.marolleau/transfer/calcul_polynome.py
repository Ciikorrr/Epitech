# made the product of two polynome,
def produit_polynome(list_coef1, list_coef2):
    list = []

    for i in range(len(list_coef1) + len(list_coef2) - 1): # from 0 to coef max ( res_max = max1 + max2)
        list.append(get_all_monome_sums(list_coef1, list_coef2, i))
    return list

# get the result of the trasnsfert operation with x
def res_transfert(numerateur, denominateur, x):
    return polynomial(numerateur, x) / polynomial(denominateur, x)

# get the result of a spesific polynome with x
def polynomial(list_coef, x):
    res = 0
    for i, coef in enumerate(list_coef):
        res += coef * x**i
    return res

# for two polynome list, add the coefficient of all the pair with the good value
def get_all_monome_sums(list_coef1, list_coef2, value):
    res = 0

    for i in range(len(list_coef1)):       #for all the elt in first list
        for j in range(len(list_coef2)):   #try the sum with all elt of the other list
            if (i + j == value):           # if it is equal to searched value, coefficient are multiplied and add to result
                res += list_coef1[i] * list_coef2[j]
    return res