/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: proche-c <proche-c@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:37:06 by proche-c          #+#    #+#             */
/*   Updated: 2021/11/18 17:47:35 by proche-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void    ft_swap(char *a, char *b)
{
        char	*c;

        c = a;
        a = b;
        b = c;
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	a;
	unsigned char	b;

	while (*s1 != '\0' && *s2 == *s1)
	{
		s1++;
		s2++;
	}
	a = (unsigned char)*s1;
	b = (unsigned char)*s2;
	return (a - b);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
			str++;
	}
}

void	ft_print_result(int argc, char **argv)
{
	int	i;

	i = argc -1;
	while (i > 0)
	{
		ft_putstr(argv[i]);
		write(1, "\n", 1);
		i--;
	}
}

void	ft_sort_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		result;
	int	k;

	k = 0;
	while(k < argc)
	{
		i = 1;
		while (i < argc)
		{
			j = 0;
			if (i < argc - 1)
			{
				result = ft_strcmp(argv[i], argv[i + 1]);
				if (result < 0)
				{
					ft_swap(argv[i], argv[i + 1]);
				}
			}
			i++;
		}
		k++;
	}
	ft_print_result(argc, argv);
}

int	main(int argc, char **argv)
{
	ft_sort_params(argc, argv);
	return (0);
}
