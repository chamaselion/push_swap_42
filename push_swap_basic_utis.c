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

int ft_atoi(const char *str)
{
    int result;
    int sign;

	result = 0;
	sign = 1;
    while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
    {
        str++;
    }
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
        {
            sign = -1;
        }
        str++;
    }
    while (*str >= '0' && *str <= '9')
    {
        result = result * 10 + (*str - '0');
        str++;
    }
    return result * sign;
}

int	ft_strlen(char *str)
{
	int c;
	
	c = 0;
	while (str[c] != '\0')
	{
		c++;
	}
	return (c);
}