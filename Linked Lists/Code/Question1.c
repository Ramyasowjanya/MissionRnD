/*Find median of a given linked list (Sorted Linked List)*/
/*#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *link;
};
void median(struct node *p)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node)), *q = (struct node*)malloc(sizeof(struct node));
	if (p != NULL && p->link != NULL)
	{
		q = p;
		temp = p;
		while (q != NULL && q->link != NULL)
		{
			if (q->link->link != NULL)
			{
				q = q->link->link;
				temp = temp->link;
			}
			else//in even list cases after reaching median nodes it will break
			{
				break;
			}
		}
		if (q->link==NULL)//if list is of odd length
			printf("%d is median", temp->data);
		else//if list is of even length
			printf("%d is median", ((temp->data)+(temp->link->data))/2);
	}
	else if (p == NULL)//if no elements are present
		printf("No median");
	else //if only one element is present
		printf("%d is median",p->data);
}
struct node * insert(struct node *p, int no)
{
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
void main()
{
	int no = 1;
	struct node *p;
	p = NULL;
	while (no != 0)
	{
		scanf("%d", &no);
		p = insert(p, no);
	}
	median(p);
}*/