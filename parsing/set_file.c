#include "../cub3d.h"

t_file  *linked_list(int ln)
{
    t_file  *head;
    t_file  *tmp;
    t_file  *curr;

    head = malloc(sizeof(t_file));
    if (!head)
        return (p_error(ERR_MEM), exit (1), NULL);
    tmp = head;
    tmp->next = NULL;
    curr = NULL;
    while (--ln)
    {
        curr = malloc(sizeof(t_file));
        if (!curr)
            return (p_error(ERR_MEM), exit (1), NULL);
        curr->next = NULL;
        tmp->next = curr;
        tmp = curr;
    }
    return (head);
}
