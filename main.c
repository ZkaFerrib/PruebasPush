/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaizkafernandezribeiro <gaizkafernandez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:04:48 by gaizkaferna       #+#    #+#             */
/*   Updated: 2023/02/01 14:26:47 by gaizkaferna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

void ft_printlist(t_list *list);

t_list *ft_lstlast(t_list *list)
{
    while(list)
    {
        if(list->next == NULL)
            return(list);
        list = list->next;
    }
    return(list);
}

void    ft_addlistb(t_list **list, t_list *nodo)
{
    t_list      *last;

    if (!(*list))
        *list = nodo;
    else
    {
        last = ft_lstlast(*list);
        last->next = nodo;
    }
}

t_list *ft_lstnew(int content)
{
    t_list  *list;
    
    list = malloc(sizeof(*list));
    if (list == NULL)
        return (NULL);
    list->contenido = content;
    return(list);
}

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

int main(int argc, char** argv)
{
    t_list      *list;
    int         n;
    int         num;
    t_list      *aux;

    (void)argc;
    n = 1;
    while(argv[n])
    {
        num = ft_atoi(argv[n]);
        printf("%d \n", num);
        printf("here");
        aux = ft_lstnew(num);
        ft_addlistb(&list, aux);
        n++;
        printf("%d \n", n);
    }
    ft_printlist(list);
}

void ft_printlist(t_list *list)
{
    while(list)
    {
        printf("HERE\n");
        printf("%d, \n", list->contenido);
        list = list->next; 
    }
}
