#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<easyx.h>
#include"fun.h"
#include"gui.h"
char gp[20] = {"��Ƭ/z.jpg"};
void shuru(struct LL** head,int cname, int x, char department[20], int age, char name[20], char position[20], int year, int month, int day, int hour, int minute,int absent,int sum,char photo[20])
{
	struct LL* temp = (struct LL*)malloc(sizeof(struct LL));
	if (temp == NULL)
		exit(-1);
	temp->age = age, temp->x = x, temp->year = year, temp->month = month, temp->day = day, temp->hour = hour, temp->minute = minute,temp->absent=absent;
	temp->sum = 0,temp->cname=cname,temp->sum=sum;
	strcpy_s(temp->photo, 20, photo);
	strcpy_s(temp->name, 20, name);
	strcpy_s(temp->department, 20, department);
	strcpy_s(temp->position, 20, position);
	temp->next = *head;
	*head = temp;
}
void back(struct LL** head, struct LL* temp)
{
	if (temp->next != NULL)
		back(head, temp->next);
	else
	{
		*head = temp;
		return;
	}
	temp->next->next = temp;
	temp->next = NULL;
	return;
}
void delete1(struct LL** head, int x)
{
	int n = 1;
	struct LL* temp = *head;
	while (temp!=NULL&&temp->x!=x)
	{
		n++;
		temp = temp->next;
	}
	if (temp == NULL)
	{
		printf("���޴���!\n"),pop_up("���޴���!");
		return;
	}
	temp = *head;
	if (n == 1)
	{
		*head = temp->next;
		free(temp);
		printf("ɾ���ɹ�!\n"),pop_up("ɾ���ɹ�!");
		return;
	}
	for (int i = 0; i < n - 2; i++)
		temp = temp->next;
	struct LL* temp1 = temp->next;
	temp->next = temp->next->next;
	free(temp1);
	printf("ɾ���ɹ�!\n"),pop_up("ɾ���ɹ�!");
	return;
}
int add1(struct LL** head, int s)
{
	int cname;
	struct LL* temp = *head;
	struct LL* temp1 = (struct LL*)malloc(sizeof(struct LL));
	if (temp1 == NULL)
		exit(-1);
	temp1->year = 0, temp1->month = 0, temp1->day = 0, temp1->hour = 0, temp1->minute = 0,temp1->absent=0;
	temp1->sum = 1;
	temp1->x = search0(*head);
	printf("����Ϊ:%d\n", temp1->x);
	cname=add_gui(temp1);
	if (cname == 0)
	{
		free(temp1);
		return 0;
	}
	strcpy_s(temp1->photo, 20, gp);
	if (s == 1)
	{
		temp1->next = temp;
		*head = temp1;
		return 1;
	}
	for (int i = 0; i < s - 2; i++)
		temp = temp->next;
	temp1->next = temp->next;
	temp->next = temp1;
	return 1;
}
void print(struct LL** head)
{
	struct LL* temp = *head;
	while (temp != NULL)
	{
		printf("%d %d %s %s %s\n", temp->x, temp->age, temp->department, temp->name, temp->position);
		temp = temp->next;
	}
}
void release(struct LL* temp)
{
	if (temp->next != NULL)
		release(temp->next);
	free(temp);
	return;
}
void pii(struct LL** head)
{
	struct LL* temp = *head;
	while (temp != NULL)
	{
		printf("%s %d %d %d %d %d\n", temp->name, temp->year, temp->month, temp->day, temp->hour, temp->minute);
		temp = temp->next;
	}
}
int login()
{
	char a[20] = { "��" },b[20];
	b[19] = '\0';
	printf("�������¼����:\n");
	strcpy_s(b, 20, sis());
	printf("%s\n", b);
	if (!strcmp(b, a))
		return 1;
	FILE* fp;
	fopen_s(&fp, "./��������.txt", "r");
	if (fp == NULL)
	{
		perror("open file failed");
		exit(-1);
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	rewind(fp);
	if (size != 0)
		while (!feof(fp))
		{
			fscanf_s(fp, "%s", a, 20);
			if (!strcmp(a, b))
			{
				fclose(fp); 
				return 1;
			}
		}
	fclose(fp);
	return 0;
}
void punch_in(struct LL** head)
{
	int x;
	struct tm local_time;
	char a1[80];
	printf("�������Ա��:\n");
	x = ECI();
	printf("%d\n", x);
	time_t time1;
	time1 = time(NULL);
	localtime_s(&local_time, &time1);
	struct LL* temp1 = *head;
	while (temp1 != NULL)
	{
		if (temp1->x == x)
		{
			if (temp1->sum == 0)
			{
				printf("Ա��%s���!���������δ��,�ѱ�����Ա����!����ϵ����Ա���!!!\n",temp1->name);
				sprintf_s(a1,80,"Ա��%s���!���������δ��,\n�ѱ�����Ա����!����ϵ����Ա���!!!", temp1->name);
				pop_up(a1);
				return;
			}
			temp1->year = local_time.tm_year + 1900;
			temp1->month = local_time.tm_mon + 1;
			temp1->day = local_time.tm_mday;
			temp1->hour = local_time.tm_hour;
			temp1->minute = local_time.tm_min;
			printf("Ա��%s�򿨳ɹ�:%d %d %d %d %d\n", temp1->name, local_time.tm_year + 1900, local_time.tm_mon + 1, local_time.tm_mday, local_time.tm_hour, local_time.tm_min);
			sprintf_s(a1,80,"Ա��%s�򿨳ɹ�:%d %d %d %d %d\n", temp1->name, local_time.tm_year + 1900, local_time.tm_mon + 1, local_time.tm_mday, local_time.tm_hour, local_time.tm_min);
			pop_up(a1);
			break;
		}
		else
			temp1 = temp1->next;
	}
	if (temp1 == NULL)
		printf("δ�ҵ���Ա��!\n"),pop_up("δ�ҵ���Ա��!");
	return;
}
void sign_up()
{
	FILE* fp;
	char a[20];
	printf("���������ĵ�¼����:\n");
	strcpy_s(a, 20, box0("���������ĵ�¼����:"));
	printf("%s\n", a);
	fopen_s(&fp, "./��������.txt", "at");
	if (fp == NULL)
	{
		perror("open file failed");
		exit(-1);
	}
	fprintf(fp, "\n%s", a);
	fclose(fp);
	return;
}
int information1(struct LL** head,int res0)
{
	int res=0;
	char a1[50];
	struct LL* temp = *head;
	time_t time1;
	struct tm local_time;
	time1 = time(NULL);
	localtime_s(&local_time, &time1);
	while (temp != NULL&&res<6)
	{
		if (temp->year != local_time.tm_year + 1900 || temp->month != local_time.tm_mon + 1 || temp->day != local_time.tm_mday)
		{
			res++, res0++;
			sprintf_s(a1, 50, "Ա��%sδ��!", temp->name);
			outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * res - 50, a1);
		}
			temp = temp->next;
	}
	if (temp == NULL && res0 != 0)
	{
		sprintf_s(a1, 50, "δ������:%d", res0);
		outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * (res+1) - 50, a1);
	}
	else if (temp == NULL && res0 == 0)
	{
		outtextxy((900 - textwidth("����Ա�����Ѵ�!")) / 2, 40 + 60 * (res+1) - 50, "����Ա�����Ѵ�!");
	}
	*head = temp;
	return res0;
}
int tinormation(struct LL* head)
{
	char a[20];
	a[19] = '\0';
	int res=0;
	int d = 0;
	struct LL* temp = head;
	printf("�����������ѯ�Ĳ�������:\n");
	strcpy_s(a, 20, box0("�����������ѯ�Ĳ�������:"));
	printf("%s\n", a);
	time_t time1;
	struct tm local_time;
	time1 = time(NULL);
	localtime_s(&local_time, &time1);
	while (temp != NULL)
	{
		if (!strcmp(temp->department, a))
			d = 1;
		if (!strcmp(temp->department,a)&&(temp->year != local_time.tm_year + 1900 || temp->month != local_time.tm_mon + 1 || temp->day != local_time.tm_mday))
			printf("%sԱ��%sδ��!\n", a,temp->name),res++;
		temp = temp->next;
	}
	tinormation1_gui(head, 0, a);
	if (d == 0)
	{
		printf("û��%s\n", a);
		return -1;
	}
	return res;
}
int search(char epartment[20])
{
	int x=0;
	char a[20];
	a[19] = '\0';
	FILE* fp;
	fopen_s(&fp, "./������Ϣ.txt", "r");
	if (fp == NULL)
	{
		perror("open file failed");
		exit(-1);
	}
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	rewind(fp);
	if (size != 0)
		while (!feof(fp))
		{
			fscanf_s(fp, "%d %s",&x, a, 20);
			if (!strcmp(a, epartment))
			{
				fclose(fp);
				return x;
			}
		}
	fclose(fp);
	fopen_s(&fp, "./������Ϣ.txt", "at");
	if (fp == NULL)
	{
		perror("open file failed");
		exit(-1);
	}
	fprintf(fp, "\n%d %s",++x, epartment);
	fclose(fp);
	return x;
}
void statistics(struct LL* temp)
{
	int a[20];
	char b[20][20],c[20];
	char a1[40];
	c[19] = '\0';
	int x=0,s;
	for (int i = 0; i < 20; i++)
		a[i] = 0;
	while (temp != NULL)
	{
		a[temp->cname] += temp->absent;
		temp = temp->next;
	}
	for (int i = 0; i < 20; i++)
	{
		if (a[i] > a[x])
			x = i;
	}
	if (a[x] == 0)
		printf("�ܰ�Ŷ!��ȱ����Ա^-^\n"),pop_up("�ܰ�Ŷ!��ȱ����Ա^-^");
	else
	{
		FILE* fp;
		fopen_s(&fp, "./������Ϣ.txt", "r");
		if (fp == NULL)
		{
			perror("open file failed");
			exit(-1);
		}
	    while (!feof(fp))
	    {
			fscanf_s(fp, "%d %s", &s, c, 20);
			strcpy_s(b[s], 20, c);
	    }
		fclose(fp);
		for (int i = 0; i < 20; i++)
		{
			if (a[i] == a[x])
			{
				printf("%sȱ�ڴ���Ϊ%d��!\n", b[i], a[i]);
				sprintf_s(a1, 40, "%sȱ�ڴ���Ϊ%d��!", b[i],a[i]);
				pop_up(a1);
			}
		}
	}
	return;
}
void input(struct LL* temp)
{
	while (temp != NULL)
	{
		printf("Ա��%sȱ�ڴ���Ϊ%d��!\n", temp->name, temp->absent);
		temp = temp->next;
	}
}
void outup(struct LL* temp)
{
	int x;
	char a[20];
	a[19] = '\0';
	printf("��������Ҫ��ѯ��Ա����Ա������:\n");
	x = box("��������Ҫ��ѯ��Ա����Ա������:");
	printf("%d\n", x);
	while (temp != NULL)
	{
		if (temp->x == x)
		{
			printf("����:%d\n����:%d\n����:%s\n����:%s\nְλ:%s\nȱ�ڴ���:%d��\n", temp->x, temp->age, temp->department, temp->name, temp->position,temp->absent);
			break;
		}
		temp = temp->next;
	}
	search_gui(temp);
}
void block(struct LL* temp,int x)
{
	while (temp != NULL)
	{
		if (temp->absent>=x)
			temp->sum = 0;
		else
			temp->sum = 1;
		temp = temp->next;
	}
	printf("�������!\n"),pop_up("�������!");
	return;
}
void end(struct LL* temp)
{
	time_t time1;
	struct tm local_time;
	time1 = time(NULL);
	localtime_s(&local_time, &time1);
	while (temp != NULL)
	{
		if (temp->year != local_time.tm_year + 1900 || temp->month != local_time.tm_mon + 1 || temp->day != local_time.tm_mday)
			temp->absent++;
		temp = temp->next;
	}
	printf("���մ�����ѵǼ����!\n������ԱϤ֪!!!(�����ظ�����!!!)\n");
	pop_up("   ���մ�����ѵǼ����!\n������ԱϤ֪!!!(�����ظ�����!!!)");
	return;
}
void blessing()
{
	time_t time1;
	struct tm local_time;
	time1 = time(NULL);
	localtime_s(&local_time, &time1);
	if (local_time.tm_hour >= 6 && local_time.tm_hour < 12)
		printf("���Ϻ�!���õ�һ�쿪ʼ��!!!^_^\n");
	else if (local_time.tm_hour >= 12 && local_time.tm_hour < 18)
		printf("�����!�ǵ�����Ŷ!owo\n");
	else if (local_time.tm_hour >= 18 && local_time.tm_hour < 22)
		printf("�����!����һ���Ҫ�����!qwq\n");
	else if ((local_time.tm_hour >= 22 && local_time.tm_hour <= 24)||(local_time.tm_hour >= 0 && local_time.tm_hour < 6))
		printf("���Ϻ�!ҹ����!�����ϢŶ!=w=\n");
	return;
		
}
char* blessing0()
{
	char a[4][100] = { {"���Ϻ�!���õ�һ�쿪ʼ��!!!^_^"} ,{"�����!�ǵ�����Ŷ!owo"} ,{"�����!����һ���Ҫ�����!qwq"} ,{"���Ϻ�!ҹ����!�����ϢŶ != w = "}};
	time_t time1;
	struct tm local_time;
	time1 = time(NULL);
	localtime_s(&local_time, &time1);
	if (local_time.tm_hour >= 6 && local_time.tm_hour < 12)
		return a[0];
	else if (local_time.tm_hour >= 12 && local_time.tm_hour < 18)
		return a[1];
	else if (local_time.tm_hour >= 18 && local_time.tm_hour < 22)
		return a[2];
	else if ((local_time.tm_hour >= 22 && local_time.tm_hour <= 24) || (local_time.tm_hour >= 0 && local_time.tm_hour < 6))
		return a[3];
}
int information(struct LL** head)
{
	int res = 0;
	struct LL* temp = *head;
	time_t time1;
	struct tm local_time;
	time1 = time(NULL);
	localtime_s(&local_time, &time1);
	while (temp != NULL)
	{
		if (temp->year != local_time.tm_year + 1900 || temp->month != local_time.tm_mon + 1 || temp->day != local_time.tm_mday)
			printf("Ա��%sδ��!\n", temp->name), res++;
		temp = temp->next;
	}
	return res;
}
int tinormation1(struct LL** head,char* a,int res0)
{
	int res = 0;
	int d = 0;
	char a1[40];
	struct LL* temp = *head;
	time_t time1;
	struct tm local_time;
	time1 = time(NULL);
	localtime_s(&local_time, &time1);
	while (temp != NULL)
	{
		if (!strcmp(temp->department, a))
			d = 1;
		if (!strcmp(temp->department, a) && (temp->year != local_time.tm_year + 1900 || temp->month != local_time.tm_mon + 1 || temp->day != local_time.tm_mday))
		{
			res++;
			res0++;
			sprintf_s(a1, 40, "%sԱ��%sδ��!",a, temp->name);
			outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * res - 50, a1);
		}
		temp = temp->next;
	}
	if (d == 0)
	{
		sprintf_s(a1,40,"û��%s", a);
		outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * (res+1) - 50, a1);
		*head = NULL;
		return -1;
	}
	if (temp == NULL && res0 != 0)
	{
		sprintf_s(a1, 40, "�ò���δ������:%d", res0);
		outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * (res + 1) - 50, a1);
	}
	else if (temp == NULL && res0 == 0)
	{
		outtextxy((900 - textwidth("�ܰ�Ŷ!�ò�������Ա�����Ѵ�!")) / 2, 40 + 60 * (res + 1) - 50, "�ܰ�Ŷ!�ò�������Ա�����Ѵ�!");
	}
	*head = temp;
	return res;
}
int mycom(const void* A,const void* B)
{
	int a = *((int*)A);
	int b = *((int*)B);
	return a - b;
}
int search0(struct LL* head)
{
	struct LL* temp=head;
	int a[100];
	int n = 1;
	while (temp != NULL)
	{
		a[n] = temp->x;
		n++;
		temp = temp->next;
	}
	qsort(a + 1, n-1, sizeof(int), mycom);
	for (int i = 1; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
	for (int i = 1; i < n; i++)
		if (a[i] != i)
			return i;
	return n;
}