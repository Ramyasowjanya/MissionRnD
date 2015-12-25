//Sorted a linked list which is in ascending order but two numbers are changed ,i mean not in the usual order they need to be
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
void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}
void sort_the_list(struct node *p)
{
	struct node *ptemp = p, *qtemp = p;
	while (ptemp != NULL&&ptemp->link != NULL)
	{
		if (ptemp->data>ptemp->link->data)
		{//to find the greater element to be reversed
			break;
		}
		ptemp = ptemp->link;
	}
	qtemp = ptemp->link;
	while (qtemp != NULL&&qtemp->link != NULL)
	{
		if (qtemp->data<qtemp->link->data&&qtemp->data>ptemp->data)
		{//the next element to smaller element should be greater than greater element
			break;
		}
		qtemp = qtemp->link;
	}
	swap(&ptemp->data, &qtemp->data);
}
void main()
{
	int no = 1;
	struct node *p, *temp;
	p = NULL;
	printf("Enter list ");
	while (no != 0)
	{
		scanf("%d", &no);
		p = insert(p, no);
	}
	temp = p;
	sort_the_list(p);
	printf("Resultant list is ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
}