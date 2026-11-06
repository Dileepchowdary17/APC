#include "apc.h"

int main(int argc, char *argv[])
{
	/* validate command line arguments*/
	if(cla_validation(argc,argv) == FAILURE)
	return FAILURE;

    node *head1 = NULL, *tail1 = NULL, *head2 = NULL, *tail2 = NULL, *headR = NULL, *tailR = NULL;

	int sign1 = 1, sign2 = 1;
	int res_sign = 1;

	/*sign of first operand*/
	if(argv[1][0] == '-')
	sign1 = -1;

	/*sign of second operand*/
	if(argv[3][0] == '-')
	sign2 = -1;


    // Create 2 lists of operands
	char *op1 = (argv[1][0] == '+' || argv[1][0] == '-') ? argv[1] + 1 : argv[1];
	char *op2 = (argv[3][0] == '+' || argv[3][0] == '-') ? argv[3] + 1 : argv[3];
    
	if(create_list(op1,&head1,&tail1) == FAILURE || create_list(op2,&head2,&tail2) == FAILURE)
	{
		printf("Memory allocation failed\n");
		return FAILURE;
	}

	remove_pre_zeros(&head1);
	remove_pre_zeros(&head2);

    char op = argv[2][0];

    switch(op)
    {
	case '+':
	    handle_addition(head1, tail1, sign1, head2, tail2, sign2, &headR, &tailR, &res_sign);
	    break;
		
	case '-':
	    handle_subtraction(head1, tail1, sign1, head2, tail2, sign2, &headR, &tailR, &res_sign);
	    break;
		
	case 'x':
	case 'X':
	    handle_multiplication(head1, tail1, sign1, head2, tail2, sign2, &headR, &tailR, &res_sign);
	    break;
		
	case '/':
		if(is_zero(head2))
		{
			printf("Error: Division by zero\n");

			delete_list(&head1, &tail1);
			delete_list(&head2, &tail2);

			return FAILURE;
		}

	    handle_division(head1, tail1, sign1, head2, tail2, sign2, &headR, &tailR, &res_sign);
		break;

	default:
	    printf("Invalid operator\n");
    }

	/*printing negative sign if required*/
	printf("Result: ");
	if(res_sign == -1 && !is_zero(headR))
		printf("-");
	
	print_list(headR);

	/* Free the allocated memory*/
	delete_list(&head1,&tail1);
	delete_list(&head2,&tail2);
	delete_list(&headR,&tailR);

	return SUCCESS;
}
