/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/
void my_swap(int *a, int *b);

void need_swap(int **nbr1, int **nbr2)
{
    int *tmp = 0;

    if (*nbr1 > *nbr2){
        tmp = *nbr2;
        *nbr2 = *nbr1;
        *nbr1 = tmp;
    }
}

int **my_sort_int_array(int **array, int size)
{
    for (int i = 0; i < size; i += 1){
		for (int j = 0; j < size; j += 1){
            need_swap(&array[j], &array[i]);
		}
	}
    return array;
}
