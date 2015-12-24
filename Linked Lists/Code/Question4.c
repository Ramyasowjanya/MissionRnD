//Reverse an Linked list, using recursion
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
void main()
{
	int no = 1;
	struct node *p, *temp;
	p = NULL;
	while (no != 0)
	{
		scanf("%d", &no);
		p = insert(p, no);
	}
	temp = p;
	while (temp->link != NULL)//to reach end of list for printing end of list
	{
		temp = temp->link;
	}
	reverse(p);
	printf("Resultant list is ");
	while (temp != NULL)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
}