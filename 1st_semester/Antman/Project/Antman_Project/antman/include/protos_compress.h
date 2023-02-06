/*
** EPITECH PROJECT, 2022
** B-CPE-110-BDX-1-1-BSQ-marius.marolleau
** File description:
** protos
*/
#include "antman_struct.h"

#ifndef PROTOS_COMPRESS_H_
    #define PROTOS_COMPRESS_H_

    char *file_to_str(char const *filepath);
    int compress_image(char *str);
    int do_antman(int argc, char **argv);
    int my_strlen(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    int compress_html(void);
    int choice_compress(int argc, char **argv);
    int compress_file(int argc, char **argv);
    int error_handling(int argc, char **argv);
    int check_image(char *str);
    int check_html(char *str);
    int check_texte(char *str);
    int do_antman(int argc, char **argv);
    int huffman_compression_main(char *file_content);
#endif /* PROTOS_COMPRESS_H_ */
