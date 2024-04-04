#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include"fun.h"
int com(struct LL* temp,struct LL* temp1)
{
	if (temp->year > temp1->year)
		return 1;
	else if (temp->year == temp1->year&&temp->month > temp1->month)
		return 1;
	else if (temp->year == temp1->year && temp->month == temp1->month&&temp->day > temp1->day)
		return 1;
	else if (temp->year == temp1->year && temp->month == temp1->month && temp->day == temp1->day &&temp->hour > temp1->hour)
		return 1;
	else if (temp->year == temp1->year && temp->month == temp1->month && temp->day == temp1->day && temp->hour == temp1->hour &&temp->minute > temp1->minute)
		return 1;
	else
		return 0;
}
int com1(struct LL* temp, struct LL* temp1)
{
	if (temp->absent > temp1->absent)
		return 1;
	return 0;
}
int com2(struct LL* temp, struct LL* temp1)
{
	if (temp->x < temp1->x)
		return 1;
	return 0;
}
void msort(int i,int j,struct LL** a,struct LL** b,int (*com)(struct LL*, struct LL*))
{
	if ((i + j) / 2 != i)
		msort(i, (i + j) / 2, a,b, com), msort(((i+j)/2)+1,j,a,b,com);
	for (int w = i, t = ((i + j) / 2) + 1, h = i;w<= (i + j) / 2||t<=j;)
	{
		if (w > (i + j) / 2)
			b[h++] = a[t++];
		else if (t > j)
			b[h++] = a[w++];
		else
		{
			if (com(a[w], a[t]))
				b[h++] = a[w++];
			else
				b[h++] = a[t++];
		}
	}
	for (int k = i; k <= j; k++)
		a[k] = b[k];
}
void t_msort(struct LL** head)
{
	int n = 0;
	struct LL* temp = *head;
	struct LL** a = (struct LL**)malloc(100 * sizeof(struct LL*));
	if (a == NULL)
		exit(-1);
	struct LL** b = (struct LL**)malloc(100 * sizeof(struct LL*));
	if (b == NULL)
		exit(-1);
	while (temp != NULL)
	{
		a[n] = temp;
		temp = temp->next;
		n++;
	}
	a[n] = NULL;
	msort(0, n - 1, a,b, com);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			*head = a[i];
		a[i]->next = a[i + 1];
	}
	free(a);
	free(b);
}
void a_msort(struct LL** head)
{
	int n = 0;
	struct LL* temp = *head;
	struct LL** a = (struct LL**)malloc(100 * sizeof(struct LL*));
	if (a == NULL)
		exit(-1);
	struct LL** b = (struct LL**)malloc(100 * sizeof(struct LL*));
	if (b == NULL)
		exit(-1);
	while (temp != NULL)
	{
		a[n] = temp;
		temp = temp->next;
		n++;
	}
	a[n] = NULL;
	msort(0, n - 1, a, b, com1);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			*head = a[i];
		a[i]->next = a[i + 1];
	}
	free(a);
	free(b);
}
void set_up(struct LL** head)
{
	int n = 0;
	struct LL* temp = *head;
	struct LL** a = (struct LL**)malloc(100 * sizeof(struct LL*));
	if (a == NULL)
		exit(-1);
	struct LL** b = (struct LL**)malloc(100 * sizeof(struct LL*));
	if (b == NULL)
		exit(-1);
	while (temp != NULL)
	{
		a[n] = temp;
		temp = temp->next;
		n++;
	}
	a[n] = NULL;
	msort(0, n - 1, a, b, com2);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			*head = a[i];
		a[i]->next = a[i + 1];
	}
	free(a);
	free(b);
}