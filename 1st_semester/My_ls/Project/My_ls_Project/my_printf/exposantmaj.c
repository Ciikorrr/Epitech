/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** expsoantmaj
*/

int my_put_float_nbr(double n, int precision, int count);
int my_put_nbr(int nb);
int my_putstr(char const *str);

int positiveexpm(double n, int count)
{
    int cpt = 0;
    while (n > 10) {
        n = n / 10;
        cpt += 1;
    }
    count += my_put_float_nbr(n, cpt, count);
    if (cpt >= 10) {
        my_putstr("E+");
        count += 2;
        count += my_put_nbr(cpt);
    } else {
        my_putstr("E+0");
        count += 3;
        count += my_put_nbr(cpt);
    }
    return count;
}

int negativeexpm(double n, int count)
{
    int cpt = 0;
    while (n < 1) {
            n = n * 10;
            cpt += 1;
    }
    count += my_put_float_nbr(n, cpt, count);
    if (cpt >= 10) {
        my_putstr("E-");
        count += 2;
        count += my_put_nbr(cpt);
    } else {
        my_putstr("E-0");
        count += 3;
        count += my_put_nbr(cpt);
    }
    return count;
}
