/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 07:33:29 by ibenaiss          #+#    #+#             */
/*   Updated: 2023/11/14 07:33:29 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_listclear(t_list **list, void (*del)(void*))
{
    t_list *current;
    t_list *next;

    current = *list;
    while(current)
    {   next = current -> next;
        (*del)(current -> content);
        free(current); 
        current = next;
    }
    *list = NULL;
}
/*
void deletecontent(void *content)
{
    free(content);
}
int main()
{
    t_list *head = ft_listnew(strdup("0"));
    t_list *new1 = ft_listnew(strdup("1"));
    t_list *new2 = ft_listnew(strdup("2"));
    t_list *new3 = ft_listnew(strdup("3"));
    ft_listadd_front(&head, new1);
    ft_listadd_front(&head, new2);
    ft_listadd_front(&head, new3);
    int i = ft_listsize(head);
    ft_listclear(&head, deletecontent);
    //free(new1);
    //ft_listdelone(new1, deletecontent);
    //printf("%p\n", new1);
    //printf("i = %d\n", i);
    char *s = malloc(3);
    s = strdup("12");
    free(s);
    printf("%s\n", s);
}
*/