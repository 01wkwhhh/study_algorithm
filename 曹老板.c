/*笔记代码*/
//字符数组指针传递给函数以及不可修改;
/*#include<stdio.h>
void print(const char* c)
{
	while (*c != 0)
	{
		printf("%c", *c++);
	}
}
void main()
{
	char c[20] = "Hello world!";
	print(c);
}*/
//字符数组（非完全意义）的指针定义以及指针输出;
/*#include<stdio.h>
void main()
{
	char* c = "rip_hs";//不可修改
	for (int i = 5; i >= 0; i--)
		printf("%c", c[i]);
}*/
//指向数组的指针运用;
/*#include<stdio.h>
void main()
{
	int a[4][8] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	int (*p)[8];
	int* q;
	for (p = a; p < a + 4; p++)
	{
		for (q = *p; q < *p + 8; q++)
			printf("%3d", *q);
		printf("\n");
	}
}*/
//多维数组及其指针运用;
/*#include<stdio.h>
void main()
{
	int a[2][4][4] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32 };
	int(*w)[4][4];
	int(*p)[4];
	int* q;
	for (w = a; w < a + 2; w++)
	{
		for (p = *w; p < *w + 4; p++)
		{
			for (q = *p; q < *p + 4; q++)
				printf("%3d", *q);
			printf("\n");
		}
		printf("\n");
	}
}*/
//多维数组传递给函数;
/*#include<stdio.h>
void print(int(*a)[3])
{
	int i,n;
	for (n = 0; n <2; n++)
	{
		for (i = 0; i < 3; i++)
			printf("%2d", a[n][i]);
		printf("\n");
	}
	for (n = 0; n < 2; n++)
	{
		for (i = 0; i < 3; i++)
			printf("%2d", *(*(a+n)+i));
		printf("\n");
	}
}
void main()
{
	int a[2][3] = {1,2,3,4,5,6};
	print(a);
}*/
//测试;
/*#include<stdio.h>
void main()
{
	int* p;
	int a;
	p = &a;
	p[0] = 30;
	printf("%d", a);
}*/
//堆;
/*#include<stdio.h>
#include<stdlib.h>
void main()
{
	int** p;
	int i,j;
	p = (int**)calloc(2 ,sizeof(int*));
	if (p == NULL)
		exit(0);
	for (i = 0; i < 2; i++)
	{
		*(p + i) = (int*)calloc(3 , sizeof(int));
		if (*(p + i) == NULL)
			exit(0);
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++);
			
	}
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
			printf("%2d", p[i][j]);
		printf("\n");
	}
	for (i = 0; i < 2; i++)
	{
		free(*(p + i));
		*(p + i) = NULL;
	}
	free(p);
	p = NULL;
}*/
//错误的栈传递(正常运行版);
/*#include<stdio.h>
int* Add(int* a, int* b)
{
	int c = *a + *b;
	return &c;
}
int main()
{
	int a = 4, b = 2;
	int *c=Add(&a, &b);
	printf("%d", *c);
}*/
//错误的栈传递(错误运行版);
/*#include<stdio.h>
void print()
{
	printf("Hello world!\n");
}
int* Add(int* a, int* b)
{
	int c = *a + *b;
	return &c;
}
int main()
{
	int a = 4, b = 2;
	int* c = Add(&a, &b);
	print();
	printf("%d", *c);
}*/
//错误栈传递的纠正;
/*#include<stdio.h>
#include<stdlib.h>
void print()
{
	printf("Hello world!\n");
}
int* Add(int* a, int* b)
{
	int *c = (int*)malloc(sizeof(int));
	if (c == NULL)
		exit(0);
	*c = *a + *b;
	return c;
}
int main()
{
	int a = 4, b = 2;
	int* c = Add(&a, &b);
	print();
	printf("%d", *c);
	return 0;
}*/
//指向函数的指针;
/*#include<stdio.h>
int Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int (*p)();//int (*p)(int,int)也可以
	p = Add;//p=&Add也可以
	int c = p(3, 2);//c=(*p)(3,2)也可以
	printf("%d", c);
}*/
//指向函数的指针变量作为函数参数;
/*#include<stdio.h>
int sum(int a, int (*p)())
{
	int sum = Add(2, 3) * a;
	return sum;
}
int Add(int a, int b)
{
	int c = a + b;
	return c;
}
int main()
{
	int (*p)();
	p = Add;
	int c = p(3, 2);
	printf("%d\n", c);
	c=sum(3, Add);
	printf("%d", c);
}*/
//qsort函数排序(在stdlib.h中)
/*#include<stdio.h>
#include<stdlib.h>
int compare(const void* a, const void* b)
{
	int A = *((int*)a);
	int B = *((int*)b);
	return A - B;
}
int main()
{
	int a[2][4] = { 3,1,7,2,8,6,4,5 };
	qsort(a[1], 4, sizeof(int), compare);
	for (int i = 0; i < 4; i++)
		printf("%2d", a[1][i]);
}*/
//单链表并且在链表开头插入元素以及任意位置插入和删除等（屎山链表生成器1.5.00版）;
/*#include<stdio.h>
#include<stdlib.h>
struct nb
{
	int a;
	struct nb* b;
};
void shuru(struct nb** head, int x)
{
	struct nb* temp = (struct nb*)malloc(sizeof(struct nb));
	if (temp == NULL)
		exit(1);
	temp->a= x;
	temp->b = *head;
	*head = temp;
}
void print(struct nb** head)
{
	struct nb* temp = *head;
	while (temp != NULL)
	{
		printf("%d ", temp->a);
		temp = temp->b;
	}
}
void charu(struct nb** head, int n, int x)
{
	struct nb* temp1 = (struct nb*)malloc(sizeof(struct nb));
	if (temp1 == NULL)
		exit(1);
	temp1->a = x;
	temp1->b = NULL;
	if (n == 1)
	{
		temp1->b = *head;
		*head = temp1;
		return;
	}
	struct nb* temp2 = *head;
	for (int i = 0; i < n - 2; i++)
	{
		temp2 = temp2->b;
	}
	temp1->b = temp2->b;
	temp2->b = temp1;
}
void shanchu(struct nb** head, int n)
{
	struct nb* temp1 = *head;
	if (n == 1)
	{
		*head = temp1->b;
		free(temp1);
		return;
	}
	for (int i = 0; i < n - 2; i++)
		temp1 = temp1->b;
	struct nb* temp2 = temp1->b;
	temp1->b = temp2->b;
	free(temp2);
}
void fanzhuan(struct nb** head)
{
	struct nb* a, *b,*next;
	a = *head;
	b = NULL;
	while (a!=NULL)
	{
		next = a->b;
		a->b = b;
		b = a;
		a = next;
	}
	*head = b;
}
void digui(struct nb* head)
{
	if (head == NULL)
		return;
	digui(head->b);
	printf("%d ", head->a);
}
void* diguifanzhuan(struct nb* p,struct nb* q)
{
	struct nb* head;
	if (p->b == NULL)
	{
		head = p;
		p->b = q;
		return head;
	}
	struct nb* w = p->b;
	if (p == q)
		p->b = NULL;
	else
		p->b = q;
	head = diguifanzhuan(w, p);
	return head;
}
void del( struct nb* head)
{
	struct nb* temp = head->b;
	free(head);
	if (temp == NULL)
		return;
	del(temp);
}
void chushi(char* a, int n)
{
	for (int i = 0; i < n; i++)
		*(a + i) = '0';
}
int main()
{
	struct nb* head = NULL;
	char h[5] = { 'n','o','.','1','\n'}, u[5] = {'n','o','.','2'}, m[2][10] = {{'\n','q','w','q','2','3','3','3','3','3'}, {'\n','w','w','l','2','3','2','3','1','2'}};
	char j[5] , f[10];
	int n,i,x,a,k,s=1,z=-1,lh=0,hl=1,ri,si=3;
    printf("欢迎使用1.5.65版本<屎山链表生成器>!\n");
lo:printf("请输入您的账号!(如果忘记账号请输入***加上用户数)\n *用户数为账号末尾数字*\n");
	for (i = 0; i < 4; i++)
	{
		scanf_s("%c", &j[i], 1);
		if (j[0] == 'W')
			goto W;
		if (j[i] == '\n')
			i = -1;
		if (j[0] == '*' && j[1] == '*' && j[2] == '*' && (j[3] == '1' || j[3] == '2'))
		{
			printf("账号查找成功\n您的账号为%c%c%c%c\n", h[0], h[1], h[2], j[3]);
			s = 1;
			break;
		}
		if (j[i] != h[i] && j[i] != '2')
			s = 0;
	}
	h[3] = j[3];
	z = j[3] - 49;
	if (z<lh ||z>hl)
	{
		s = 0;
	}
	if (s == 0)
	{
		printf("用户不存在!!!<屎山链表生成器>拒绝访问!!!\n");
		si--;
		printf("您还有%d次机会登录!!!\n", si);
		h[3] = '1';
		chushi(j, 5);
		s = 1;
		if (si == 0)
		{
			printf("<屎山链表生成器>已重置,请重新启动!");
			exit(0);
		}
		goto lo;
	}
	si = 3;
	printf("*密码输入仅有一次机会!*\n");
	printf("请输入您的密码!(如果忘记密码请输入账号)\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%c", &f[i],1);
		if (f[1] == 'n'&&f[2]=='o'&&f[3]=='.'&&f[4]==j[3])
		{
			printf("密码查找成功\n");
			printf("您的密码为%c%c%c%c%c%c%c%c%c,请牢记密码!\n",m[z][1], m[z][2], m[z][3], m[z][4], m[z][5], m[z][6], m[z][7], m[z][8], m[z][9]);
			s = 1;
			break;
		}
			if (f[i] != m[z][i])
				s = 0;
	}
	if (s==0)
	{
		printf("账号或密码错误!!!<屎山链表生成器>拒绝访问!!!");
		exit(0);
	}
	printf("登陆成功!\n您想创建一个有几个元素的链表？\n");
    W:if(j[0]=='W')
    {
		printf("欢迎管理员!\n");
		if (si == 1)
		{
			printf("当前登录系统允许错误次数为%d,是否更改?\n", si - 1);
			printf("不更改1,更改输入任意大于1的数。\n");
			scanf_s("%d", &si);
			if (si < 1)
			{
				printf("输入错误已自动更改!!!\n");
				si = 1;
			}
			if (si != 1)
			{
				printf("更改成功!当前允许出错次数为%d。(请以实际登录显示次数为准!)\n", si - 1);
			}
		}
		if (hl > lh)
		{
			printf("*无拉黑人员*\n");
			printf("输入任意数字退出管理员系统:");
			scanf_s("%d", &ri);
		}
		if (lh == hl && lh == 0)
		{
			printf("用户no.2被拉黑,是否解除？1解除0不解除\n");
			scanf_s("%d", &hl);
		}
		if (lh == hl && lh == 1)
		{
			printf("用户no.1被拉黑,是否解除？0解除1不解除\n");
			scanf_s("%d", &lh);
		}
		if (lh >hl)
		{
			printf("用户no.1,no.2被拉黑,是否解除？0 0解除no.1,1 1解除no.2,0 1都解除,1 0都不解除\n");
			scanf_s("%d%d", &lh,&hl);
		}
		j[0] = '0';
		goto lo;
    }
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		if(i==n-1)
			printf("请输入最后一个元素:");
		else
		    printf("请输入第%d个元素:", i + 1);
		scanf_s("%d", &x);
		shuru(&head, x);
	}
	printf("当前链表为:");
	print(&head);
	printf("\n");
	for (i = 0;; i++)
	{
		printf("请选择您想要的操作,并且输入相应操作数。\n");
		printf("插入元素.0,删除元素.1,反转链表.2,递归反向输出链表.3,输出当前链表.4,查看头指针.5,退回登录页面.6,任意别的数据退出程序。\n");
		scanf_s("%d", &k);
		if (k == 0)
		{
			printf("你想在第几个位置插入元素几?注意位置范围:1-%d!\n",n+1);
			scanf_s("%d%d", &a, &x);
			if (a > n + 1)
			{
				printf("你小子想让程序跑飞是吧？\n已自动退出,<屎山链表生成器>已将%s用户拉黑!!!\n",h);
				if (z == 1)
				{
					hl = 0;
				}
				if (z == 0)
				{
					lh = 1;
				}
				h[3] = '1';
				chushi(j, 5);
				chushi(f, 10);
				del(head);
				head = NULL;
				goto lo;
			}
			charu(&head, a, x);
			printf("插入完毕\n");
			n++;
			print(&head);
			printf("\n");
			continue;
		}
		if (k == 1)
		{
			printf("你想删除第几个元素？注意位置范围:1-%d!\n",n);
			scanf_s("%d", &a);
			if (a>n )
			{
				printf("你小子想让程序跑飞是吧？\n已自动退出,<屎山链表生成器>已将%s用户拉黑!!!\n", h);
				if (z == 1)
				{
					hl = 0;
				}
				if (z == 0)
				{
					lh = 1;
				}
				h[3] = '1';
				chushi(j, 5);
				chushi(f, 10);
				del(head);
				head = NULL;
				goto lo;
			}
			shanchu(&head, a);
			printf("删除成功。\n");
			n--;
			print(&head);
			printf("\n");
			continue;
		}
		if (k == 2)
		{
			printf("使用迭代反转0,使用递归反转1。\n");
			scanf_s("%d", &x);
			if(x==0)
				fanzhuan(&head);
			if (x == 1)
				head=diguifanzhuan(head,head);
			if (x != 0 && x != 1)
			{
				printf("输入错误!\n");
				continue;
			}
			printf("反转结果为:");
			print(&head);
			printf("\n");
			continue;
		}
		if (k == 3)
		{
			printf("递归反向输出结果为:");
			digui(head);
			printf("\n");
			continue;
		}
		if (k == 4)
		{
			printf("当前链表为:");
			print(&head);
			printf("\n");
			continue;
		}
		if (k == 5)
		{
			printf("当前头指针为%d\n",head);
			continue;
		}
		if (k == 6)
		{
			printf("链表最终结果为:");
			print(&head);
			printf("\n");
			h[3] = '1';
			chushi(j, 5);
			chushi(f, 10);
			del(head);
			head = NULL;
			goto lo;
		}
			printf("链表最终结果为:");
			print(&head);
			printf("\n程序已退出,<屎山链表生成器>祝%s用户生活愉快！",h); 
			del(head);head = NULL;
		break;
	}
	return 0;
}*/
//双链表的模拟使用历遍, 删除, 插入;
/*#include<stdio.h>
#include<stdlib.h>
struct nb* head = NULL;
struct nb
{
	struct nb* a;
	int b;
	struct nb* c;
};
void shuru(int x)
{
	struct nb* temp = (struct nb*)malloc(sizeof(struct nb));
	if (temp == NULL)
		exit(0);
	temp->a = NULL;
	temp->c = head;
	temp->b = x;
	if (head != NULL)
		head->a = temp;
	head = temp;
}
void charu(int n, int x)
{
	if (n == 1)
	{
		shuru(x);
		return;
	}
	struct nb* temp = (struct nb*)malloc(sizeof(struct nb));
	struct nb* temp1=head;
	if (temp == NULL)
		exit(0);
	for (int i = 0; i < n - 2; i++)
	{
		temp1 = temp1->c;
		if (temp1 == NULL)
			return;
	}
	temp->b = x;
	temp->a = temp1;
	temp->c = temp1->c;
	if(temp1->c!=NULL)
	temp1->c->a = temp;
	temp1->c = temp;
}
void shanchu(int n)
{
	struct nb* temp = head;
	for (int i = 0; i < n - 1; i++)
	{
		temp = temp->c;
	}
	if (temp->a != NULL)
		temp->a->c = temp->c;
	else
		head = temp->c;
	if(temp->c!=NULL)
	temp->c->a = temp->a;
	free(temp);
}
void print()
{
	struct nb* temp=head;
	if (temp == NULL)
		return;
	while (temp ->c!= NULL)
	{
		printf("%d ", temp->b);
		temp = temp->c;
	}
	printf("%d", temp->b);
	printf("\n");
	while (temp != NULL)
	{
		printf("%d ", temp->b);
		temp = temp->a;
	}
}
int main()
{
	int n,k,i,x;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &x);
		shuru(x);
	}
	print();
	printf("\n");
	lo:printf("删除1，添加2\n");
	scanf_s("%d", &k);
	if (k == 2)
	{
		printf("你想在第几个位置插入元素几?注意位置范围:1-%d!\n", n + 1);
		scanf_s("%d%d", &i, &x);
		if (i > n + 1)
		{
			printf("你小子想让程序跑飞是吧?\n");
			exit(0);
		}
		charu(i, x);
		print();
		n++;
	}
	if (k == 1)
	{
		printf("你想删除第几个元素？注意位置范围:1-%d!\n", n);
		scanf_s("%d", &i);
		if (i > n)
		{
			printf("你小子想让程序跑飞是吧?");
			exit(0);
		}
		shanchu(i);
		print();
		n--;
	}
	printf("\n是否继续程序继续1,退出0\n");
	scanf_s("%d", &k);
	if (k == 1)
		goto lo;
	print();
	return 0;
}*/
//二叉搜索树;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(1);
	temp->b = x;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (x <= root->b)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
int chazhao(struct bst* root,int x)
{
	if (root == NULL)
		return 0;
	if (root->b == x)
		return 1;
	if (root->b < x)
		return chazhao(root->c, x);
	if (root->b >= x)
		return chazhao(root->a, x);
}
int findmin(struct bst* root)
{
	if (root == NULL)
	{
		printf("错误!");
		exit(-1);
	}
	if (root->a == NULL)
		return root->b;
	else
		return findmin(root->a);
}
int findmax(struct bst* root)
{
	if (root == NULL)
	{
		printf("错误!");
		exit(-1);
	}
	if (root->c == NULL)
		return root->b;
	else
		return findmax(root->c);
}
int main()
{
	struct bst* root=NULL;
	int a, x, n, i, j[7] = {5,3,8,1,4,6,9};
	n = 7;
	for (i = 0; i < n; i++)
	{
		root=shuru(root, j[i]);
	}
	printf("树已生成!");
	for (i = 0;; i++)
	{
		printf("输入你想查找的数据,退出-1\n");
		scanf_s("%d", &x);
		if (x == -1)
			break;
		a=chazhao(root,x);
		if (a == 1)
			printf("有该数据\n");
		if (a == 0)
			printf("无该数据\n");
	}
	printf("min=%d\n",findmin(root));
	printf("max=%d\n",findmax(root));
	printf("   %d\n", root->b);
	printf("  / \\\n");
	printf(" %d   %d\n", root->a->b, root->c->b);
	printf("/ \\ / \\\n");
	printf("%d %d %d %d", root->a->a->b, root->a->c->b, root->c->a->b, root->c->c->b);
}*/
//二叉树的高度;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (x <= root->b)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
int maxi(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int hight(struct bst* root)
{
	if (root == NULL)
		return -1;
	return maxi(hight(root->a), hight(root->c)) + 1;
}
int main()
{
	struct bst* root = NULL;
	int a, x, n, i, j[9] = { 5,3,8,1,4,6,9,3,5 };
	n = 9;
	for (i = 0; i < n; i++)
	{
		root = shuru(root, j[i]);
	}
	printf("hight=%d", hight(root));
}*/
//树的结构图;
/*     5
	/     \
   2       8
  / \     / \
 1   4   6   9
    / \
   3   5       */
//二叉树的遍历（前序遍历）DLR;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (x <= root->b)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
void print(struct bst* root)
{
	if (root == NULL)
		return;
	printf("%d\n", root->b);
	print(root->a);
	print(root->c);
}
int main()
{
	struct bst* root = NULL;
	int a, x, n, i, j[9] = { 5,2,8,1,4,6,9,3,5 };
	n = 9;
	for (i = 0; i < n; i++)
	{
		root = shuru(root, j[i]);
	}
	print(root);
}*/
//二叉树的遍历（中序遍历）LDR（按大小排序）;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
}
struct bst* shuru(struct bst* root,int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (x <= root->b)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
void print(struct bst* root)
{
	if (root == NULL)
		return;
	print(root->a);
	printf("%d\n", root->b);
	print(root->c);
}
int main()
{
	struct bst* root=NULL;
	int  n, a[9] = { 5,2,8,1,4,6,9,3,5 };
	n = 9;
	for (int i = 0; i < n; i++)
		root = shuru(root, *(a+i));
	print(root);
}*/
//二叉树的遍历（后序遍历）LRD;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (x <= root->b)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
void print(struct bst* root)
{
	if (root == NULL)
		return;
	print(root->a);
	print(root->c);
	printf("%d\n", root->b);
}
int main()
{
	struct bst* root = NULL;
	int  n, a[9] = { 5,2,8,1,4,6,9,3,5 };
	n = 9;
	for (int i = 0; i < n; i++)
		root = shuru(root, *(a + i));
	print(root);
}*/
//二叉树的层遍历（队列实现）;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (x <= root->b)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
void print(struct bst* root)
{
	struct bst* a[20];
	int b=-1, c=-1;
	if (root == NULL)
		return;
	a[0] = root;
	b++; c++;
	while (b <=c)
	{
		printf("%d ", a[b]->b);
		if (a[b]->a != NULL)
		{
			c++;
			a[c] = a[b]->a;
		}
		if (a[b]->c != NULL)
		{
			c++;
			a[c] = a[b]->c;
		}
		b++;
	}
}
int main()
{
	struct bst* root = NULL;
	int n = 9, a[9] = { 5,2,8,1,4,6,9,3,5 };
	for (int i = 0; i < n; i++)
	{
		root = shuru(root, a[i]);
	}
	print(root);
}*/
//判断二叉树是否为搜索二叉树;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew()
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = 0;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int* x,int n)
{
	struct bst* a[20];
	int b = -1, c = -1;
	b++; c++;
	if (root == NULL)
		root = getnew();
	a[0] = root;
	while (b<=c)
	{
		if (c < n-1 )
		{
			c++;
			a[c] = a[b]->a = getnew();
		}
		if (c < n-1 )
		{
			c++;
			a[c] = a[b]->c = getnew();
		}
		a[b]->b = x[b];
		b++;
	}
	return root;
}
int panduan(struct bst* root, int max, int min)
{
	if (root == NULL)
		return 1;
	if(root->b<max&&root->b>min&&panduan(root->a,root->b,min)==1&&panduan(root->c,max,root->b)==1)
		return 1;
	else
		return 0;
}
int i=0;
int m;
int print(struct bst* root)
{
	int a, b;
	if (root == NULL)
		return 1;
	a=print(root->a);
	if (i == 0)
	{
		m = root->b;
		i++;
	}
	else
	{
		if (root->b < m)
		{
			m = root->b;
			return 0;
		}
		m = root->b;
	}
	b=print(root->c);
	if (a == 0 || b == 0)
		return 0;
	else
		return 1;
}
int main()
{
	struct bst* root = NULL;
	int j[8] = { 5,3,8,1,4,6,9,0 },a,b;
	root=shuru(root, j,sizeof(j)/sizeof(int));
	a=panduan(root, 1000, -1000);
	if (a == 1)
		printf("二叉搜索树\n");
	if (a == 0)
		printf("二叉树\n");
	b = print(root);
	if (b == 1)
		printf("二叉搜索树");
	if (b == 0)
		printf("二叉树");
}*/
//删除二叉搜索树节点（着重复习）;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (x <= root->b)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
struct bst* findmin(struct bst* root)
{
	if (root == NULL)
		exit(-1);
	if (root->a != NULL)
		root=findmin(root->a);
		return root;
}
struct bst* delit(struct bst* root,int x)
{
	if (root == NULL)
		return root;
	else if (root->b > x)
		root->a = delit(root->a, x);
	else if (root->b < x)
		root->c = delit(root->c, x);
	else
	{
		if (root->a == NULL && root->c == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->a == NULL)
		{
			struct bst* temp=root;
			root = root->c;
			free(temp);
		}
		else if (root->c == NULL)
		{
			struct bst* temp = root;
			root = root->a;
			free(temp);
		}
		else
		{
			struct bst* temp;
			temp = findmin(root->c);
			root->b = temp->b;
			root->c=delit(root->c, temp->b);
		}
	}
	return root;
}
void print(struct bst* root)
{
	if (root == NULL)
		return;
	print(root->a);
	printf("%d\n", root->b);
	print(root->c);
}
int main()
{
	struct bst* root = NULL,*temp;
	int a, x, n, i, j[7] = { 5,3,8,1,4,6,9 };
	n = 7;
	for (i = 0; i < n; i++)
	{
		root = shuru(root, j[i]);
	}
	root = delit(root,3);
	print(root);
}*/
//寻找中序后继点;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (x <= root->b)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
struct bst* zhaoxun(struct bst* root, int x)
{
	struct bst* temp = root;
	while (temp->b != x)
	{
		if (temp->b > x)
			temp = temp->a;
		else
			temp = temp->c;
	}
	if (temp->c != NULL)
	{
		temp = temp->c;
		while (temp->a != NULL)
		{
			temp = temp->a;
		}
		return temp;
	}
	else
	{
		struct bst* temp1 = NULL;
		struct bst* temp2 = root;
		while (temp2->b != temp->b)
		{
			if (temp2->b > temp->b)
			{
				temp1 = temp2;
				temp2 = temp2->a;
			}
			else
				temp2 = temp2->c;
		}
		return temp1;
	}
}
int main()
{
	struct bst* root = NULL, * temp;
	int a, x, n, i, j[7] = { 5,3,8,1,4,6,9 };
	n = 7;
	for (i = 0; i < n; i++)
	{
		root = shuru(root, j[i]);
	}
	temp = zhaoxun(root, 6);
	if (temp == NULL)
		printf("无中序后继点!");
	else
	    printf("%d", temp->b);
}*/
//复习删除搜索二叉树节点;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x; temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (root->b > x)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
struct bst* findmin(struct bst* root)
{
	if (root == NULL)
		return root;
	while (root->a != NULL)
	{
		root = root->a;
	}
	return root;
}
struct bst* delit(struct bst* root, int x)
{ 
	if (root == NULL)
		return root;
	else if (root->b > x)
		root->a = delit(root->a, x);
	else if (root->b < x)
		root->c = delit(root->c, x);
	else
	{
		if (root->a == NULL && root->c == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->a == NULL)
		{
			struct bst* temp=root;
			root = root->c;
			free(temp);
		}
		else if (root->c == NULL)
		{
			struct bst* temp = root;
			root = root->a;
			free(temp);
		}
		else
		{
			struct bst* temp = findmin(root->c);
			root->b = temp->b;
			root->c = delit(root->c, temp->b);
		}
	}
	return root;
}
void print(struct bst* root)
{
	if (root == NULL)
		return;
	print(root->a);
	printf("%d\n", root->b);
	print(root->c);
}
int main()
{
	struct bst* root = NULL, * temp;
	int a, x, n, i, j[7] = { 5,3,8,1,4,6,9 };
	n = 7;
	for (i = 0; i < n; i++)
	{
		root = shuru(root, j[i]);
	}
	root = delit(root, 3);
	print(root);
}*/
//复习寻找中序后继点;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (root->b > x)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
struct bst* chazhao(struct bst* root, int x)
{
	if (root == NULL)
		return root;
	struct bst* temp = root;
	while (temp->b != x)
	{
		if (temp->b > x)
			temp = temp->a;
		else
			temp = temp->c;
	}
	if (temp->c != NULL)
	{
		temp = temp->c;
		while (temp->a != NULL)
		{
			temp = temp->a;
		}
	}
	else
	{
		struct bst* temp1 = root;
		struct bst* temp2 = NULL;
		while (temp1->b != x)
		{
			if (temp1->b > x)
			{
				temp2 = temp1;
				temp1 = temp1->a;
			}
			else
				temp1 = temp1->c;
		}
		temp = temp2;
	}
	return temp;
}
int main()
{
	struct bst* root = NULL, * temp;
	int a, x, n, i, j[7] = { 5,3,8,1,4,6,9 };
	n = 7;
	for (i = 0; i < n; i++)
	{
		root = shuru(root, j[i]);
	}
	temp = chazhao(root, 6);
	if (temp == NULL)
		printf("无中序后继点!");
	else
		printf("%d", temp->b);
}*/
//复习二叉树高度;
/*#include<stdio.h>
#include<stdlib.h>
struct bst 
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (root->b > x)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
int maxi(int a, int b)
{
	if (a > b)
		return a;
	return b;
}
int gaodu(struct bst* root)
{
	if (root == NULL)
		return -1;
	return maxi(gaodu(root->a), gaodu(root->c)) + 1;
}
int main()
{
	struct bst* root = NULL;
	int a, x, n, i, j[9] = { 5,3,8,1,4,6,9,3,5 };
	n = 9;
	for (i = 0; i < n; i++)
	{
		root = shuru(root, j[i]);
	}
	printf("hight=%d", gaodu(root));
}*/
/*复习判断二叉树;
#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew()
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = 0;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int* x,int n)
{
	struct bst* d[20];
	int a, b, c;
	a = b = -1;
	root = d[0] = getnew();
	a++;
	b++;
	while (b <= a)
	{
		if (a < n - 1)
		{
			a++;
			d[a] = getnew();
			d[b]->a = d[a];
		}
		if (a < n - 1)
		{
			a++;
			d[a] = getnew();
			d[b]->c = d[a];
		}
		d[b]->b = x[b];
		b++;
	}
	return root;
}
int panduan(struct bst* root,int max,int min)
{
	if (root == NULL)
		return 1;
	else if (root->b<max && root->b>min && panduan(root->a, root->b, min) && panduan(root->c, max, root->b))
		return 1;
	else
		return 0;
}
int i = 0,a;
int panduan1(struct bst* root)
{
	int b, c;
	if (root == NULL)
		return 1;
	b = panduan1(root->a);
	if (i == 0)
	{
		i = 1;
		a = root->b;
	}
	else
	{
		if (root->b < a)
		{
			a = root->b;
			return 0;
		}
		a = root->b;
	}
	c = panduan1(root->c);
	if (b != 0 && c != 0)
		return 1;
	return 0;
}
int main()
{
	struct bst* root = NULL;
	int j[8] = { 5,3,8,1,4,6,9,-1 }, a, b;
	root = shuru(root, j, sizeof(j) / sizeof(int));
	a = panduan(root, 1000, -1000);
	if (a == 1)
		printf("二叉搜索树\n");
	if (a == 0)
		printf("二叉树\n");
	b = panduan1(root);
	if (b == 1)
		printf("二叉搜索树");
	if (b == 0)
		printf("二叉树");
}*/
//二叉树的层遍历复习;
/*#include<stdio.h>
#include<stdlib.h>
struct bst
{
	struct bst* a;
	int b;
	struct bst* c;
};
struct bst* getnew(int x)
{
	struct bst* temp = (struct bst*)malloc(sizeof(struct bst));
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
	return temp;
}
struct bst* shuru(struct bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (root->b > x)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
void shuchu(struct bst* root)
{
	struct bst* a[20];
	int b = -1, c = -1;
	a[0] = root;
	c = ++b;
	while (b <= c)
	{
		if (a[b]->a != NULL)
		{
			c++;
			a[c] = a[b]->a;
		}
		if (a[b]->c != NULL)
		{
			c++;
			a[c] = a[b]->c;
		}
		printf("%d ", a[b]->b);
		b++;
	}
}
int main()
{
	struct bst* root = NULL;
	int a, x, n, i, j[7] = { 5,3,8,1,4,6,9 };
	n = 7;
	for (i = 0; i < n; i++)
	{
		root = shuru(root, j[i]);
	}
	shuchu(root);
}*/
//复习链表的递归输出;
/*#include<stdio.h>
#include<stdlib.h>
struct link
{
	int a;
	struct link* b;
};
struct link* head = NULL;
struct link* getnew(int x)
{
	struct link* temp = (struct link*)malloc(sizeof(struct link));
	if (temp == NULL)
		exit(-1);
	temp->a = x;
	temp->b = NULL;
	return temp;
}
void shuru(int x)
{
	struct link* temp;
	temp = head;
	head = getnew(x);
	head->b = temp;
	return;
}
void fanzhuan(struct link* temp)
{
	if (temp->b == NULL)
	{
		head = temp;
		return;
	}
	fanzhuan(temp->b);
	temp->b->b = temp;
	temp->b = NULL;
}
void print()
{
	struct link* temp = head;
	while (temp != NULL)
	{
		printf("%d ", temp->a);
		temp = temp->b;
	}
}
int main()
{
	shuru(5);
	shuru(4);
	shuru(3);
	shuru(2);
	shuru(1);
	print();
	printf("\n");
	fanzhuan(head);
	print();
	printf("\n");
	fanzhuan(head);
	print();
}*/
//复习qsort排序;
/* #include<stdio.h>
#include<stdlib.h>
int com(const void* a, const void* b)
{
	int A = *((int*)a);
	int B = *((int*)b);
	return A - B;
}
void print(int(*a)[5])
{
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 5; j++)
			printf("%d ", *(*(a + i) + j));
		printf("\n");
	}
}
int main()
{
	int a[2][5] = { {1,3,7,2,5},{7,2,6,3,8} };
	print(a);
	qsort(a[0], 5, sizeof(int), com);
	print(a);
	qsort(a[1], 5, sizeof(int), com);
	print(a);
} */
//关于我学不懂归并排序的那些事;
/*#include<stdio.h>
int a[100],b[100],sum=0;
void msort(int w, int t)
{
	int c, d, e;
	if ((w + t) / 2 != w)
	{
		msort(w, (w + t)/2);
		msort(((w + t)/2) + 1, t);
	}
	for (c = w, d = ((w + t) / 2) + 1,e=w; (c <= (w + t) / 2 && d <= t)||(e<=t);e++)
	{
		if (c > (w + t) / 2)
		{
			b[e] = a[d];
			d++;
		}
		else if (d > t)
		{
			b[e] = a[c];
			c++;
		}
		else
		{
			if (a[c] < a[d])
			{
				b[e] = a[c];
				c++;
			}
			else
			{
				b[e] = a[d];
				d++;
			}
		}
		sum++;
	}
	for (c = w; c <= t; c++)
	{
		a[c] = b[c];
	}
}
int main()
{
	int n, i;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	msort(0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\n%d", sum);
}*/
//这么久了还记得冒泡吗？;
/*#include<stdio.h>
int a[20], i, temp, j, sum = 0, n;
int main()
{
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
		scanf_s("%d", &a[i]);
	for(i=0;i<n;i++)
		for (j = 0; j < n-i-1; j++)
		{
			if (a[j] > a[j + 1])
			{
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
			sum++;
		}
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n%d", sum);
}*/
写在最后冒泡vs归并;
#include<stdio.h>
int a[200], b[200], a1[200], sum0 = 0; sum = 0, sum1 = 0;
void msort(int w, int t)
{
	int c, d, e;
	if ((w + t) / 2 != w)
	{
		msort(w, (w + t) / 2);
		msort(((w + t) / 2) + 1, t);
	}
	for (c = w, d = ((w + t) / 2) + 1, e = w; (c <= (w + t) / 2 && d <= t) || (e <= t); e++)
	{
		if (c > (w + t) / 2)
		{
			b[e] = a[d];
			d++;
		}
		else if (d > t)
		{
			b[e] = a[c];
			c++;
		}
		else
		{
			if (a[c] < a[d])
			{
				b[e] = a[c];
				c++;
			}
			else
			{
				b[e] = a[d];
				d++;
			}
		}
		sum0++;
		sum++;
	}
	for (c = w; c <= t; c++)
	{
		sum0++;
		a[c] = b[c];
	}
}
int main()
{
	int n, i,temp,j;
	scanf_s("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &a[i]);
		a1[i] = a[i];
	}
	printf("归并排序:\n");
	msort(0, n - 1);
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n归并排序加上复制数组循环次数为:%d\n", sum0);
	printf("归并排序循环次数为:%d\n", sum);
	printf("冒泡排序:");
	for (i = 0; i < n; i++)
		for (j = 0; j < n - i - 1; j++)
		{
			if (a1[j] > a1[j + 1])
			{
				temp = a1[j];
				a1[j] = a1[j + 1];
				a1[j + 1] = temp;
			}
			sum1++;
		}
	for (i = 0; i < n; i++)
		printf("%d ", a1[i]);
	printf("\n冒泡排序循环次数为:%d", sum1);
}