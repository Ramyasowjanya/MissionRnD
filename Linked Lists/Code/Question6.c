//Write a program to add two linked list(Each node is represented by a digit) (Note: Unequal Lengths can also be given)
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};

struct node * insert(struct node *p, int no)
{//insertion at the end of the list
	struct node *temp, *q;
	if (no != 0)
	{
		if (p == NULL)
		{
			p = (struct node*)malloc(sizeof(struct node));
			p->data = no;
			p->link = NULL;
		}
		else
		{
			temp = p;
			while (temp->link != NULL)
				temp = temp->link;
			q = (struct node*)malloc(sizeof(struct node));
			q->data = no;
			temp->link = q;
			q->link = NULL;
		}
	}
	return p;
}

struct node* add(struct node *first, struct node* second)
{
	struct node *temp = NULL;
	while (first != NULL && second != NULL)
	{
		temp = insert(temp, first->data + second->data);
		first = first->link;
		second = second->link;
	}
	if (first != NULL)//if first list is larger than second
	{
		while (first != NULL)
		{
			temp = insert(temp, first->data);
			first = first->link;
		}
	}
	if (second != NULL)//if first list is smaller than second
	{
		while (second != NULL)
		{
			temp = insert(temp, second->data);
			second = second->link;
		}
	}
	return temp;
}

void main()
{
	int no = 1;
	struct node *first, *second, *result, *temp;
	first = NULL;
	second = NULL;
	result = NULL;
	printf("Enter list1");
	while (no != 0)
	{
		scanf("%d", &no);
		first = insert(first, no);
	}
	no = 1;
	printf("Enter list2");
	while (no != 0)
	{
		scanf("%d", &no);
		second = insert(second, no);
	}
	result = add(first, second);
	temp = result;
	printf("Resultant list is ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
}