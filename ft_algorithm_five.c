/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algorithm_five.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 13:53:25 by gafernan          #+#    #+#             */
/*   Updated: 2023/02/23 14:29:59 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_algorithm_five(t_control *control)
{
	ft_minvalue(control);
	ft_pushmin(control);
	ft_minvalue(control);
	ft_pushmin(control);
	ft_algorithm_three(control);
	ft_pushstack(control, 'a');
	ft_pushstack(control, 'a');
}
