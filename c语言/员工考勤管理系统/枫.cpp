#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<easyx.h>
#include"fun.h"
#include"sort.h"
#include"gui.h"
char gp1[20] = { "��Ƭ/z.jpg" };
int main()
{
	struct LL* head = NULL;
	int age,year, month, day, hour, minute,n=0,size=0,x, s,absent,cname,sum;
	char department[20],name[20],position[20],zhufu[100];
	char photo[20];
	initgraph(900, 540, EX_SHOWCONSOLE | EX_DBLCLKS);
	setbkmode(TRANSPARENT);
	FILE* fp;
	fopen_s(&fp, "./Ա����Ϣ.txt", "r");
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
		printf("Ա������Ϊ��!������һ��Ա��:\n");
		scanf_s("%d%d %s %s %s", &x, &age, department, 20, name, 20, position, 20);
		cname=search(department);
		shuru(&head,cname,x, department, age, name, position, 0, 0, 0, 0, 0,0,1,gp1);
	}
	back(&head,head);
	for (int j = 0;; j++)
	{
		printf("0.Ա����,1.���²���¼:\n");
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
			printf("������һ�ε�¼����!\n"), pop_up("������һ�ε�¼����!");
		if (login())
			break;
		x--;
		if (x == 0)
			goto w;
	}
	printf("��ӭ!\n"),pop_up("��ӭ!");
	blessing();
	for (int j = 0;; j++)
	{
		x = -1;
		printf("��ѡ�����:\n(0.ɾ��,1.���,2.�������Ϣ,3.��ѯԱ����Ϣ,4.��ѯ����δ��Ա��)\n");
		printf("(5.��ѯĳ���Ŵ����, 6.Ա������ʱ������, 7.Ա����ȱ�ڴ�������, 8.�鿴ȱ����ಿ��)\n");
		printf("(9.���������Ϣ,10.��Ƕ��ȱ��Ա��,11.�������մ�(δ����Աȱ�ڴ�����һ),12.���²�ע��):\n");
		strcpy_s(zhufu, 100, blessing0());
		x=HOI(zhufu);
		printf("%d\n", x);
		if (x == 0)
		{
			printf("����������ɾ����Ա���Ĺ���:\n");
			x = box("����������ɾ����Ա���Ĺ���:");
			printf("%d\n", x);
			delete1(&head,x);
			n--;
		}
		else if (x == 1)
		{
			printf("�������������\n");
			printf("����!!!��ΧΪ1-%d\n", n+1);
			s = n + 1;
			printf("%d\n", s);
			if (s == -1)
				break;
			if (s > n + 1 || s < 1)
			{
				printf("����!!!\n");
				break;
			}
			printf("������Ϣ\n");
			x=add1(&head,s);
			if (x == 1)
			{
				n++;
				printf("��ӳɹ�!\n");
			}
			else if (x == 0)
			{
				printf("���ʧ��!\n");
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
				printf("�ܰ�Ŷ!����Ա�����Ѵ�\n");
			else
				printf("δ������:%d\n", x);
		    information_gui(head,0);
		}
		else if (x == 5)
		{
			x=tinormation(head);
			if (x == 0)
				printf("�ܰ�Ŷ!�ò�������Ա�����Ѵ�!\n");
			else if(x!=-1)
				printf("�ò���δ������:%d\n", x);
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
			printf("�������ڳ������ٴ�δ�򿨵�Ա��?\n");
			x = box("�������ڳ������ٴ�δ�򿨵�Ա��?");
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
	w:fopen_s(&fp, "./Ա����Ϣ.txt", "w");
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
//д�����
//                    ��ף��
//              ��������˳��һ����˳
//���������ƺ����þ��ǳ��������ֵ�,��������ν��һ����˳��˵��
//               ��������������˵
//     ףԸ���ܹ�������Ŀ������в��ϳɳ����������ջ�