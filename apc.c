#include "apc.h"

/* check operand is a valid number */
static int valid_number(const char *str)
{
    int i = 0;

    /* skip the optional sign */

    if(str[i] == '+' || str[i] == '-')
    i++;

    /* sign alone is not a number */

    if(str[i] == '\0')
    return FAILURE;

    /*check whether remaining characters are digits or not*/

    while(str[i])
    {
        if(!isdigit(str[i]))
        return FAILURE;
        i++;
    }

    return SUCCESS;
}

/* Validate commmand line arguments*/
int cla_validation(int argc,char *argv[])
{
    if(argc != 4)
    {
        printf("Usage : ./APC.out <operand1> <operator> <operand2>\n");
        return FAILURE;
    }

    /* Validate first argument*/
    if(valid_number(argv[1]) == FAILURE)
    {
        printf("Error: First operand is invalid\n");
        return FAILURE;
    }

    /* Validate second argument*/
    if(strlen(argv[2]) != 1)
    {
        printf("Error: invalid operator\n");
        return FAILURE;
    }

    /*Validate third argument*/
    if(valid_number(argv[3]) == FAILURE)
    {
        printf("Error: Second operand is invalid\n");
        return FAILURE;
    }


    char op = argv[2][0];

    /*accept both x and X for multiplication*/
    if (op == 'x')
        op ='X';

    if(op != '+' && op != '-' && op != 'X' && op != '/')
    {
        printf("Error: Unsupported operator\n");
        return FAILURE;
    }

    return SUCCESS;
}

/* Convert numeric string into linked list*/
int create_list(const char *str,node **head, node **tail)
{
    for(int i = 0; str[i]; i++){
        int digit = str[i] - '0';

        if(insert_last(head,tail,digit) == FAILURE)
        {
            delete_list(head,tail);
            return FAILURE;
        }
    }

    return SUCCESS;
}