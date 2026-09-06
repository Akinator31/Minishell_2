# Minishell2

UNIX command interpreter written in C, developed as part of the Epitech curriculum. This project extends [Minishell1](https://github.com/Akinator31/Minishell_1) by adding support for semicolons, pipes, and redirections.

## Description

Minishell2 (binary `mysh`) builds on Minishell1 and adds the ability to chain and combine several commands on a single line. A command line can now contain command sequences, pipelines, and input or output redirections.

## Features

- All Minishell1 features (builtins, resolution via `PATH`, environment handling, exit code, dynamic prompt)
- Chaining several commands on a single line with `;`
- Chaining commands through pipes `|`
- Standard output redirection with `>` (overwrite) and `>>` (append)
- Standard input redirection with `<`
- Error handling on standard error, with exit code 84 on internal errors

## Processing priority

A command line is parsed in the following order:

1. Splitting and sequential execution of commands separated by `;`
2. Applying redirections (`>>`, then `>`, then `<`)
3. Splitting and execution of commands separated by pipes `|`
4. Looking up a builtin, then executing an external binary if no builtin matches

## Builtins

| Command | Description |
|---|---|
| `cd [directory]` | Changes the current directory. Without argument, moves to `HOME`. Also supports `~` and `-` |
| `env` | Prints the current environment variables, no argument |
| `setenv [name] [value]` | Creates or updates an environment variable |
| `unsetenv name` | Removes an environment variable (the `*` wildcard is not supported) |
| `exit` | Exits the shell |

## Compilation

The project is built with `make`, using a Makefile that provides the following rules:

```bash
make            # builds the mysh binary
make debug      # builds a debug version with AddressSanitizer
make tests_run  # builds and runs the unit tests (Criterion)
make show_test  # runs the tests and generates an HTML coverage report
make clean      # removes object files
make fclean     # removes object files, binaries and generated reports
make re         # fclean then full rebuild
```

## Usage

Interactive mode:

```bash
./mysh
$> ls -l; ls -l | wc -l
```

Non-interactive mode:

```bash
echo "mkdir test ; cd test ; ls -a ; ls | cat | wc -c > tutu ; cat tutu" | ./mysh
```

The shell exits with `exit`, or with `EOF` (Ctrl+D) in interactive mode.

## Exit codes

The shell returns the exit code of the last executed command. When there is no error, the exit code is 0. On an internal error (command not found, invalid argument, builtin error, empty command around a pipe), the exit code is 84.

## Project structure

```
.
├── include/        project headers
├── lib/            reimplemented basic utility functions
├── src/
│   ├── commands/   builtins and execution of external commands
│   ├── utils/      command parsing, pipe, redirection and semicolon
│   │               handling, environment handling, prompt...
│   └── main.c      program entry point
├── tests/          unit tests (Criterion)
└── Makefile
```

## Project constraints

As required by the Epitech subject, this project requires a functional Minishell1 to execute binaries. Only the following functions are allowed: `malloc`, `free`, `exit`, `opendir`, `readdir`, `closedir`, `getcwd`, `chdir`, `fork`, `stat`, `lstat`, `fstat`, `open`, `close`, `getline`, `strtok`, `strtok_r`, `read`, `write`, `execve`, `access`, `isatty`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `kill`, `getpid`, `strerror`, `perror`, `strsignal`, `pipe`, `dup`, `dup2`.

Standard error redirections (for example `2>&1`) are not handled in this project.

## Tests

Unit tests are written with Criterion and located in the `tests/` directory. They can be run with `make tests_run`, and a coverage report can be generated with `make show_test`.
