/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** ouais
*/

void my_sort_int_array(int *array, int size)
{
    int temp = 0;
    for (int i = 0; i < size - 1; i = i + 1) {
        if (array[i] > array[i + 1]) {
            temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            i = -1;
        }
    }
}
