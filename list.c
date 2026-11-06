#include "apc.h"

/*Insert the node at the begining*/

int insert_first(node **h,node **t,int d){
    node *new = malloc(sizeof(node));

    if(new == NULL)
    return FAILURE;

    new->data = d;
    new->prev = NULL;
    new->next = *h;
    
    if(*h == NULL){
        *h = new;
        *t = new;
    }
    
    else{
        (*h)->prev = new;
        *h = new;
    }
    
    return SUCCESS;
}

/* Insert node at the end*/

int insert_last(node **h,node **t,int d)
{
    node *new = malloc(sizeof(node));
    
    if(new == NULL)
    return FAILURE;
    
    new->data = d;
    new->next = NULL;
    new->prev = *t;

    if(*t == NULL)
    {
        *h = new;
        *t = new;
    }

    else
    {
        (*t)->next = new;
        *t = new;
    }

    return SUCCESS;
}

/* Delete entire list */

int delete_list(node **h,node **t)
{
    node *temp;

    while(*h)
    {
        temp = *h;
        *h = (*h)->next;
        free(temp);
    }
    
    *t = NULL;

    return SUCCESS;
}

/* print the number*/

void print_list(node *h)
{
    if(h == NULL)
    {
        printf("0\n");
        return;
    }

    while(h)
    {
        printf("%d", h->data);
        h = h->next;
    }

    printf("\n");
}

/*find the length of the linked list*/
int list_len(node *head)
{
    int count = 0;

    while(head)
    {
        count++;
        head = head->next;
    }
    return count;
}

/*remove leading zeros */
void remove_pre_zeros(node **h)
{
    if(*h == NULL)
    return;

    while((*h)->data == 0 && (*h)->next != NULL)
    {
        node *temp = *h;
        *h = (*h)->next;
        (*h)->prev = NULL;
        free(temp);
    }
}

/* check whether number is zero */
int is_zero(node *h)
{
    if(h == NULL)
    return 1;

    while(h)
    {
        if(h->data != 0)
        return 0;
        h = h->next;
    }

    return 1;
}

/*compare two numbers and return
1 if(first > second)
-1 if(first < second)
0 if equal
*/

int compare_list(node *h1,node *h2)
{
    while(h1 && h1->data == 0 && h1->next)
    {
        h1 = h1->next;
    }

    while(h2 && h2->data == 0 && h2->next)
    {
        h2 = h2->next;
    }

    int len1 = list_len(h1),len2 = list_len(h2);

    /* compare lengths */
    if(len1 > len2)
        return 1;

    if(len1 < len2)
        return -1;

    /* if lengths are equal then compare digit by digit*/
    while(h1 && h2)
    {
        if(h1->data > h2->data)
            return 1;
        
        if(h1->data < h2->data)
            return -1;

        h1 = h1->next;
        h2 = h2->next;
    }

    return 0;
}

