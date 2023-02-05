/*
** EPITECH PROJECT, 2022
** do-op
** File description:
** make a calcul
*/

void my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int my_getnbr(char const *str);

int my_get_ope(char *ope)
{
    int a = 0;
    if (ope[0] == '+') {
        a = 1;
    }
    if (ope[0] == '-') {
        a = 2;
    }
    if (ope[0] == '*') {
        a = 3;
    }
    if (ope[0] == '/') {
        a = 4;
    }
    if (ope[0] == '%') {
        a = 5;
    }
    return a;
}

int my_calcul(int a, int num1, int num2)
{
    int res = 0;
    if (a == 1) {
        res = num1 + num2;
    }
    if (a == 2)	{
        res = num1 - num2;
    }
    if (a == 3)	{
        res = num1 * num2;
    }
    if (a == 4)	{
        res = num1 / num2;
    }
    if (a == 5)	{
        res = num1 % num2;
    }
    return res;
}

int do_op(int ac, char **av)
{
    if (ac >= 4) {
        int num1 = my_getnbr(av[1]);
        char op = my_get_ope(av[2]);
        int num2 = my_getnbr(av[3]);
        if (op == 4 && num2 == 0) {
            my_putstr("Stop : division by zero");
            return 0;
        }
        if (op == 5 && num2 == 0) {
            my_putstr("Stop : modulo by zero");
            return 0;
        }
        return my_calcul(op, num1, num2);
    }
    return 84;
}
