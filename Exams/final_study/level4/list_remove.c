#include <stdlib.h>


typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}	t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
    t_list *tmp;
    
    while (*begin_list && cmp((*begin_list)->data, data_ref) == 0) {
        tmp = *begin_list;
        *begin_list = (*begin_list)->next;
        free(tmp);
    }

    t_list *current = *begin_list;
    while (current && current->next) {
        if (cmp(current->next->data, data_ref) == 0) {
            tmp = current->next;
            current->next = current->next->next;
            free(tmp);
        } else {
            current = current->next;
        }
    }
}
