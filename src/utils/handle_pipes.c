/*
** EPITECH PROJECT, 2025
** B-PSU-200-TLS-2-1-minishell2-pavel.de-wavrechin
** File description:
** handle_pipes
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <stdio.h>
#include "commands.h"
#include "my_lib.h"
#include "utils.h"

static void execute_pipe(char ***envp, char **commands, int *error_code)
{
    int pipefd[2];
    pid_t pid;
    int fd_in = 0;

    for (int i = 0; commands[i] != NULL; i++) {
        pid = fork();
        pipe(pipefd);
        if (pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            dup2(fd_in, 0);
            if (commands[i + 1] != NULL)
                dup2(pipefd[1], 1);
            close(pipefd[0]);
            analyse_command(envp, commands[i], error_code);
            exit(EXIT_FAILURE);
        } else {
            wait(NULL);
            close(pipefd[1]);
            fd_in = pipefd[0];
        }
    }
}

int handle_pipes(char *command, char ***envp, int *error_code)
{
    char **commands = NULL;

    if (my_strstr(command, "|")) {
        commands = my_str_to_word_array(command, "|");
        execute_pipe(envp, commands, error_code);
        free_2d_array_of_char(commands);
        return 1;
    }
    return 0;
}
