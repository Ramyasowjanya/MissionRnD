//Given a linked list which is in pattern like combination of ascending and descending. Sort it
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
void reverse(struct node* p)
{
	struct node *temp;
	if (p->link != NULL)
	{
		reverse(p->link);
		temp = p;
		p = p->link;
		temp->link = p->link;
		p->link = temp;
	}
}
void sort_the_list(struct node *p)
{
	struct node *ptemp = p, *qtemp = p, *prev = p;
	while (ptemp != NULL&&ptemp->link != NULL)
	{
		if (ptemp->data>ptemp->link->data)
		{//to find start of descending part of list
			break;
		}
		prev = ptemp;
		ptemp = ptemp->link;
	}
	qtemp = ptemp;
	while (qtemp->link != NULL)
	{
		qtemp = qtemp->link;
	}
	reverse(ptemp);//reverse the descending part of list
	prev->link = qtemp;
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