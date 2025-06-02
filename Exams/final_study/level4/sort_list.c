typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;


t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	int temp;
	t_list *head;

	head = temp;
	while (lst != 0 && lst->next != 0)
	{
		if ((*cmp)(lst->data, lst->next->data) == 0)
		{
			temp = lst->data;
			lst->data = lst->next;
			lst->next = temp;
			lst = head;
		}
		else
			lst = lst->next;
	}
	return (head);
}