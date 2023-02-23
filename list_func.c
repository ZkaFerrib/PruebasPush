/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gafernan <gafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 14:11:35 by gafernan          #+#    #+#             */
/*   Updated: 2023/02/23 14:26:45 by gafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstlast(t_list *list)
{
	while (list)
	{
		if (list->next == NULL)
			return (list);
		list = list->next;
	}
	return (list);
}

void	ft_addlistb(t_list **list, t_list *nodo)
{
	t_list	*last;

	if (!(*list))
		*list = nodo;
	else
	{
		last = ft_lstlast(*list);
		last->next = nodo;
	}
}

void	ft_addlistf(t_list **list, t_list **nodo)
{
	t_list	*aux;

	if (*nodo)
	{
		aux = *list;
		*list = *nodo;
		(*nodo)->next = aux;
	}
}
