/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:45:35 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/13 11:48:50 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_listsize(t_list *list)
{
    int i;

    i = 0;
    while(list)
    {
        i++;
        list = list -> next;
    }
    return (i);
}
/*
int main()
{
    t_list *head = ft_listnew("wqwq");
    t_list *new1 = ft_listnew("asas");
    t_list *new2 = ft_listnew("asasa");
    t_list *new3 = ft_listnew("asasaaaaaaa");

    ft_listadd_front(&head, new1);
    ft_listadd_front(&head, new2);
    ft_listadd_front(&head, new3);

    int i = ft_listsize(head);
    printf("i = %d\n", i);
}
*/