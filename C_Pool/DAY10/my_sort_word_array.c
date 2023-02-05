/*
** EPITECH PROJECT, 2022
** my_sort_word_array
** File description:
** prog
*/

int my_sizetab(char **array)
{
    int size = 0;
    while (array[i] != 0) {
        i += 1;
    }
    return size;
}

int my_sort_word_array(char **array)
{
    int size = my_sizetab(array);
    for (int i = 0; i < size - 1; i += 1) {
        if (my_strcmp(array[i], array[i + 1]) == -1) {
            char *mem = array[i];
            array[i] = array[i + 1];
            array[i + 1] = mem;
            i = -1;
        }
    }
    return 0;
}
