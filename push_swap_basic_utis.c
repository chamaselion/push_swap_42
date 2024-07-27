#include "push_swap.h"

char *ft_strchr(const char *s, int c)
{
    while (*s)
    {
        if (*s == (char)c)
        {
            return (char *)s;
        }
        s++;
    }
    if (c == '\0')
    {
        return (char *)s;
    }
    return NULL;
}

char *ft_strtok_r(char *str, const char *delim, char **saveptr)
{
    char *end;

    if (str == NULL)
    {
        str = *saveptr;
    }
    while (*str && strchr(delim, *str))
    {
        str++;
    }

    if (*str == '\0')
    {
        *saveptr = str;
        return NULL;
    }
    end = str;
    while (*end && !strchr(delim, *end))
    {
        end++;
    }

    if (*end == '\0')
    {
        *saveptr = end;
        return str;
    }
    *end = '\0';
    *saveptr = end + 1;
    return str;
}

char *ft_strtok(char *str, const char *delim)
{
    static char *last;
    return ft_strtok_r(str, delim, &last);
}
