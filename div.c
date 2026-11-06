#include "apc.h"

int division(node *head1, node *tail1, node *head2, node *tail2, node **headR, node **tailR)
{
    /* check if the divisor is zero*/
    if(is_zero(head2))
    return FAILURE;
    
    /* check if the dividend is zero*/
    if(is_zero(head1))
    {
        insert_first(headR,tailR,0);
        return SUCCESS;
    }

    /*creating temporary linked lists*/

    node *rem_head = NULL, *rem_tail = NULL;
    node *quo_head = NULL, *quo_tail = NULL;

    node *cur = head1;

    while(cur)
    {
        /* Bring down one digit*/
        insert_last(&rem_head, &rem_tail, cur->data);
        remove_pre_zeros(&rem_head);
        int count = 0;

        /* repeat the subtraction*/
        while(compare_list(rem_head, head2) >= 0)
        {
            node *temp_head = NULL;
            node *temp_tail = NULL;

            subtraction(rem_tail, tail2, &temp_head, &temp_tail);

            delete_list(&rem_head, &rem_tail);

            rem_head = temp_head;
            rem_tail = temp_tail;

            count++;
        }

        insert_last(&quo_head, &quo_tail, count);

        cur = cur->next;
    }

    if(quo_head == NULL)
    {
        insert_first(&quo_head, &quo_tail, 0);
    }

    remove_pre_zeros(&quo_head);

    *headR = quo_head;
    *tailR = quo_tail;

    delete_list(&rem_head, &rem_tail);
    return SUCCESS;
}

/* Handle sign for division*/
int handle_division(node *head1, node *tail1, int sign1, node *head2, node *tail2, int sign2, node **headR, node **tailR, int *res_sign)
{
    if (division(head1, tail1, head2, tail2, headR, tailR) == FAILURE)
    return FAILURE;

    /*Zero should never be negative*/
    if(is_zero(*headR))
        *res_sign = 1;
    else
        *res_sign = (sign1 == sign2) ? 1 : -1;

    return SUCCESS;
}
