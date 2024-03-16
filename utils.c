/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: uxmancis <uxmancis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:46:25 by uxmancis          #+#    #+#             */
/*   Updated: 2024/03/16 16:39:59 by uxmancis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_strlen(char *str)
{
    int len;

    len = 0;
    while (str[len] != '\0')
        len++;
    return (len);
}

int get_multiplier(int index, int len_arg)
{
    int multiplier;
    int times;
    
    //printf("index = %d, len_arg = %d\n", index, len_arg);
    multiplier = 1;
    times = len_arg - index - 1;
    while (times > 0)
    {
         multiplier = multiplier*10;
         times--;
    }
    //printf("multiplier = %d\n", multiplier);
    return (multiplier);
}

int get_int(char c, int index, int len_arg)
{
    int result;
    
    //printf("c to analyse = %c\n", c);
    result = (c - 48) * get_multiplier(index, len_arg);
    //printf("utils.c get_int, result = %d\n", result);
    return (result);
}

int ft_atoi(char **argv)
{
    int nb;
    int index;
    int len_arg;
    int keep_len_arg;

    len_arg = ft_strlen(argv[1]);
    keep_len_arg = len_arg;
    index = 0;
    nb = 0;
    while (len_arg > 0)
    {
        nb = nb + get_int(argv[1][index], index, keep_len_arg);
        //printf("ft_atoi > each int, nb = %d\n", nb);
        index++;
        len_arg--;
    }
    //nb = argv[i]
    //printf("utils.c ft_atoi | nb = %d\n", nb);
    return (nb);
}

int ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

/*int main(void)
{
    printf("result = %d\n", ft_atoi("123"));
    return (0);
}*/