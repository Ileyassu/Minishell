#include "libft.h"

void ft_listiter(t_list *list, void (*f)(void *))
{
    while(list)  
    {
        (*f)(list -> content);
        list = list -> next;
    }
}
/*
void cnttoupper(void *content)
{
    char *str = (char *)content;
    int i = 0;
    while(str[i])
    {
        str[i] = ft_toupper(str[i]);
        i++;
    }
    //return content;
}

int main()
{
    t_list *head = ft_listnew(strdup("a"));
    ft_listadd_back(&head, ft_listnew(strdup("a")));
    ft_listadd_back(&head, ft_listnew(strdup("2")));
    ft_listadd_back(&head, ft_listnew(strdup("3")));
    ft_listadd_back(&head, ft_listnew(strdup("4")));
    
    int i = ft_listsize(head);
    ft_listiter(head, cnttoupper);
    printf("%s\n", (char *)head -> content);
    printf("%d\n", i);
}
*/