/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gaizkafernandezribeiro <gaizkafernandez    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 13:04:48 by gaizkaferna       #+#    #+#             */
/*   Updated: 2023/02/01 18:40:10 by gaizkaferna      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
#include <stdlib.h>
#include <stdio.h>

int     ft_listsize(t_list *list);
void    ft_rotatedown(t_list **list);
void    ft_swap(t_list **list);
void    ft_rotateup(t_list **list);
void    ft_printlist(t_list *list);
t_list  *ft_getlist(char **argv);

t_list  *ft_lstlast(t_list *list)
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

void    ft_addlistf(t_list **list, t_list *nodo)
{
    if(list && new)
    {
        new->next = *list;
        list = new;
    }
}

t_list  *ft_lstnew(int content)
{
    t_list  *list;
    
    list = malloc(sizeof(*list));
    if (list == NULL)
        return (NULL);
    list->contenido = content;
    return(list);
}

int     ft_atoi(const char *str)
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

    list = NULL;
    (void)argc;
    list = ft_getlist(&argv[1]);
    ft_printlist(list);
    ft_rotatedown(&list);
    ft_printlist(list);
}

void ft_printlist(t_list *list)
{
    while(list)
    {
        printf("%d, \n", list->contenido);
        list = list->next; 
    }
}

t_list *ft_getlist(char **argv)
{
    int n;
    int num;
    t_list *list;
    
    n = 0;
    num = 0;
    while(argv[n])
    {
        num = ft_atoi(argv[n]);
        ft_addlistb(&list, ft_lstnew(num));
        n++;
    }
    return(list);
}

/* void    ft_rotateup(t_list **list)
{
    t_list      *last;
    t_list      *aux;

    aux = *list;
    last = ft_lstlast(*list);
    *list = (*list)->next;
    last->next = aux;
    aux->next = NULL;
} */

/* void    ft_swap(t_list **list)
{
    t_list      *aux;

    aux = *list;
    *list = aux->next;
    aux->next = (*list)->next;
    (*list)->next = aux;
} */

void    ft_rotatedown(t_list **list)
{
    t_list      *aux;

    aux = *list;
    while(aux->next->next != NULL)
            aux = aux->next;
    aux->next->next = *list;
    *list = aux->next;
    aux->next = *list;
}

int ft_listsize(t_list *list)
{
    int i;

    i = 0;
    while(list)
    {
        list = list->next;
        i++;
    }
    return(i);
}