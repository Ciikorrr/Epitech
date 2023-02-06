/*
** EPITECH PROJECT, 2022
** B-CPE-101-BDX-1-1-myprintf-theophile.combes
** File description:
** struct_flag
*/


#ifndef STRUCT_FLAG_H_
    #define STRUCT_FLAG_H_

        #include "my.h"

typedef struct tab_flag {
    char flag;
    int (*function)(va_list list, int count, attributes_t);
}flags_t;

flags_t tab_flag[] = {
{'i', &flag_id},
{'d', &flag_id},
{'s', &flag_s},
{'c', &flag_c},
{'o', &flag_o},
{'x', &flag_x},
{'X', &flag_xx},
{'f', &flag_f},
{'n', &flag_n},
{'%', &flag_per},
{'p', &flag_p},
{'e', &flag_e},
{'E', &flag_ee},
{'F', &flag_ff},
{'b', &flag_b},
{'u', &flag_u}
};
    #define TAB_SIZE 16

#endif /* !STRUCT_FLAG_H_ */
