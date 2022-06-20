/*
** EPITECH PROJECT, 2022
** my_sh
** File description:
** command
*/

#include "minishell.h"

char *get_line_env(char **env, char *str)
{
    char *home = NULL;
    int i = 0;
    int j = 0;

    for (i; my_strncmp(env[i], str, my_strlen(str)) != 0; i++);
    home = malloc(sizeof(char) * my_strlen(env[i]));
    for (int x = my_strlen(str); env[i][x]; x++) {
        home[j] = env[i][x];
        j++;
    }
    return home;
}

int change_dir(char *file, int nb_arg, char **env)
{
    if (nb_arg >= 3) {
        my_puts("cd: Too many arguments.\n");
        return 0;
    }
    if (file != NULL) {
        if (chdir(file) == -1) {
            perror(file);
            return 0;
        }
    } else {
        chdir(get_line_env(env, "HOME="));
    }
    return 1;
}

void my_cd(char **command, char **env)
{
    char *pwd = malloc(sizeof(char) * 256);
    char **arg = malloc(sizeof(char *) * 3);
    int nb_arg = my_tab_len(command);

    if (change_dir(command[1], nb_arg, env) == 0)
        return;
    pwd = getcwd(pwd, 256);
    arg[0] = "setenv";
    arg[1] = "PWD";
    arg[2] = malloc(sizeof(char) * my_strlen(pwd) + 1);
    arg[2] = my_strcpy(arg[2], pwd);
    arg[3] = NULL;
    my_setenv(env, arg);
}

char **get_command(char **command, char **env)
{
    int x = 0;

    if (my_strcmp(command[0], "cd") == 0) {
        my_cd(command, env);
        x++;
    }
    if (my_strcmp(command[0], "env") == 0) {
        my_env(env);
        x++;
    }
    if (my_strcmp(command[0], "setenv") == 0) {
        my_setenv(env, command);
        x++;
    }
    if (my_strcmp(command[0], "unsetenv") == 0) {
        my_unsetenv(env, command);
        x++;
    }
    if (x == 0)
        spawnchild(command, env);
}
