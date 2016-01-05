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
	return p;
}

struct node* add(struct node *first, struct node* second, int cou1, int cou2)
{
	struct node *temp = (struct node*)malloc(sizeof(struct node)), *result = NULL;
	int t = cou1 - cou2;;
	if (cou1 > cou2)//add the difference of lengths bits to final result
	{
		while (t > 0)
		{
			if (first->data == 9)//chance of overflow as first digit is 9
				result = insert(result, 0);
			result = insert(result, first->data);
			first = first->link;
			t--;
		}
	}
	else if (cou2>cou1)
	{
		t = -t;
		while (t > 0)
		{
			if (second->data == 9)
				result = insert(result, 0);
			result = insert(result, second->data);
			second = second->link;
			t--;
		}
	}
	else
	{
		result = insert(result, 0);
	}
	temp = result;//temp is to locate the position from which carry should be added
	if (temp != NULL)
	{
		while (temp->link != NULL&&temp != NULL)
		{
			if (temp->link->data < 9)
				temp = temp->link;
			else
				break;
		}
	}
	while (first != NULL && second != NULL)
	{
		if ((first->data + second->data)<9)
		{
			result = insert(result, first->data + second->data);
			if (temp == NULL)
				temp = result;
			else
				temp = temp->link;
		}
		else if ((first->data + second->data) == 9)
		{
			result = insert(result, first->data + second->data);
			if (temp == NULL)
				temp = result;
		}
		else
		{
			result = insert(result, (first->data + second->data) % 10);
			if (temp == NULL)
				temp = result;
			while (temp->link != NULL&&temp != NULL)//adding the carry
			{
				if (temp->data == 9)
					temp->data = 0;
				else
					temp->data += 1;
				temp = temp->link;
			}

		}
		first = first->link;
		second = second->link;
	}
	return result;
}

void main()
{
	int no = 1;
	struct node *first, *second, *result, *temp;
	int fcount = 0, scount = 0;
	first = NULL;
	second = NULL;
	result = NULL;
	printf("Enter list1 ");
	while (no != 0)
	{
		scanf("%d", &no);
		if (no != 0)
		{
			first = insert(first, no);
			fcount++;
		}
	}
	no = 1;
	printf("Enter list2 ");
	while (no != 0)
	{
		scanf("%d", &no);
		if (no != 0)
		{
			second = insert(second, no);
			scount++;
		}
	}
	result = add(first, second, fcount, scount);
	temp = result;
	printf("Resultant list is ");
	while (temp != NULL)
	{
		printf("%d", temp->data);
		temp = temp->link;
	}
}