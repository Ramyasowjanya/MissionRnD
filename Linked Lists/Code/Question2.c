//Merge linked lists which are sorted
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
struct node* merge(struct node *p, struct node *q)
{
	struct node *ptemp = p, *qtemp = q;
	struct node *result = (struct node*)malloc(sizeof(struct node));
	result = NULL;
	if (ptemp != NULL&&qtemp != NULL)
	{
		while (ptemp != NULL&&qtemp != NULL)
		{
			if (ptemp->data == qtemp->data)//to eliminate redundancy
			{
				result = insert(result, qtemp->data);
				qtemp = qtemp->link;
				ptemp = ptemp->link;
			}
			else if (ptemp->data > qtemp->data)
			{
				result = insert(result, qtemp->data);
				qtemp = qtemp->link;
			}
			else
			{
				result = insert(result, ptemp->data);
				ptemp = ptemp->link;
			}
		}
		if (ptemp != NULL)
		{
			while (ptemp != NULL)
			{
				result = insert(result, ptemp->data);
				ptemp = ptemp->link;
			}
		}
		if (qtemp != NULL)
		{
			while (qtemp != NULL)
			{
				result = insert(result, qtemp->data);
				qtemp = qtemp->link;
			}
		}
		return result;
	}
	return NULL;
}
void main()
{
	int no = 1;
	struct node *p, *q, *temp = NULL;
	p = NULL;
	printf("Enter First sorted list");
	while (no != 0)
	{
		scanf("%d", &no);
		p = insert(p, no);
	}
	q = NULL;
	no = 1;
	printf("Enter second sorted list");
	while (no != 0)
	{
		scanf("%d", &no);
		q = insert(q, no);
	}
	temp = merge(p, q);
	printf("Merged sorted list");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	scanf("%d", &no);
}