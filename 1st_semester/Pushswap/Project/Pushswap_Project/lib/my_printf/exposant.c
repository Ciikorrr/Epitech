/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** expsoant
*/

int my_put_float_nbr(double n, int precision, int count);
int my_put_nbr(int nb);
int my_putstr(char const *str);

int positiveexp(double n, int count)
{
    int decalage = 0;
    while (n > 10) {
        n = n / 10;
        decalage += 1;
    }
    count += my_put_float_nbr(n, decalage, count);
    if (decalage >= 10) {
        my_putstr("e+");
        count += 2;
        count += my_put_nbr(decalage);
    } else {
        my_putstr("e+0");
        count += 3;
        count += my_put_nbr(decalage);
    }
    return count;
}

int negativeexp(double n, int count)
{
    int decalage = 0;
    while (n < 1) {
            n = n * 10;
            decalage += 1;
    }
    count += my_put_float_nbr(n, decalage, count);
    if (decalage >= 10) {
        my_putstr("e-");
        count += 2;
        count += my_put_nbr(decalage);
    } else {
        my_putstr("e-0");
        count += 3;
        count += my_put_nbr(decalage);
    }
    return count;
}
