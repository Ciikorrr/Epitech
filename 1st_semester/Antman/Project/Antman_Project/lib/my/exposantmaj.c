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
    int cmp = 0;
    while (n > 10) {
        n = n / 10;
        cmp += 1;
    }
    count += my_put_float_nbr(n, cmp, count);
    if (cmp >= 10) {
        my_putstr("E+");
        count += 2;
        count += my_put_nbr(cmp);
    } else {
        my_putstr("E+0");
        count += 3;
        count += my_put_nbr(cmp);
    }
    return count;
}

int negativeexpm(double n, int count)
{
    int cmp = 0;
    while (n < 1) {
            n = n * 10;
            cmp += 1;
    }
    count += my_put_float_nbr(n, cmp, count);
    if (cmp >= 10) {
        my_putstr("E-");
        count += 2;
        count += my_put_nbr(cmp);
    } else {
        my_putstr("E-0");
        count += 3;
        count += my_put_nbr(cmp);
    }
    return count;
}
