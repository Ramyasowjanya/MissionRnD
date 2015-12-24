//Add a node to the circular linked list
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
struct cnode
{
	int data;
	struct cnode *link;
};

struct cnode * insert(struct cnode *p, int no)
{//insertion at the end of the list
	struct cnode *temp, *q;
	if (no != 0)
	{
		if (p == NULL)
		{
			p = (struct cnode*)malloc(sizeof(struct cnode));
			p->data = no;
			p->link = p;
		}
		else
		{
			temp = p;
			while (temp->link != p)
				temp = temp->link;
			q = (struct cnode*)malloc(sizeof(struct cnode));
			q->data = no;
			temp->link = q;
			q->link = p;
		}
	}
	return p;
}
void main()
{
	int no = 1;
	struct cnode *p, *temp;
	p = NULL;
	while (no != 0)
	{
		scanf("%d", &no);
		p = insert(p, no);
	}
	temp = p;
	printf("%d ", temp->data);
	temp = temp->link;
	while (temp != p)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	scanf("%d", &no);
}