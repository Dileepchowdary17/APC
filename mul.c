#include "apc.h"

/* Function to multiply two positive numbers*/
void multiplication(node *head1, node *tail1, node *head2, node *tail2, node **headR, node **tailR)
{
    /*If either number is zero, answer is zero*/
    if(is_zero(head1) || is_zero(head2))
    {
        insert_first(headR,tailR,0);
        return;
    }

    /*intialise result as zero*/
    insert_first(headR,tailR,0);

    node *ptr2 = tail2;
    int shift = 0;

    while(ptr2)
    {
        node *ptr1 = tail1;
        node *temp_head = NULL;
        node *temp_tail = NULL;

        int carry = 0;

        /*Multiply one digit with complete first number*/

        while(ptr1 || carry)
        {
            int digit = (ptr1) ? ptr1->data : 0;
            int product = digit * ptr2->data + carry;

            carry = product / 10;

            insert_first(&temp_head,&temp_tail, product % 10);
            if(ptr1)
            ptr1 = ptr1->prev;
        }

        /*Append zeros according to place value*/
        for(int i = 0; i < shift; i++)
        insert_last(&temp_head, &temp_tail, 0);
        
        node *new_head = NULL;
        node *new_tail = NULL;

        /*Add partial product to final result*/
        addition(*tailR, temp_tail, &new_head, &new_tail);

        delete_list(headR, tailR);
        delete_list(&temp_head, &temp_tail);

        *headR = new_head;
        *tailR = new_tail;

        shift++;
        ptr2 = ptr2->prev;
    }

    /*Remove unnecessary leading zeros*/
    remove_pre_zeros(headR);
}

/*Handle sign for multiplication*/
void handle_multiplication(node *head1, node *tail1, int sign1, node *head2, node *tail2, int sign2, node **headR, node **tailR, int *res_sign)
{
    multiplication(head1, tail1, head2, tail2, headR, tailR);

    /*Zero should never have a negative sign*/
    if(is_zero(*headR))
    *res_sign = 1;
    else
    *res_sign = (sign1 == sign2) ? 1 : -1;
}
