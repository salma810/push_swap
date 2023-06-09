/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssaadaou <ssaadaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 22:31:05 by ssaadaou          #+#    #+#             */
/*   Updated: 2023/06/19 20:06:58 by ssaadaou         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *buff)
{
    while (*buff)
	{
		ft_putchar(*buff);
		buff++;
	}
}
int ft_atoi(char *s)
{
	int	i;
	int	res;
	int sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((s[i] == ' ') || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '0')
	{
		while(s[i] == '0')
			i++;
	}
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] && s[i] >= '0' && s[i] <= '9')
	{
		res = (res * 10) + (s[i] - '0');
		i++;
	}
	return (res * sign);
}

int ft_duplicate(char **str)
{
	int i;
	int j;

	i = 0;
	while(str[i])
	{
		j = i + 1;
		while(str[j])
		{
			if(ft_atoi (str[i]) == ft_atoi (str[j]))
				return (0);
			j++;
		}
		i++;
	}
	return(1);
}

char	*mein_strjoin(int ac, char **str, char *del)
{
	int		i;
	int		j;
	int 	x;
	int		len;
	char	*tmp;

	i = 1;
	x = 0;
	len = ft_strslen(str, del, ac);
	tmp = malloc(sizeof(char) * (len + 1));
	if(!tmp)
		return(NULL);
	while(i < ac)
	{	
		j= 0 ;
		while(str[i][j] != '\0')
			tmp[x++] = str[i][j++];
		if(i < ac - 1)
		{
			j = 0;
			while (del[j] != '\0')
				tmp[x++] = del[j++];
		}
		i++;
	}
	return(tmp);
}

int is_space(char c)
{
	if (c == '\t' || c == '\f' || c == '\v'
		|| c == '\n' || c == '\r' || c == ' ')
		return (1);
	return (0);
}


int is_empty(int ac, char **str)
{
	int i = 1;
	size_t j;
	while(i < ac)
	{
		j = 0;
		while(is_space(str[i][j] ))
			j++;
		if(str[i][j] == '\0')
		{
			ft_putstr("empty input\n");
			exit (1);
		}
		i++;
	}
	return(1);
}