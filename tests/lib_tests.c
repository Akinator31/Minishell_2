/*
** EPITECH PROJECT, 2025
** B-PSU-200-TLS-2-1-minishell1-pavel.de-wavrechin
** File description:
** lib_tests
*/

#include <criterion/criterion.h>
#include "my_lib.h"

Test(my_strcmp, basic_my_strcmpt_test)
{
    cr_assert_eq(my_strcmp("super_string", "super_string"), 0);
}

Test(test_free_2d, test_basic)
{
    char **word_array = my_str_to_word_array("ceci est un test", " ");
    free_2d_array_of_char(word_array);
    word_array = NULL;
    cr_assert_null(word_array);
}

Test(get_2d_arr_len, basic_test_get_2d_arr_len)
{
    char *string = "bonjour";
    char **string_element = my_str_to_word_array(string, " ");

    cr_assert_eq(get_2d_arr_len(string_element), 1);
    free_2d_array_of_char(string_element);
}

Test(my_isalpha, basic_test_myisalpha)
{
    char test = 'A';
    char test2 = 'a';
    char test3 = '1';
    char test4 = '\\';

    cr_assert_eq(my_isalpha(test), 1);
    cr_assert_eq(my_isalpha(test2), 1);
    cr_assert_eq(my_isalpha(test3), 1);
    cr_assert_eq(my_isalpha(test4), 0);
}

Test(my_memset, basic_test_my_memset)
{
    char *string = malloc(sizeof(char) * 20);

    my_memset(string, 0, 20);
    string[20] = '\0';
    for (int i = 0; string[i] != '\0'; i++)
        cr_assert_eq(string[i], 0);
    free(string);
}

Test(my_str_isalpha, basic_test_my_str_is_alpha)
{
    char *string = "BONJOUR";
    char *string2 = "";
    char *string3 = "122344566";

    cr_assert_eq(my_str_isalpha(string), 0);
    cr_assert_eq(my_str_isalpha(string2), 1);
    cr_assert_eq(my_str_isalpha(string3), 0);
}
