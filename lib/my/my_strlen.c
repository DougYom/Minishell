/*
** EPITECH PROJECT, 2021
** my_strlen
** File description:
** counts and returns the number of characters found in the string
*/

int my_putchar(char c);

int my_strlen(char const *str)
{
    int count = 0;

    while (str[count] != '\0') {
        count += 1;
    }
    return count;
}
