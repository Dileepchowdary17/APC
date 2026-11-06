#include "apc.h"

/* Function to subtract two numbers
* Assumption : First number >= second number
*/
void subtraction(node *tail1, node *tail2, node **headR, node **tailR)
{
    int borrow = 0;

    while(tail1 != NULL)
    {
        int d1 = tail1->data;
        int d2 = (tail2 != NULL) ? tail2->data : 0;

        d1 -= borrow;

        if(d1 < d2)
        {
            d1 += 10;
            borrow = 1;
        }

        else
        {
            borrow = 0;
        }

        insert_first(headR, tailR, d1 - d2);

        tail1 = tail1->prev;
        if(tail2)
        tail2 = tail2->prev;
    }

    /*Removing leading zeros from the result*/
    remove_pre_zeros(headR);

    /*If list becomes empty, make result as 0*/
    if(*headR == NULL)
    insert_first(headR, tailR, 0);
}

void handle_subtraction(node *head1, node *tail1, int sign1, node *head2, node *tail2, int sign2, node **headR, node **tailR, int *res_sign)
{
    int cmp = compare_list(head1, head2);

    /*For the same sign*/
    if(sign1 == sign2)
    {
        /*if both numbers are equal*/
        if(cmp == 0)
        {
            insert_first(headR, tailR, 0);
            *res_sign = 1;
        }

        /*if first number is greater*/
        else if(cmp > 0)
        {
            subtraction(tail1, tail2, headR, tailR);
            *res_sign = sign1;
        }

        /*if second number is greater*/
        else if(cmp < 0)
        {
            subtraction(tail2, tail1, headR, tailR);
            *res_sign = -sign1;
        }
    }

    else
    {
        /*if it is different signs then perform the addition*/
        addition(tail1, tail2, headR, tailR);
        *res_sign = sign1;
    }
}
