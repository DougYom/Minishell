/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** setenv
*/

#include "minishell.h"

int check_env(char **env, int nb_env, char *str)
{
    int i = 0;

    for (i; env[i]; i++) {
        if (my_strncmp(env[i], str, my_strlen(str)) == 0 &&
        env[i][my_strlen(str)] == '=')
            return i;
    }
    return nb_env;
}

void my_setenv(char **env, char **arg)
{
    int nb_arg = my_tab_len(arg);
    int nb_env = my_tab_len(env);
    int line = 0;
    char *tmp = my_strdup(env[0]);

    if (nb_arg == 1) {
        my_env(env);
    } else if (nb_arg > 3) {
        my_puts("setenv: Too many arguments.\n");
    } else {
        line = check_env(env, nb_env, arg[1]);
        env[line] = malloc(sizeof(char) * my_strlen(arg[1]));
        env[line] = my_strcpy(env[line], arg[1]);
        env[line] = my_strcat(env[line], "=");
            if (nb_arg == 3)
                env[line] = my_strcat(env[line], arg[2]);
        env[nb_env + 1] = NULL;
        env[0] = my_strdup(tmp);
    }
}

void my_env(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_puts(env[i]);
        my_putchar('\n');
    }
}

char **deplace_tab(char **tab, int i)
{
    for (i; tab[i + 1]; i++) {
        tab[i] = malloc(sizeof(char) * my_strlen(tab[i + 1]));
        tab[i] = my_strcpy(tab[i], tab[i + 1]);
    }
    tab[i] = NULL;
    return tab;
}

void my_unsetenv(char **env, char **arg)
{
    int nb_arg = my_tab_len(arg);
    int line = 0;

    if (nb_arg == 1) {
        my_puts("unsetenv: Too few arguments.\n");
        return;
    }
    for (nb_arg; nb_arg > 1; nb_arg--) {
        line = check_env(env, -1, arg[1]);
        if (line != -1) {
            env = deplace_tab(env, line);
        }
    }
}
