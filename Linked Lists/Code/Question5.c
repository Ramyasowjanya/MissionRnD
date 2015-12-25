//Given three numbers n1, n2, and r.Merge the table of n1 and n2 and find the r th number.In merging it should eliminate duplicate values
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
int find_rth_element(struct node *p, struct node *q, int r)
{
	struct node *ptemp = p, *qtemp = q;
	int rth_element;//rth_element is assigned smallest number and rth number is returned
	while (r >0)
	{
		if (ptemp->data == qtemp->data)//to eliminate redundancy
		{
			rth_element = ptemp->data;
			qtemp = qtemp->link;
			ptemp = ptemp->link;
		}
		else if (ptemp->data > qtemp->data)
		{
			rth_element = qtemp->data;
			qtemp = qtemp->link;
		}
		else
		{
			rth_element = ptemp->data;
			ptemp = ptemp->link;
		}
		--r;
	}

	return rth_element;
}
void main()
{
	int n1, n2, temp, r, rth_element, insert_no;
	struct node *first, *second;
	printf("Enter n1");
	scanf("%d", &n1);
	printf("Enter n2");
	scanf("%d", &n2);
	printf("Enter r");
	scanf("%d", &r);
	first = NULL;
	temp = r;
	insert_no = n1;
	while (temp != 0)
	{
		first = insert(first, insert_no);
		insert_no += n1;
		temp--;
	}
	second = NULL;
	temp = r;
	insert_no = n2;
	while (temp != 0)
	{
		second = insert(second, insert_no);
		insert_no += n2;
		temp--;
	}
	rth_element = find_rth_element(first, second, r);
	printf("Rth element of merged list is %d", rth_element);
}
