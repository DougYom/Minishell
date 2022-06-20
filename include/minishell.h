/*
** EPITECH PROJECT, 2021
** Include
** File description:
** Include
*/

#ifndef MINISHELL

    #define MINISHELL
    #define EXIT_ERROR 84

    #include "my_printf.h"
    #include "my.h"
    #include <stdlib.h>
    #include <unistd.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <signal.h>
    #include <string.h>
    #include <errno.h>

    char *my_realloc2(char *ptr, unsigned int size);
    char *return_freed(char *ptr, char *ret);
    char *my_strconfigure(unsigned int size);
    char *get_input(char **env);
    void my_exit(void);
    int test_command(char *str);
    char **get_command(char **command, char **env);
    void my_puts(const char *str);
    char **copy_tab(char **tab);
    int my_tab_len(char **tab);
    void my_setenv(char **env, char **arg);
    void my_env(char **env);
    void my_unsetenv(char **env, char **arg);
    char *get_line_env(char **env, char *str);
    void spawnchild(char **tab, char **env);

#endif
