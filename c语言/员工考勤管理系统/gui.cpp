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
	InputBox(x, 20, a, "输入框");
	c=tft(x);
	return c;
}
char* box0(const char a[20])
{
	char x[20];
	InputBox(x, 20, a, "输入框");
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
		settextstyle(65, 0, "微软雅黑");
		outtextxy((900 - textwidth("屎山员工考勤管理系统")) / 2, 100,"屎山员工考勤管理系统");
		settextstyle(0, 0,"0");
		outtextxy(850, 500, "zcf");
		text(100, 350, 150, 40, "员工打卡");
		text(650, 350, 150, 40, "人事部登录");
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
		settextstyle(65, 0, "微软雅黑");
		outtextxy((900 - textwidth("请输入工号")) / 2, 60, "请输入工号");
		settextstyle(0, 0, "0");
		outtextxy(850, 500, "zcf");
		text(350, 300, 200, 50, "点击输入");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 350, 300, 200, 50))
		{
			InputBox(x,10,"请输入您的工号","输入框");
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
	MessageBox(hnd,a,"提示窗",MB_OKCANCEL);
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
		settextstyle(65, 0, "微软雅黑");
		outtextxy((900 - textwidth("请输入您的登录密码")) / 2, 120, "请输入您的登录密码");
		settextstyle(0, 0, "0");
		outtextxy(850, 500, "zcf");
		text(350, 300, 200, 50, "点击输入");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 350, 300, 200, 50))
		{
			InputBox(x, 20, "请输入您的密码", "输入框");
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
		settextstyle(65, 0, "微软雅黑");
		outtextxy((900 - textwidth(a)) / 2, 0, a);
		settextstyle(0, 0, "0");
		outtextxy(850, 500, "zcf");
		text(800, 450, 100, 50, "退出");
		text(200, 150, 200, 50, "删除员工");
		text(200, 210, 200, 50, "打卡信息");
		text(200, 270, 200, 50, "查询未打卡员工");
		text(200, 330, 200, 50, "排序(按打卡)");
		text(200, 390, 200, 50, "查看缺勤最多部门");
		text(200, 450, 200, 50, "标记缺勤员工");
		text(500, 150, 200, 50, "添加员工");
		text(500, 210, 200, 50, "查询员工");
		text(500, 270, 200, 50, "某部门打卡信息");
		text(500, 330, 200, 50, "排序(按缺勤)");
		text(500, 390, 200, 50, "考勤信息");
		text(500, 450, 200, 50, "结束今日打卡");
		text(800, 400, 100, 50, "注册");
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
		settextstyle(62, 0, "微软雅黑");
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID,3);
		for (int i = 0; i < 8; i++)
			line(100, 40 + i * 60, 800, 40 + i * 60);
		line(800, 40, 800, 460);
		line(100, 40, 100, 460);
		line(350, 40, 350, 460);
		outtextxy(150, 40, "姓名");
		outtextxy(350, 40, "打卡时间");
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
		text(0, 500, 100, 40, "返回");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return;
		}
		if (temp != NULL)
		{
			text(800, 500, 100, 40, "下一页");
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
		settextstyle(62, 0, "微软雅黑");
		res = information1(&temp, res);
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "返回");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return ;
		}
		if (temp != NULL)
		{
			text(800, 500, 100, 40, "下一页");
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
		settextstyle(62, 0, "微软雅黑");
		setlinecolor(BLACK);
		setlinestyle(PS_SOLID, 3);
		for (int i = 0; i < 8; i++)
			line(100, 40 + i * 60, 800, 40 + i * 60);
		line(800, 40, 800, 460);
		line(100, 40, 100, 460);
		line(350, 40, 350, 460);
		outtextxy(150, 40, "姓名");
		outtextxy(500, 40, "缺勤次数");
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
		text(0, 500, 100, 40, "返回");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return;
		}
		if (temp != NULL)
		{
			text(800, 500, 100, 40, "下一页");
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
		settextstyle(62, 0, "微软雅黑");
		res =tinormation1(&temp,a,res);
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "返回");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return;
		}
		if (temp != NULL)
		{
			text(800, 500, 100, 40, "下一页");
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
	char name[20] = {"空"};
	char department[20] = { "空" };
	char position[20] = { "空" };
	char age[10] = { "空" };
	while (1)
	{
		peekmessage(&msg, EX_MOUSE);
		BeginBatchDraw();
		cleardevice();
		setbkcolor(RGB(89, 227, 255));
		settextcolor(BLACK);
		settextstyle(62, 0, "微软雅黑");
		outtextxy(200, 120, "姓名:");
		outtextxy(200, 200, "年龄:");
		outtextxy(200, 280, "部门:");
		outtextxy(200, 360, "职业:");
		text(320, 130, 300, 50, name);
		text(320, 210, 300, 50, age);
		text(320, 290, 300, 50, department);
		text(320, 370, 300, 50, position);
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 130, 300, 50))
		{
			msg = { 0 };
			strcpy_s(name, 20, box0("请输入姓名"));
			strcpy_s(temp->name, 20, name);
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 210, 300, 50))
		{
			msg = { 0 };
			strcpy_s(age, 10, box0("请输入年龄"));
			temp->age = tft(age);
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 290, 300, 50))
		{
			msg = { 0 };
			strcpy_s(department, 20, box0("请输入部门"));
			strcpy_s(temp->department, 20, department);
			x = search(department);
			temp->cname = x;
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 370, 300, 50))
		{
			msg = { 0 };
			strcpy_s(position, 20, box0("请输入职位"));
			strcpy_s(temp->position, 20, position);
		}
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(800, 500, 100, 40, "确定");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 500, 100, 40))
		{
			msg = { 0 };
			if (!strcmp(name, "空") || !strcmp(age, "空") || !strcmp(department, "空") || !strcmp(position, "空"))
			{
				pop_up("无效信息!添加失败!!!");
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
		settextstyle(62, 0, "微软雅黑");
		outtextxy(200, 120, "姓名:");
		outtextxy(200, 200, "年龄:");
		outtextxy(200, 280, "部门:");
		outtextxy(200, 360, "职业:");
		text(320, 130, 300, 50,name);
		text(320, 210, 300, 50, age);
		text(320, 290, 300, 50, department);
		text(320, 370, 300, 50, position);
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 130, 300, 50))
		{
			msg = { 0 };
			strcpy_s(name,20,box0("请输入姓名"));
			strcpy_s(temp->name, 20, name);
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 210, 300, 50))
		{
			msg = { 0 };
			strcpy_s(age, 10, box0("请输入年龄"));
			temp->age = tft(age);
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 290, 300, 50))
		{
			msg = { 0 };
			strcpy_s(department, 20, box0("请输入部门"));
			strcpy_s(temp->department, 20, department);
			x = search(department);
			temp->cname = x;
		}
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 320, 370, 300, 50))
		{
			msg = { 0 };
			strcpy_s(position, 20, box0("请输入职位"));
			strcpy_s(temp->position, 20, position);
		}
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "返回");
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
	char u[20] = { "照片/hn.jpg" };
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
			settextstyle(62, 0, "微软雅黑");
			outtextxy((900 - textwidth("查无此人!")) / 2, 0, "查无此人");
			settextstyle(0, 0, "0");
			outtextxy(850, 0, "zcf");
			text(0, 500, 100, 40, "返回");
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
		settextstyle(62, 0, "微软雅黑");
		outtextxy((900 - textwidth("员工信息卡")) / 2, 0, "员工信息卡");
		sprintf_s(a1, 40, "工号:%d", temp->x);
		outtextxy(150,80, a1);
		sprintf_s(a1, 40, "姓名:%s", temp->name);
		outtextxy(150, 140, a1);
		sprintf_s(a1, 40, "年龄:%d", temp->age);
		outtextxy(150, 200, a1);
		sprintf_s(a1, 40, "部门:%s", temp->department);
		outtextxy(150, 260, a1);
		sprintf_s(a1, 40, "职位:%s", temp->position);
		outtextxy(150, 320, a1);
		sprintf_s(a1, 40, "缺勤次数:%d", temp->absent);
		outtextxy(150, 380, a1);
		settextstyle(0, 0, "0");
		outtextxy(850, 0, "zcf");
		text(0, 500, 100, 40, "返回");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 0, 500, 100, 40))
		{
			msg = { 0 };
			return;
		}
		if (temp->sum == 1)
		{
			text(800, 460, 100, 40, "拉黑");
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 460, 100, 40))
			{
				msg = { 0 };
				printf("该员工已被拉黑!\n");
				temp->sum = 0;
			}
		}
		else if (temp->sum == 0)
		{
			text(800, 460, 100, 40, "解除拉黑");
			if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 460, 100, 40))
			{
				msg = { 0 };
				printf("该员工已解除拉黑!\n");
				temp->sum = 1;
			}
		}
		text(800, 500, 100, 40, "修改信息");
		if (msg.message == WM_LBUTTONDOWN && inArea(msg.x, msg.y, 800, 500, 100, 40))
		{
			msg = { 0 };
			printf("修改信息中!\n");
			change_gui(temp);
			printf("工号:%d\n年龄:%d\n部门:%s\n姓名:%s\n职位:%s\n缺勤次数:%d次\n", temp->x, temp->age, temp->department, temp->name, temp->position, temp->absent);
			printf("修改完成!\n");
		}
		EndBatchDraw();
	}
}