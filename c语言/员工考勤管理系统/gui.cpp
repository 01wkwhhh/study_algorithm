#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<easyx.h>
#include"fun.h"
ExMessage msg = { 0 };
int tft(const char x[10])
{
	int n=strlen(x);
	int c = n;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		if (48 > x[i] || x[i] > 57)
			return 0;
		sum += (x[i] - 48) * pow(10,c-1);
		c--;
	}
	return sum;
}
int inArea(int mx, int my, int x, int y, int w, int h)
{
	if (msg.x > x && msg.x<x + w && msg.y>y && msg.y < y + h)
		return 1;
	return 0;
}
void text(int x, int y, int w, int h, const char* text)
{
	setfillcolor(RGB(230, 231, 232));
	setlinestyle(0, 0);
	setlinecolor(BLACK);
	if (inArea(msg.x, msg.y, x, y, w, h))
	{
		setfillcolor(RGB(93, 107, 153));
	}
	fillroundrect(x, y, x + w, y + h, 5, 5);
	int hspace = (w - textwidth(text)) / 2;
	int vspace = (h - textheight(text)) / 2;
	settextcolor(BLACK);
	outtextxy(x + hspace, y + vspace, text);
}
int box(const char a[20])
{
	int c;
	char x[20];
	InputBox(x, 20, a, "�����");
	c=tft(x);
	return c;
}
char* box0(const char a[20])
{
	char x[20];
	InputBox(x, 20, a, "�����");
	return x;
}
int home()
{
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(65, 0, "΢���ź�");
		outtextxy((900 - textwidth("ʺɽԱ�����ڹ���ϵͳ")) / 2, 100,"ʺɽԱ�����ڹ���ϵͳ");
		settextstyle(0, 0,"0");
		outtextxy(850, 500, "zcf");
		text(100, 350, 150, 40, "Ա����");
		text(650, 350, 150, 40, "���²���¼");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 100, 350, 150, 40))
		{
			msg = { 0 };
			return 0;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 650, 350, 150, 40))
		{
			msg = { 0 };
			return 1;
		}
		EndBatchDraw();
	}
}
int ECI()
{
	int c;
	char x[10];
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(65, 0, "΢���ź�");
		outtextxy((900 - textwidth("�����빤��")) / 2, 60, "�����빤��");
		settextstyle(0, 0, "0");
		outtextxy(850, 500, "zcf");
		text(350, 300, 200, 50, "�������");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 350, 300, 200, 50))
		{
			InputBox(x,10,"���������Ĺ���","�����");
			c = tft(x);
			msg = { 0 };
			return c;
		}
		EndBatchDraw();
	}
}
void pop_up(const char a[80])
{
	HWND hnd = GetHWnd();
	MessageBox(hnd,a,"��ʾ��",MB_OKCANCEL);
	return;
}
char* sis()
{
	char x[20];
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(65, 0, "΢���ź�");
		outtextxy((900 - textwidth("���������ĵ�¼����")) / 2, 120, "���������ĵ�¼����");
		settextstyle(0, 0, "0");
		outtextxy(850, 500, "zcf");
		text(350, 300, 200, 50, "�������");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 350, 300, 200, 50))
		{
			InputBox(x, 20, "��������������", "�����");
			return x;
		}
		EndBatchDraw();
	}
}
int HOI(char a[100])
{
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(65, 0, "΢���ź�");
		outtextxy((900 - textwidth(a)) / 2, 0, a);
		settextstyle(0, 0, "0");
		outtextxy(850, 500, "zcf");
		text(800, 450, 100, 50, "�˳�");
		text(200, 150, 200, 50, "ɾ��Ա��");
		text(200, 210, 200, 50, "����Ϣ");
		text(200, 270, 200, 50, "��ѯδ��Ա��");
		text(200, 330, 200, 50, "����(����)");
		text(200, 390, 200, 50, "�鿴ȱ����ಿ��");
		text(200, 450, 200, 50, "���ȱ��Ա��");
		text(500, 150, 200, 50, "���Ա��");
		text(500, 210, 200, 50, "��ѯԱ��");
		text(500, 270, 200, 50, "ĳ���Ŵ���Ϣ");
		text(500, 330, 200, 50, "����(��ȱ��)");
		text(500, 390, 200, 50, "������Ϣ");
		text(500, 450, 200, 50, "�������մ�");
		text(800, 400, 100, 50, "ע��");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 450, 100, 50))
		{
			msg = { 0 };
			return -1;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 200, 150, 200, 50))
		{
			msg = { 0 };
			return 0;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 200, 210, 200, 50))
		{
			msg = { 0 };
			return 2;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 200, 270, 200, 50))
		{
			msg = { 0 };
			return 4;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 200, 330, 200, 50))
		{
			msg = { 0 };
			return 6;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 200, 390, 200, 50))
		{
			msg = { 0 };
			return 8;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 200, 450, 200, 50))
		{
			msg = { 0 };
			return 10;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 500, 150, 200, 50))
		{
			msg = { 0 };
			return 1;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 500, 210, 200, 50))
		{
			msg = { 0 };
			return 3;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 500, 270, 200, 50))
		{
			msg = { 0 };
			return 5;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 500, 330, 200, 50))
		{
			msg = { 0 };
			return 7;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 500, 390, 200, 50))
		{
			msg = { 0 };
			return 9;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 500, 450, 200, 50))
		{
			msg = { 0 };
			return 11;
		}
		else if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 400, 100, 50))
		{
			msg = { 0 };
			return 12;
		}
		EndBatchDraw();
	}
}
void table(struct LL* head)
{
	char a1[50];
	int n;
	struct LL* temp;
	while (1)
	{
		temp = head;
		n = 0;
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(62, 0, "΢���ź�");
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID,3);
		for (int i = 0; i < 8; i++)
			line(100, 40 + i * 60, 800, 40 + i * 60);
		line(800, 40, 800, 460);
		line(100, 40, 100, 460);
		line(350, 40, 350, 460);
		outtextxy(150, 40, "����");
		outtextxy(350, 40, "��ʱ��");
		setlinestyle(0, 0);
		while (temp!=NULL&&n < 6)
		{
			outtextxy(150, 160 + 60 * n - 60, temp->name);
			sprintf_s(a1, 50, "% d % d % d % d % d",temp->year, temp->month, temp->day, temp->hour, temp->minute);
			outtextxy(350, 160 + 60 * n - 50, a1);
			temp = temp->next;
			n++;
		}
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "����");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return;
		}
		if (temp != NULL)
		{
			text(800, 500, 100, 40, "��һҳ");
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 500, 100, 40))
			{
				msg = { 0 };
				table(temp);
			}
		}
		EndBatchDraw();
	}
}
void information_gui(struct LL* head,int res0)
{
	struct LL* temp = head;
	int res = res0;
	while (1)
	{
		temp = head;
		res = res0;
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(62, 0, "΢���ź�");
		res = information1(&temp, res);
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "����");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return ;
		}
		if (temp != NULL)
		{
			text(800, 500, 100, 40, "��һҳ");
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 500, 100, 40))
			{
				msg = { 0 };
				information_gui(temp,res);
			}
		}
		EndBatchDraw();
	}
}
void table1(struct LL* head)
{
	char a1[50];
	int n;
	struct LL* temp;
	while (1)
	{
		temp = head;
		n = 0;
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(62, 0, "΢���ź�");
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID, 3);
		for (int i = 0; i < 8; i++)
			line(100, 40 + i * 60, 800, 40 + i * 60);
		line(800, 40, 800, 460);
		line(100, 40, 100, 460);
		line(350, 40, 350, 460);
		outtextxy(150, 40, "����");
		outtextxy(500, 40, "ȱ�ڴ���");
		setlinestyle(0, 0);
		while (temp != NULL && n < 6)
		{
			outtextxy(150, 160 + 60 * n - 60, temp->name);
			sprintf_s(a1, 50, "%d", temp->absent);
			outtextxy(580, 160 + 60 * n - 50, a1);
			temp = temp->next;
			n++;
		}
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "����");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return;
		}
		if (temp != NULL)
		{
			text(800, 500, 100, 40, "��һҳ");
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 500, 100, 40))
			{
				msg = { 0 };
				table1(temp);
			}
		}
		EndBatchDraw();
	}
}
void tinormation1_gui(struct LL* head,int res0,char* a)
{
	struct LL* temp = head;
	int res = res0;
	while (1)
	{
		temp = head;
		res = res0;
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(62, 0, "΢���ź�");
		res =tinormation1(&temp,a,res);
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "����");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return;
		}
		if (temp != NULL)
		{
			text(800, 500, 100, 40, "��һҳ");
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 500, 100, 40))
			{
				msg = { 0 };
				tinormation1_gui(temp, 0, a);
			}
		}
		EndBatchDraw();
	}
}
int add_gui(struct LL* temp)
{
	int x;
	char name[20] = {"��"};
	char department[20] = { "��" };
	char position[20] = { "��" };
	char age[10] = { "��" };
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(62, 0, "΢���ź�");
		outtextxy(200, 120, "����:");
		outtextxy(200, 200, "����:");
		outtextxy(200, 280, "����:");
		outtextxy(200, 360, "ְҵ:");
		text(320, 130, 300, 50, name);
		text(320, 210, 300, 50, age);
		text(320, 290, 300, 50, department);
		text(320, 370, 300, 50, position);
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 130, 300, 50))
		{
			msg = { 0 };
			strcpy_s(name, 20, box0("����������"));
			strcpy_s(temp->name, 20, name);
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 210, 300, 50))
		{
			msg = { 0 };
			strcpy_s(age, 10, box0("����������"));
			temp->age = tft(age);
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 290, 300, 50))
		{
			msg = { 0 };
			strcpy_s(department, 20, box0("�����벿��"));
			strcpy_s(temp->department, 20, department);
			x = search(department);
			temp->cname = x;
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 370, 300, 50))
		{
			msg = { 0 };
			strcpy_s(position, 20, box0("������ְλ"));
			strcpy_s(temp->position, 20, position);
		}
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(800, 500, 100, 40, "ȷ��");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 500, 100, 40))
		{
			msg = { 0 };
			if (!strcmp(name, "��") || !strcmp(age, "��") || !strcmp(department, "��") || !strcmp(position, "��"))
			{
				pop_up("��Ч��Ϣ!���ʧ��!!!");
				return 0;
			}
			return 1;
		}
		EndBatchDraw();
	}
}
void change_gui(struct LL* temp)
{
	int x;
	char name[20];
	strcpy_s(name, 20, temp->name);
	char department[20];
	strcpy_s(department, 20, temp->department);
	char position[20];
	strcpy_s(position, 20, temp->position);
	char age[10];
	sprintf_s(age, 10, "%d", temp->age);
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(62, 0, "΢���ź�");
		outtextxy(200, 120, "����:");
		outtextxy(200, 200, "����:");
		outtextxy(200, 280, "����:");
		outtextxy(200, 360, "ְҵ:");
		text(320, 130, 300, 50,name);
		text(320, 210, 300, 50, age);
		text(320, 290, 300, 50, department);
		text(320, 370, 300, 50, position);
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 130, 300, 50))
		{
			msg = { 0 };
			strcpy_s(name,20,box0("����������"));
			strcpy_s(temp->name, 20, name);
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 210, 300, 50))
		{
			msg = { 0 };
			strcpy_s(age, 10, box0("����������"));
			temp->age = tft(age);
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 290, 300, 50))
		{
			msg = { 0 };
			strcpy_s(department, 20, box0("�����벿��"));
			strcpy_s(temp->department, 20, department);
			x = search(department);
			temp->cname = x;
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 370, 300, 50))
		{
			msg = { 0 };
			strcpy_s(position, 20, box0("������ְλ"));
			strcpy_s(temp->position, 20, position);
		}
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "����");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return;
		}
		EndBatchDraw();
	}
}
void search_gui(struct LL* temp)
{
	char a1[40];
	IMAGE a;
	char u[20] = { "��Ƭ/hn.jpg" };
	if(temp!=NULL)
	strcpy_s(u, 20, temp->photo);
	if (temp == NULL)
	{
		while (1)
		{
			peekmessage(&msg, EX_MOUSE);
			BeginBatchDraw();
			cleardevice();
			setbkcolor(RGB(89, 227, 255));
			settextcolor(BLACK);
			settextstyle(62, 0, "΢���ź�");
			outtextxy((900 - textwidth("���޴���!")) / 2, 0, "���޴���");
			settextstyle(0, 0, "0");
			outtextxy(850, 0, "zcf");
			text(0, 500, 100, 40, "����");
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
			{
				msg = { 0 };
				return;
			}
			EndBatchDraw();
		}
	}
	else
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		loadimage(&a, u, 153, 201);
		putimage(580, 80, &a);
		settextcolor(BLACK);
		settextstyle(62, 0, "΢���ź�");
		outtextxy((900 - textwidth("Ա����Ϣ��")) / 2, 0, "Ա����Ϣ��");
		sprintf_s(a1, 40, "����:%d", temp->x);
		outtextxy(150,80, a1);
		sprintf_s(a1, 40, "����:%s", temp->name);
		outtextxy(150, 140, a1);
		sprintf_s(a1, 40, "����:%d", temp->age);
		outtextxy(150, 200, a1);
		sprintf_s(a1, 40, "����:%s", temp->department);
		outtextxy(150, 260, a1);
		sprintf_s(a1, 40, "ְλ:%s", temp->position);
		outtextxy(150, 320, a1);
		sprintf_s(a1, 40, "ȱ�ڴ���:%d", temp->absent);
		outtextxy(150, 380, a1);
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "����");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return;
		}
		if (temp->sum == 1)
		{
			text(800, 460, 100, 40, "����");
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 460, 100, 40))
			{
				msg = { 0 };
				printf("��Ա���ѱ�����!\n");
				temp->sum = 0;
			}
		}
		else if (temp->sum == 0)
		{
			text(800, 460, 100, 40, "�������");
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 460, 100, 40))
			{
				msg = { 0 };
				printf("��Ա���ѽ������!\n");
				temp->sum = 1;
			}
		}
		text(800, 500, 100, 40, "�޸���Ϣ");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 500, 100, 40))
		{
			msg = { 0 };
			printf("�޸���Ϣ��!\n");
			change_gui(temp);
			printf("����:%d\n����:%d\n����:%s\n����:%s\nְλ:%s\nȱ�ڴ���:%d��\n", temp->x, temp->age, temp->department, temp->name, temp->position, temp->absent);
			printf("�޸����!\n");
		}
		EndBatchDraw();
	}
}