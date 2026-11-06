#include "apc.h"

/* Function for adding two positive numbers*/
void addition(node *tail1, node *tail2, node **headR, node **tailR)
{
    int carry = 0;

    while(tail1 != NULL || tail2 != NULL || carry)
    {
        int sum = carry;
        if(tail1)
        {
            sum += tail1->data;
            tail1 = tail1->prev;
        }

        if(tail2)
        {
            sum += tail2->data;
            tail2 = tail2->prev;
        }

        carry = sum / 10;
        insert_first(headR,tailR,sum % 10);
    }

    /* Remove unnecessary leading zeros*/
    remove_pre_zeros(headR);
}

/* Handle sign for addition*/
void handle_addition(node *head1, node *tail1, int sign1, node *head2, node *tail2, int sign2, node **headR, node **tailR, int *res_sign)
{
    int cmp = compare_list(head1, head2);

    /* Same sign -> perform addition*/
    if(sign1 == sign2)
    {
        addition(tail1, tail2, headR, tailR);
        *res_sign = sign1;
    }

    else
    {
        /*if numbers are equal*/
        if(cmp == 0)
        {
            insert_first(headR, tailR, 0);
            *res_sign = 1;
        }

        /* if first number is greater*/
        else if(cmp > 0)
        {
            subtraction(tail1, tail2, headR, tailR);
            *res_sign = sign1;
        }

        /*if second number is greater*/
        else if(cmp < 0)
        {
            subtraction(tail1, tail2, headR, tailR);
            *res_sign = sign2;
        }
    }
}
