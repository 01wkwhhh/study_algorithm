#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<easyx.h>
#include"fun.h"
#include"gui.h"
char gp[20] = {"照片/z.jpg"};
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
		printf("查无此人!\n"),pop_up("查无此人!");
		return;
	}
	temp = *head;
	if (n == 1)
	{
		*head = temp->next;
		free(temp);
		printf("删除成功!\n"),pop_up("删除成功!");
		return;
	}
	for (int i = 0; i < n - 2; i++)
		temp = temp->next;
	struct LL* temp1 = temp->next;
	temp->next = temp->next->next;
	free(temp1);
	printf("删除成功!\n"),pop_up("删除成功!");
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
	printf("工号为:%d\n", temp1->x);
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
	char a[20] = { "我" },b[20];
	b[19] = '\0';
	printf("请输入登录密码:\n");
	strcpy_s(b, 20, sis());
	printf("%s\n", b);
	if (!strcmp(b, a))
		return 1;
	FILE* fp;
	fopen_s(&fp, "./人事密码.txt", "r");
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
	printf("请输入打卡员工:\n");
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
				printf("员工%s你好!由于您多次未打卡,已被管理员拉黑!请联系管理员解决!!!\n",temp1->name);
				sprintf_s(a1,80,"员工%s你好!由于您多次未打卡,\n已被管理员拉黑!请联系管理员解决!!!", temp1->name);
				pop_up(a1);
				return;
			}
			temp1->year = local_time.tm_year + 1900;
			temp1->month = local_time.tm_mon + 1;
			temp1->day = local_time.tm_mday;
			temp1->hour = local_time.tm_hour;
			temp1->minute = local_time.tm_min;
			printf("员工%s打卡成功:%d %d %d %d %d\n", temp1->name, local_time.tm_year + 1900, local_time.tm_mon + 1, local_time.tm_mday, local_time.tm_hour, local_time.tm_min);
			sprintf_s(a1,80,"员工%s打卡成功:%d %d %d %d %d\n", temp1->name, local_time.tm_year + 1900, local_time.tm_mon + 1, local_time.tm_mday, local_time.tm_hour, local_time.tm_min);
			pop_up(a1);
			break;
		}
		else
			temp1 = temp1->next;
	}
	if (temp1 == NULL)
		printf("未找到该员工!\n"),pop_up("未找到该员工!");
	return;
}
void sign_up()
{
	FILE* fp;
	char a[20];
	printf("请输入您的登录密码:\n");
	strcpy_s(a, 20, box0("请输入您的登录密码:"));
	printf("%s\n", a);
	fopen_s(&fp, "./人事密码.txt", "at");
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
			sprintf_s(a1, 50, "员工%s未打卡!", temp->name);
			outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * res - 50, a1);
		}
			temp = temp->next;
	}
	if (temp == NULL && res0 != 0)
	{
		sprintf_s(a1, 50, "未打卡人数:%d", res0);
		outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * (res+1) - 50, a1);
	}
	else if (temp == NULL && res0 == 0)
	{
		outtextxy((900 - textwidth("所有员工均已打卡!")) / 2, 40 + 60 * (res+1) - 50, "所有员工均已打卡!");
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
	printf("请输入您想查询的部门名字:\n");
	strcpy_s(a, 20, box0("请输入您想查询的部门名字:"));
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
			printf("%s员工%s未打卡!\n", a,temp->name),res++;
		temp = temp->next;
	}
	tinormation1_gui(head, 0, a);
	if (d == 0)
	{
		printf("没有%s\n", a);
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
	fopen_s(&fp, "./部门信息.txt", "r");
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
	fopen_s(&fp, "./部门信息.txt", "at");
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
		printf("很棒哦!无缺勤人员^-^\n"),pop_up("很棒哦!无缺勤人员^-^");
	else
	{
		FILE* fp;
		fopen_s(&fp, "./部门信息.txt", "r");
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
				printf("%s缺勤次数为%d次!\n", b[i], a[i]);
				sprintf_s(a1, 40, "%s缺勤次数为%d次!", b[i],a[i]);
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
		printf("员工%s缺勤次数为%d次!\n", temp->name, temp->absent);
		temp = temp->next;
	}
}
void outup(struct LL* temp)
{
	int x;
	char a[20];
	a[19] = '\0';
	printf("请输入想要查询的员工的员工工号:\n");
	x = box("请输入想要查询的员工的员工工号:");
	printf("%d\n", x);
	while (temp != NULL)
	{
		if (temp->x == x)
		{
			printf("工号:%d\n年龄:%d\n部门:%s\n姓名:%s\n职位:%s\n缺勤次数:%d次\n", temp->x, temp->age, temp->department, temp->name, temp->position,temp->absent);
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
	printf("操作完成!\n"),pop_up("操作完成!");
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
	printf("今日打卡情况已登记完毕!\n望管理员悉知!!!(切勿重复操作!!!)\n");
	pop_up("   今日打卡情况已登记完毕!\n望管理员悉知!!!(切勿重复操作!!!)");
	return;
}
void blessing()
{
	time_t time1;
	struct tm local_time;
	time1 = time(NULL);
	localtime_s(&local_time, &time1);
	if (local_time.tm_hour >= 6 && local_time.tm_hour < 12)
		printf("早上好!美好的一天开始啦!!!^_^\n");
	else if (local_time.tm_hour >= 12 && local_time.tm_hour < 18)
		printf("中午好!记得午休哦!owo\n");
	else if (local_time.tm_hour >= 18 && local_time.tm_hour < 22)
		printf("下午好!愉快的一天快要结束喽!qwq\n");
	else if ((local_time.tm_hour >= 22 && local_time.tm_hour <= 24)||(local_time.tm_hour >= 0 && local_time.tm_hour < 6))
		printf("晚上好!夜深啦!早点休息哦!=w=\n");
	return;
		
}
char* blessing0()
{
	char a[4][100] = { {"早上好!美好的一天开始啦!!!^_^"} ,{"中午好!记得午休哦!owo"} ,{"下午好!愉快的一天快要结束喽!qwq"} ,{"晚上好!夜深啦!早点休息哦 != w = "}};
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
			printf("员工%s未打卡!\n", temp->name), res++;
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
			sprintf_s(a1, 40, "%s员工%s未打卡!",a, temp->name);
			outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * res - 50, a1);
		}
		temp = temp->next;
	}
	if (d == 0)
	{
		sprintf_s(a1,40,"没有%s", a);
		outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * (res+1) - 50, a1);
		*head = NULL;
		return -1;
	}
	if (temp == NULL && res0 != 0)
	{
		sprintf_s(a1, 40, "该部门未打卡人数:%d", res0);
		outtextxy((900 - textwidth(a1)) / 2, 40 + 60 * (res + 1) - 50, a1);
	}
	else if (temp == NULL && res0 == 0)
	{
		outtextxy((900 - textwidth("很棒哦!该部门所有员工均已打卡!")) / 2, 40 + 60 * (res + 1) - 50, "很棒哦!该部门所有员工均已打卡!");
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