/*
** EPITECH PROJECT, 2022
** rush
** File description:
** rush
*/

int my_strlen(char *str);
void my_putchar(char c);
int my_put_nbr(int nb);

int count_char(char *str)
{
    int res = my_strlen(str);

    for (int i = 0; str[i] != '\0'; i += 1) {
        if (str[i] < 'A' || (str[i] > 'Z' && str[i] < 'a') || str[i] > 'z') {
            res -= 1;
        }
    }
    return res;
}

int display_pourcent(int nb)
{
    my_put_nbr(nb / 100);
    my_putchar('.');
    my_put_nbr((nb / 10) % 10);
    my_put_nbr(nb % 10);
    return (0);
}

void display(char letter, char letter_rev, char *str)
{
    int nbr = 0;
    for (int j = 0; str[j] != '\0'; j += 1) {
        if (str[j] == letter || str[j] == letter_rev) {
            nbr += 1;
        }
    }
    my_putchar(letter);
    my_putchar(':');
    my_put_nbr(nbr);
    my_putchar('(');
    display_pourcent(10000 * nbr / count_char(str));
    my_putchar('%');
    my_putchar(')');
    my_putchar('\n');
    nbr = 0;
}

int  main(int ac, char **av)
{
    char *str = av[1];
    char letter_rev;
    int i = 0;
    for (i = 0; i < ac - 2; i += 1) {
        if (av[i + 2][0] < 'A' || av[i + 1][0] > 'Z'
            && av[i + 2][0] < 'a' || av[i + 2][0] > 'z') {
            return 84;
        }
        if (av[i + 2][0] > 'a' && av[i + 2][0] < 'z') {
            letter_rev = av[i + 2][0] - 32;
        }
        if (av[i + 2][0] > 'A' && av[i + 2][0] < 'Z') {
            letter_rev = av[i + 2][0] + 32;
        }
        display(av[i + 2][0], letter_rev, str);
    }
    return 0;
}
