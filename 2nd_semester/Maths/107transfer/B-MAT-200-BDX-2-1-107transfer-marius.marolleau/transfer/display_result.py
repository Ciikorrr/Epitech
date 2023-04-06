from .calcul_polynome import res_transfert

# print the result of the funcion for all x value from 0 to 1
def get_all_result(numerateur, denominateur):
    x = 0

    for i in range(1001):
        print(f"{x:.3f} -> {res_transfert(numerateur, denominateur, x):.5f}")
        x += 0.001
    return