/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** Main
*/

#include "minishell.h"

void my_puts(const char *str)
{
    write(1, str, my_strlen(str));
}

void own_command(char **tab, char **env)
{
    pid_t child = fork();
    int status;

    if (child == -1)
        exit(84);
    if (child == 0) {
        execve(tab[0], tab, env);
        my_printf("%s: Command not found.\n", tab[0]);
        exit(0);
    } else
        wait(&status);
    if (status == 139)
        my_puts("Segmentation fault\n");
}

void put_command(char **path, char **tab, char **env, int i)
{
    pid_t child = fork();
    int status;

    if (child == 0) {
        execve(path[i], tab, env);
        exit(0);
    } else
        wait(&status);
}

void spawnchild(char **tab, char **env)
{
    pid_t child;
    char **path = my_str_to_word_array(get_line_env(env, "PATH="), ':');

    for (int i = 0; path[i]; i++) {
        path[i] = my_strcat(path[i], "/");
        path[i] = my_strcat(path[i], tab[0]);
        if (open(path[i], O_RDONLY) != -1) {
            put_command(path, tab, env, i);
            return;
        }
    }
    own_command(tab, env);
}

int main(int ac, char **av, char **real_env)
{
    char *s = NULL;
    char **tab = NULL;
    char **env = copy_tab(real_env);

    if (ac == 1) {
        while (s = get_input(env)) {
            tab = my_str_to_word_array(s, ' ');
            get_command(tab, env);
        }
        return EXIT_SUCCESS;
    } else
        EXIT_ERROR;
}
