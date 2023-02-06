/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-BSQ-marius.marolleau
** File description:
** macros
*/

#ifndef MACROS_H_
    #define MACROS_H_

typedef enum error_e {
    SUCCESS_EPITECH = 0,
    ERROR_EPITECH = 84,
} error_t;


        #define CHECK_HTML check_html(argv[1]) == SUCCESS_EPITECH
        #define CHECK_IMAGE check_image(argv[1]) == SUCCESS_EPITECH
        #define CHECK_TEXTE check_texte(argv[1]) == SUCCESS_EPITECH

#endif /* !MACROS_H_ */
