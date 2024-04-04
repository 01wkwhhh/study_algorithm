#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<easyx.h>
#include"fun.h"
#include"sort.h"
#include"gui.h"
char gp1[20] = { "照片/z.jpg" };
int main()
{
	struct LL* head = NULL;
	int age,year, month, day, hour, minute,n=0,size=0,x, s,absent,cname,sum;
	char department[20],name[20],position[20],zhufu[100];
	char photo[20];
	initgraph(900, 540, EX_SHOWCONSOLE | EX_DBLCLKS);
	setbkmode(TRANSPARENT);
	FILE* fp;
	fopen_s(&fp, "./员工信息.txt", "r");
	if (fp == NULL)
	{
		perror("open file failed");
		exit(-1);
	}
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);
	if(size!=0)
	while(!feof(fp))
	{
		fscanf_s(fp,"%d %d %d %s %s %s %d %d %d %d %d %d %d %s",&cname, &x, &age, department,20,name,20,position,20,&year,&month,&day,&hour,&minute,&absent,&sum,photo,20);
		shuru(&head,cname,x, department, age, name, position, year, month, day, hour, minute,absent,sum,photo);
		n++;
	}
	fclose(fp);
	if (head == NULL)
	{
		printf("员工不能为空!请输入一个员工:\n");
		scanf_s("%d%d %s %s %s", &x, &age, department, 20, name, 20, position, 20);
		cname=search(department);
		shuru(&head,cname,x, department, age, name, position, 0, 0, 0, 0, 0,0,1,gp1);
	}
	back(&head,head);
	for (int j = 0;; j++)
	{
		printf("0.员工打卡,1.人事部登录:\n");
		x = home();
		printf("%d\n", x);
		if (x == 0)
		{
			punch_in(&head);
		}
		else if (x == 1)
			break;
		else
			break;
	}
	x = 3;
	for (int j = 0;; j++)
	{
		if (x == 1)
			printf("您还有一次登录机会!\n"), pop_up("您还有一次登录机会!");
		if (login())
			break;
		x--;
		if (x == 0)
			goto w;
	}
	printf("欢迎!\n"),pop_up("欢迎!");
	blessing();
	for (int j = 0;; j++)
	{
		x = -1;
		printf("请选择操作:\n(0.删除,1.添加,2.输出打卡信息,3.查询员工信息,4.查询今日未打卡员工)\n");
		printf("(5.查询某部门打卡情况, 6.员工按打卡时间排序, 7.员工按缺勤次数排序, 8.查看缺勤最多部门)\n");
		printf("(9.输出考勤信息,10.标记多次缺勤员工,11.结束今日打卡(未打卡人员缺勤次数加一),12.人事部注册):\n");
		strcpy_s(zhufu, 100, blessing0());
		x=HOI(zhufu);
		printf("%d\n", x);
		if (x == 0)
		{
			printf("请输入您想删除的员工的工号:\n");
			x = box("请输入您想删除的员工的工号:");
			printf("%d\n", x);
			delete1(&head,x);
			n--;
		}
		else if (x == 1)
		{
			printf("你想在哪里插入\n");
			printf("警告!!!范围为1-%d\n", n+1);
			s = n + 1;
			printf("%d\n", s);
			if (s == -1)
				break;
			if (s > n + 1 || s < 1)
			{
				printf("错误!!!\n");
				break;
			}
			printf("输入信息\n");
			x=add1(&head,s);
			if (x == 1)
			{
				n++;
				printf("添加成功!\n");
			}
			else if (x == 0)
			{
				printf("添加失败!\n");
			}
		}
		else if (x == 2)
		{
			pii(&head);
			table(head);
		}
		else if (x == 3)
		{
			outup(head);
		}
		else if (x == 4)
		{
			x = information(&head);
			if (x == 0)
				printf("很棒哦!所有员工均已打卡\n");
			else
				printf("未打卡人数:%d\n", x);
		    information_gui(head,0);
		}
		else if (x == 5)
		{
			x=tinormation(head);
			if (x == 0)
				printf("很棒哦!该部门所有员工均已打卡!\n");
			else if(x!=-1)
				printf("该部门未打卡人数:%d\n", x);
		}
		else if (x == 6)
		{
			t_msort(&head);
			print(&head);
			table(head);
		}
		else if (x == 7)
		{
			a_msort(&head);
			print(&head);
			table1(head);
		}
		else if (x == 8)
		{
			statistics(head);
		}
		else if (x==9)
		{
			input(head);
			table1(head);
		}
		else if (x==10)
		{
			printf("您想拉黑超过多少次未打卡的员工?\n");
			x = box("您想拉黑超过多少次未打卡的员工?");
			printf("%d\n", x);
			block(head, x);
		}
		else if (x == 11)
		{
			end(head);
		}
		else if (x == 12)
		{
			sign_up();
		}
		else
			break;
	}
	set_up(&head);
	w:fopen_s(&fp, "./员工信息.txt", "w");
	if (fp == NULL)
	{
		perror("open file failed");
		exit(-1);
	}
	struct LL* temp = head;
	while (temp != NULL)
	{
		if (temp->next == NULL)
			fprintf(fp, "%d %d %d %s %s %s %d %d %d %d %d %d %d %s",temp->cname, temp->x, temp->age, temp->department, temp->name, temp->position, temp->year, temp->month, temp->day, temp->hour, temp->minute,temp->absent,temp->sum,temp->photo);
		else
			fprintf(fp, "%d %d %d %s %s %s %d %d %d %d %d %d %d %s\n",temp->cname, temp->x, temp->age, temp->department, temp->name, temp->position, temp->year, temp->month, temp->day, temp->hour, temp->minute,temp->absent,temp->sum,temp->photo);
		temp = temp->next;
	}
	fclose(fp);
	release(head);
}
//写在最后
//                    想祝你
//              生活事事顺意一帆风顺
//可是生活似乎本该就是充满苦与乐的,不存在所谓的一帆风顺的说法
//               所以最后我想对你说
//     祝愿你能够在生活的苦与乐中不断成长不断有所收获