#ifndef APC_H
#define APC_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>



#define SUCCESS		1
#define FAILURE		0

#define SAME		0
#define OPERAND1	1
#define OPERAND2	2

typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
}node;

void addition(node *tail1, node *tail2, node **headR, node **tailR);
void subtraction(node *tail1, node *tail2, node **headR, node **tailR);
void multiplication(node *head1, node *tail1, node *head2, node *tail2, node **headR, node **tailR);
int division(node *head1, node *tail1, node *head2, node *tail2, node **headR, node **tailR);

void handle_addition(node *head1, node *tail1, int sign1, node *head2, node *tail2, int sign2, node **headR, node **tailR, int *res_sign);
void handle_subtraction(node *head1, node *tail1, int sign1, node *head2, node *tail2, int sign2, node **headR, node **tailR, int *res_sign);
void handle_multiplication(node *head1, node *tail1, int sign1, node *head2, node *tail2, int sign2, node **headR, node **tailR, int *res_sign);
int handle_division(node *head1, node *tail1, int sign1, node *head2, node *tail2, int sign2, node **headR, node **tailR, int *res_sign);


int cla_validation(int argc, char *argv[]);
int create_list(const char *str, node **head, node **tail);

int insert_first(node **head, node **tail, int data);
int insert_last(node **head, node **tail, int data);
int delete_list(node **head, node **tail);
void print_list(node *head);

int compare_list(node *head1, node *head2);
int list_len(node *head);
int is_zero(node *headR);
void remove_pre_zeros(node **head);



#endif
