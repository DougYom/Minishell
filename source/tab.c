/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** tab
*/

#include "minishell.h"

int my_tab_len(char **tab)
{
    int i = 0;

    for (i; tab[i] != NULL; i++);
    return i;
}

char **copy_tab(char **tab)
{
    char **new_tab = malloc(sizeof(char *) * my_tab_len(tab));
    int i = 0;

    for (i = 0; tab[i]; i++) {
        new_tab[i] = malloc(sizeof(char) * my_strlen(tab[i]) + 1);
        new_tab[i] = my_strcpy(new_tab[i], tab[i]);
    }
    new_tab[i] = NULL;
    return new_tab;
}
