/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:04:59 by gafernan          #+#    #+#             */
/*   Updated: 2023/02/09 13:17:02 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "struct.h"

int	ft_atoi(const char *str)
{
	int	sign;
	int	i;
	int	num;

	sign = 1;
	i = 0;
	num = 0;
	while ((str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}	
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			break ;
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * sign);
}