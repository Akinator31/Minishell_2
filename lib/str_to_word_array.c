/*
** EPITECH PROJECT, 2025
** LIB
** File description:
** str_to_word_array
*/

#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include "my_lib.h"

char **str_to_word_array(const char *string, const char *separators)
{
    size_t len = 0;
    char **result = NULL;
    char *work_string = NULL;
    char *token = NULL;

    if (!string || !separators)
        return NULL;
    work_string = strdup(string);
    token = strtok(work_string, separators);
    result = malloc(sizeof(char *));
    while (token) {
        result = realloc(result, sizeof(char *) * (len + 1));
        result[len] = strdup(token);
        token = strtok(NULL, separators);
        len++;
    }
    result = realloc(result, sizeof(char *) * (len + 1));
    result[len] = NULL;
    free(work_string);
    return result;
}
