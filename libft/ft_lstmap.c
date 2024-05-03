/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:45:35 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/14 11:46:18 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_listmap(t_list *list, void *(*f)(void *), void (*del)(void *))
{
    ft_size *new_list = NULL;
    ft_size *current;
    while(list)
    {
        void *newnode;

        newnode = ft_listnew((f*)(list -> content));
        if(!newnode)
        {
            ft_listclear(&list, del);
            return (NULL);
        }
        else
        {
            current -> next = newnode;
            ft_listadd_back(&list, newnode);
        }
        list = list -> next;
    }
    return (newlist);
}