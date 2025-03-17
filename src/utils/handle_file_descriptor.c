/*
** EPITECH PROJECT, 2025
** B-PSU-200-TLS-2-1-minishell2-pavel.de-wavrechin
** File description:
** duplicate_file_descriptor
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "utils.h"

int duplicate_file_descriptor(int fd)
{
    int fd_copy = dup(fd);

    if (fd_copy == -1) {
        perror("dup");
        exit(EXIT_FAILURE);
    }
    return fd_copy;
}

void restore_stdin_stdout_fd(int stdin_cpy, int stdout_cpy)
{
    if (dup2(stdin_cpy, STDIN_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    close(stdin_cpy);
    if (dup2(stdout_cpy, STDOUT_FILENO) == -1) {
        perror("dup2");
        exit(EXIT_FAILURE);
    }
    close(stdout_cpy);
}
