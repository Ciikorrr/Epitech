/*
** EPITECH PROJECT, 2022
** my_sort_int_array
** File description:
** sort array
*/

void my_put_nbr(int i);

int my_sort_int_array(int *array, int size)
{
    int count = 0;
    for (int i = 0;  size; i += 1) {
        if (array[i] > array[i + 1]) {
            int temp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = temp;
            count += 1;
        }
    }
    return array;
}

int main()
{
    char array[3] = {4, 5, 8};
    my_show_word_array(my_sort_int_array(array, 3));
}