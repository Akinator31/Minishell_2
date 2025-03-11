/*
** EPITECH PROJECT, 2025
** my_str_isalpha.c
** File description:
** task11
*/

#include "my_lib.h"

int my_str_isalpha(char const *str)
{
    int i = 0;

    if (my_strlen(str) == 0)
        return 1;
    for (; str[i] > '\0'; i++) {
        if ((str[i] < 'a') || (str[i] > 'z'))
            return 0;
        if ((str[i] < 'A') || (str[i] > 'Z'))
            return 0;
    }
    return 1;
}
