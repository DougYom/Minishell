/*
** EPITECH PROJECT, 2022
** minishell
** File description:
** read command
*/

#include "minishell.h"

char *my_realloc2(char *ptr, unsigned int size)
{
    char *new_ptr = my_strconfigure(size);
    int ch = 0;

    if (ptr == NULL || size < 1 || !new_ptr)
        return (NULL);
    while (((ssize_t)ch) != size && ptr[ch] != '\0') {
        new_ptr[ch] = ptr[ch];
        ch++;
    }
    if (ptr[ch])
        while (((ssize_t)ch) < size)
            new_ptr[ch++] = 0;
    new_ptr[ch] = 0;
    free(ptr);
    return (new_ptr);
}

char *return_freed(char *ptr, char *ret)
{
    if (ptr != NULL)
        free(ptr);
    return (ret);
}

char *my_strconfigure(unsigned int size)
{
    char *ptr;
    unsigned int i = 0;

    if (!size)
        return (NULL);
    ptr = malloc(sizeof(char) * (size + 1));
    if (ptr == NULL)
        return (NULL);
    while (i < size + 1)
        *(ptr + i++) = 0;
    return (ptr);
}

int test_command(char *str)
{
    char **command = my_str_to_word_array(str, ' ');

    if (my_strcmp(command[0], "exit") == 0)
        my_exit();
}

void my_exit(void)
{
    my_puts("exit\n");
    exit(0);
}
