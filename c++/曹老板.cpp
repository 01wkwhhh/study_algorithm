/*#include<iostream>
using namespace std;
int max(int a, int b, int c)
{
	int max=a;
	b > max ? max = b : max = max;
	c > max ? max = c : max = max;
	return max;
}
int max(int a, int b)
{
	int max=a;
	b > max ? max = b : max=max;
	return max;
}
int main()
{
	int a, b, c;
	int d[3];
	cin >> a >> b >> c;
	d[0] = max(a, b, c);
	d[1] = max(a, b);
	d[2] = max(b, c);
	cout << d[0]<<" "<< d[1]<<" " << d[2] << endl;
}*/
/*#include<iostream>
#include<cstring>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N = 200010;
int n;
int w[N];
int main()
{
	scanf_s("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf_s("%d", &w[i]);
	unordered_map<int, int>f;
	int res = 0;
	for (int i = 1; i <= n; i++)
	{
		f[w[i]] = max(f[w[i] - 1], 0) + 1;
		if (res < f[w[i]])
		{
			res = f[w[i]]; 
		}
	}
	printf("%d", res);
	return 0;
}*/
/*#include<iostream>
#include<string>
using namespace std;
int b = 10;
int main()
{
	string d = "hello world!";
	string e[2] = { "Hello world!","hello world!" };
	int a[3] = { 1,2,3 };
	int b = 0;
	int& c = a[0];
	cout << c << endl;
	cout << "土皇帝" << b << "天皇" << ::b << endl;
	for (int i = 0; i < 2; i++)
	{
		if (d == e[i])
			cout << e[i];
	}
}*/
/*#include<iostream>
#include<string.h>
struct bst
{
	bst* a;
	int b;
	bst* c;
};
bst* getnew(int x)
{
	bst* temp = new bst;
	if (temp == NULL)
		exit(-1);
	temp->b = x;
	temp->a = temp->c = NULL;
}
bst* shuru(bst* root, int x)
{
	if (root == NULL)
		root = getnew(x);
	else if (root->b > x)
		root->a = shuru(root->a, x);
	else
		root->c = shuru(root->c, x);
	return root;
}
int main()
{
	bst* root = NULL;
	int a, x, n, i, j[7] = { 5,3,8,1,4,6,9 };
	n = 7;
	for (i = 0; i < n; i++)
	{
		root = shuru(root, j[i]);
	}
	printf("   %d\n", root->b);
	printf("  / \\\n");
	printf(" %d   %d\n", root->a->b, root->c->b);
	printf("/ \\ / \\\n");
	printf("%d %d %d %d", root->a->a->b, root->a->c->b, root->c->a->b, root->c->c->b);
	return 0;
}*/
/*#include<iostream>
#include<string>
using namespace std;
void jiaohuan(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int main()
{
	string a;
	int b[5] = { 0,0,0,0,0 }, n, x, temp, temp1, num, c[5][3][9] = { {{0}} }, d[5] = { 1,2,3,4,5 }, e[5];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		cin >> a;
		cin >> temp;
		if (temp > c[x - 1][a[1] - 49][a[3]-49])
			c[x - 1][a[1] - 49][a[3]-49]=temp;
	}
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 8; j++)
			b[i] += c[i][0][j];
	for (int i = 0; i < 5; i++)
		e[i] = b[i];
	num =temp1= b[0] + b[1] + b[2] + b[3] + b[4];
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 4; j++)
			{
				if(b[i]>=60)
				b[i] += c[i][1][j];
			}
	if (num >= 300)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 4; j++)
			{
				num += c[i][1][j];
			}
	}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 3; j++)
			{
				if(b[i]-e[i]>=25)
				b[i] += c[i][2][j];
			}
	if (num-temp1>= 125)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 3; j++)
			{
				num += c[i][2][j];
			}
	}
	cout << num << endl;
	for (int i = 0; i < 4; i++)
	{
		if (b[i] < b[i + 1])
		{
			jiaohuan(b[i], b[i + 1]);
			jiaohuan(d[i], d[i + 1]);
			i = -1;
		}
	}
	for (int i = 0; i < 5; i++)
		cout << d[i] << ' ' << b[i] << endl;
}*/
/*#include<iostream>
using namespace std;
int panduan(long int n)
{
	for (long int i = 2; i <=  n/i; i++)
	{
		if (n % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	long int n;
	cin >> n;
	for (long int i = 2; i <= n -i; i++)
	{
		if (panduan(i) && panduan(n-i))
		{
			cout << n << " = " << i << " + " << n - i;
			break;
		}
	}
}*/
/*#include<iostream>
using namespace std;
void shuchu(int n)
{
	int a;
	if (n < 10)
	{
		cout << n;
		return;
	}
	a = n / 10 * 10;
	cout << n - a;
	shuchu(n / 10);
}
int main()
{
	int n;
	cin >> n;
	shuchu(n);
}*/
/*#include<iostream>
using namespace std;
struct link
{
	int a;
	link* b;
};
link* getnew(int x)
{
	link* temp = new link;
	if (temp == NULL)
		exit(-1);
	temp->a = x;
	temp->b = NULL;
}
link* shuru(link* head, int x)
{
	if (head == NULL)
		head = getnew(x);
	else
		head->b=shuru(head->b, x);
	return head;
}
int main()
{
	link* head = NULL,*temp;
	int a, b,x,num=1;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		cin >> x;
		head = shuru(head, x);
	}
	temp = head;
	for (int i = 0; i < a; i++)
	{
		if (i > a - b - 1)
		{
			num *= temp->a;
		}
		temp = temp->b;
	}
	cout << num;
}*/
/*#include<iostream>
#include<string>
using namespace std;
class student
{
private:
	string name;
	string xvehao;
public:
	void shuru()
	{
		cin >> name >> xvehao;
	}
	void shuchu()
	{
		cout << "姓名:" << name << "学号:" << xvehao;
	}
};
int main()
{
	student xve1, xve2;
	xve1.shuru();
	xve2.shuru();
	xve1.shuchu();
	cout << endl;
	xve2.shuchu();
	return 0;
}*/
/*#include<iostream>
using namespace std;
class yuan
{
public:
	int r;
	void zhouchang();
	yuan(int t)
	{
		r = t;
	}
};
void yuan::zhouchang()
{
	cout << 2 * 3 * r;
	return;
}
void yuan2(yuan t)
{
	cout << endl;
	t.zhouchang();
}
int main()
{
	yuan yuan1(3), * p = &yuan1, & yuan = yuan1;
	yuan1.zhouchang();
	p->zhouchang();
	yuan.zhouchang();
	cout << endl << yuan1.r << yuan.r << p->r;
	yuan2(yuan);
}*/
/*#include<iostream>
#include<string>
using namespace std;
class student
{
private:
	int xve;
	char name[20];
public:
	student(int n = 100, const char nam[] = "xvboyuan") :xve(n)
	{
		strcpy_s(name, nam);
	}
	~student()
	{
		cout << "嗨嗨嗨!" << name << endl;
	}
	void show()
	{
		cout << xve << endl; 
		cout << name << endl;
	}
};
int main()
{
	void (student::*a)();
	student q[3] =
	{
		student(123,"wangkenan"),
		student(100,"xvboyuan"),
		student(111,"wangweilin")
	};
	student* p = q;
	for (int i = 0; i < 3; i++)
		p[i].show();
	a = &student::show;
	(q[0].*a)();
	return 0;
}*/
/*#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class student
{
private:
	char name[20];
	int xve;
public:
	student(int x,const char a[]):xve(x)
	{
		strcpy_s(name, a);
	}
	~student()
	{
		cout << "完结撒花!" << name;
	}
	void display()
	{
		cout << xve << endl << name << endl;
	}
	void shuru()
	{
		cin >> xve >> name;
	}
};
int main()
{
	student* p = new student(123, "wangkenan");
	p->display();
	delete p;
	return 0;
}*/
/*#include<iostream>
#include<string>
using namespace std;
class nb;
class student
{
private:
	int xve;
	char name[20];
public:
	friend void shuchu(student&);
	friend nb;
	student(int n,const char a[]) :xve(n)
	{
		strcpy_s(name, a);
	}
};
class nb
{
private:
	int a;
public:
	void shuchu(student* t)
	{
		cout << t->xve << a;
	}
	nb(int c) :a(c) {}
};
void shuchu(student& a)
{
	cout << a.xve << ' ' << a.name;
}
int main()
{
	student a(123, "wangkenan");
	shuchu(a);
	nb b(90);
	b.shuchu(&a);
}*/ 
/*#include<iostream>
using namespace std;
class fushu
{
private:
	int x;
	int y;
public:
	fushu(int a,int b):x(a),y(b){}
	friend fushu operator+(fushu& t,fushu& t1);
	void display()
	{
		cout << x << '+' << y << 'i' << endl;
	}
};
fushu operator+(fushu& t,fushu& t1)
{
	fushu c(0, 0);
	c.x = t1.x + t.x;
	c.y = t1.y + t.y;
	return c;
}
int main()
{
	fushu c1(12, 34), c2(-6, -19), c3(0, 0);
	c3 = c1 + c2;
	c3.display();
}*/
/*#include<iostream>
#include<string>
using namespace std;
class String
{
private:
	const char* t;
public:
	friend bool operator>(String& t1, String& t2);
	String(const char* t=NULL):t(t){}
};
bool operator>(String& t1, String& t2)
{
	if (strcmp(t1.t, t2.t) > 0)
		return true;
	return false;
}
int main()
{
	String string1("Hello"), string2("Book");
	cout << (string1 > string2);
}*/
/*#include<iostream>
using namespace std;
class Time
{
private:
	int sec;
	int minute;
public:
	Time(int a=0,int b=0):minute(a%60),sec(b%60){}
	friend void operator++(Time& t1); 
	friend Time operator++(Time& t1,int);
	friend ostream& operator<<(ostream& cout, Time& t);
	friend istream& operator>>(istream& cin, Time& t);
	void display()
	{
		cout << minute << ':' << sec<<endl;
	}
};
istream& operator>>(istream& cin, Time& t)
{
	cin >> t.minute >> t.sec;
	return cin;
}
ostream& operator<<(ostream& cout, Time& t)
{
	cout << t.minute << ':' << t.sec << endl;
	return cout;
}
Time operator++(Time& t1, int)
{
	Time temp(t1);
	t1.sec += 1;
	t1.minute += t1.sec / 60;
	t1.sec %= 60;
	return temp;
}
void operator++(Time& t1)
{
	int t2 = 1;
	t1.sec += t2;
	t1.minute += t1.sec / 60;
	t1.sec %= 60;
}
int main()
{
	Time t1(1, 119),t3;
	t1.display();
	cin >> t1; 
	t1.display();
	++t1; 
	t1.display();
	t3=t1++;
	t3.display();
	t1.display();
	cout << t1;
}*/
//类的继承;
/*#include<iostream>
#include<string>
using namespace std;
class student
{
private:
	int xve;
	char name[20]; 
public:
	student(int x, const char a[]) :xve(x)
	{
		strcpy_s(name, a);
	}
	void display()
	{
		cout << xve << ' ' << name << endl;
	}
};
class student1 : public student//公有继承
{
private:
	int chengji;
public:
	student1(int x,const char a[],int c):student(x,a),chengji(c){}
	void display1()
	{
		display();
		cout << chengji;
	}
};
class student2 : private student//私有继承
{
private:
	int chengji;
public:
	student2(int x, const char a[], int c) :student(x, a), chengji(c) {}
	void display2()
	{
		display();
		cout<< chengji;
	}
};
int main()
{
	student1 a(123,"wangkenan",750);
	student2 b(111,"wangweilin",750);
	a.display1();
	cout << ' ';
	a.display();
	b.display2();//b.display();私有错误 
}*/
//含子对象派生类构造函数;
/*#include<iostream>
#include<string>
using namespace std;
class student
{
private:
	int xve;
	char name[20];
public:
	student(int xve, const char a[]) :xve(xve)
	{
		strcpy_s(name, a);
	}
	void display()
	{
		cout << xve << ' ' << name << endl;
	}
};
class student1:public student
{
private:
	student banzhang;
	int chengji;
public:
	student1(int xve,const char name[],int xve1,const char name1[],int chengji):student(xve,name),banzhang(xve1,name1),chengji(chengji){}
	void display1()
	{
		display();
		cout << chengji << endl;
	}
	void ban()
	{
		banzhang.display();
	}
};
int main()
{
	student1 a(123, "wangkenan", 111, "wangweilin", 750);
	a.display1();
	a.ban();
}*/
//虚基;
/*#include<iostream>
#include<string>
using namespace std;
class people
{
private:
	char name[20];
public:
	people(const char a[])
	{
		strcpy_s(name, a);
	}
	void display()
	{
		cout << "姓名:" << name << endl;
	}
};
class student:virtual public people
{
private:
	int xve;
public:
	student(const char a[],int xve):people(a),xve(xve){}
	void display1()
	{
		display();
		cout <<"学号:" << xve << endl;
	}
};
class xing :virtual public people
{
private:
	int x;
public:
	xing(const char a[],int x):people(a),x(x){}
	void display2()
	{
		cout << "性别(0:女,1:男):" << x << endl;
	}
};
class chengji :public student, public xing
{
private:
	int c;
public:
	chengji(const char a[],int xve,int x,int c):people(a),student(a,xve),xing(a,x),c(c){}
	void display3()
	{
		display1();
		display2();
		cout<<"总分:"<< c;
	}
};
int main()
{
	chengji a("wangkenan", 123, 1, 750);
	a.display3();
	student b("wangweilin", 111);
	student* p;
	cout << endl;
	b.display1();
	b = a;
	p = &a;
	b.display1();
	p->display1();
	return 0;
}*/
//虚函数;
/*#include<iostream>
#include<string>
class student
{
protected:
	int xve;
	char name[20];
public:
	student(int xve, const char a[]) :xve(xve)
	{
		strcpy_s(name, a);
	}
	virtual void display()//虚函数
	{
		std::cout << xve << name << std::endl;
	}
};
class chengji:public student
{
private:
	int fen;
public:
	chengji(int xve,const char a[],int fen):student(xve,a),fen(fen){}
	void display()
	{
		std::cout << xve<<name<<fen << std::endl;
	}
};
int main()
{
	student b(111, "wangweilin");
	chengji a(123, "wangkenan", 750);
	student* p=&b;
	p->display();
	p = &a;
	p->display();
	a.display();
	a.student::display();
}*/
/*#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[108], n, i, sum;
	double c = 0;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> a[i];
		c += a[i];
	}
	i = 0;
	sort(&a[0], &a[n]);
	for (i = 0; i < n; i++)
	{
		cout<< a[i];
	}
	cout << endl;
	i = 0;
	while (c*1.0/n<4.5)
	{
		c -= a[i];
		c += 5;
		i++;
	}
	cout << i;
}*/
/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int i, n, j,sum=0;
vector<int> v, v1, v2;
class com
{
public:
	bool operator()(int a)
	{
		return a >= v1[i];
	}
};
class com1
{
public:
	bool operator()(int a)
	{
		return a > v1[i];
	}
};
int main()
{
	int x;
	cin >> n;
	for (i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	for (i = 0; i < n; i++)
	{
		cin >> x;
		v1.push_back(x);
	}
	sort(v1.begin(), v1.end());
	for (i = 0; i < n; i++)
	{
		cin >> x;
		v2.push_back(x);
	}
	sort(v2.begin(), v2.end());
	i = 0;
	vector<int>::iterator it = find_if(v.begin(), v.end(), com());
	vector<int>::iterator it1 = find_if(v2.begin(), v2.end(), com1());
	while (it!=v.begin()&&it1!=v2.end())
	{
		cout << (it - v.begin()) * (v2.end() - it1) << endl;
		sum = sum + (it - v.begin()) * (v2.end() - it1);
		i++;
		if (i == n)
			break;
		it = find_if(v.begin(), v.end(), com());
		it1 = find_if(v2.begin(), v2.end(), com1());
	}
	cout << sum;
}*/
/*#include<iostream>
#include<algorithm>
using namespace std;
long int n, m, x, y, sum = 0, i;
long int a[100010];
void com(long int x)
{
	cout << x << ' ';
}
int main()
{
	cin >> n >> m;
	for (i = 0; i < n + m + 1; i++)
		cin >> a[i];
	sort(a, &a[n + m + 1]);
	for_each(a, &a[n + m + 1], com);
	sum = a[n + m];
	x = 0;
	y = n + m - 1;
	while (n != 0 || m != 0)
	{
		if (m != 0)
		{
			sum -= a[x];
			x++;
			m--;
		}
		if (n != 0)
		{
			sum += a[y];
			y--;
			n--;
		}
	}
	cout << sum;
}*/
/*#include<iostream>
#include<algorithm>
using namespace std;
long int n, t, w, i, min1, max1;
long int x, y, z;
long int findmin()
{
	while (w + 1 != t)
	{
		if (((w + t) / 2) * (y + 1) > x && ((w + t) / 2) * y <= x)
			t = (w + t) / 2;
		else
			w = (w + t) / 2;
		cout << 1;
	}
	return t;
}
long int findmax()
{
	while (w + 1 != t)
	{
		if (((w + t) / 2) * (y + 1) > x && ((w + t) / 2) * y <= x)
			w = (w + t) / 2;
		else
			t = (w + t) / 2;
		cout << 2;
	}
	return w;
}
int main()
{
	cin >> n;
	cin >> x >> y;
	t = x / (y - 1);
	w = x / (y + 1);
	min1 = w;
	max1 = t;
	z = findmin();
	if (z > min1)
		min1 = z;
	t = max1+1;
	w = min1-1;
	z = findmax();
	if (z < max1)
		max1 = z;
	for (i = 1; i < n; i++)
	{
		t = max1;
		w = min1;
		cin >> x >> y;
		z = findmin();
		if (z > min1)
			min1 = z;
		t = max1;
		w = min1;
		z = findmax();
		if (z < max1)
			max1 = z;
	}
	cout << min1 << ' ' << max1;
}*/
/*#include<iostream>
#include<algorithm>
using namespace std;
long int n, len, l[1000010], s[100010], t, w, max1, i, z, j;
class bian
{
public:
	long int x, y;
};
bian a[100010];
bool com(const bian a, const bian b)
{
	return a.x < b.x;
}
bool check()
{
	z = n;
	j = 0;
	for (i = 0; i < n; i++)
	{
		if ((t + w) / 2 - s[i] < 0)
		{
			z--;
		}
		else
		{
			a[j].x = l[i] - ((t + w) / 2 - s[i]);
			a[j].y = l[i] + ((t + w) / 2 - s[i]);
			j++;
		}
	}
	sort(a, a + j + 1, com);
	if (a[0].x > 1)
		return false;
	max1 = a[0].y;
	for (i = 1; i < j + 1; i++)
	{
		if (a[i].x - 1 > max1)
			return false;
		if (a[i].y > max1)
			max1 = a[i].y;
	}
	if (max1 < len)
		return false;
	return true;
}
int main()
{
	cin >> n >> len;
	for (i = 0; i < n; i++)
		cin >> l[i] >> s[i];
	w = 0;
	t = 10000;
	while (w + 1 != t)
	{
		if (check())
			t = (t + w) / 2;
		else
			w = (t + w) / 2;
		cout << t << endl;
	}
	cout << t << w;
	return 0;
}*/
/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class people
{
public:
	char name;
	int age;
	people(char name,int age):name(name),age(age){}
	void display()
	{
		cout << this->name << ' ' << this->name << endl;
	}
};
class com
{
public:
	bool operator()(const pair<char,int>& a, const pair<char,int>& b)
	{
		return a.second < b.second;
	}
};
void coml(const pair<char,int>& a)
{
	cout << a.first << ' ' << a.second << endl;
}
int main()
{
	int b;
	int g[26] = { 12,43,5,26,43,42,423,455,23,53,34,53,64,76,87,64,46,46,12,32,12,56,34,67,35,24 };
	vector<pair<char,int>> a;
	for (int i =65; i <=90; i++)
	{
		b = g[i - 65];
		a.push_back({i,b});
	}
	sort(a.begin(), a.end(), com());
	for_each(a.begin(), a.end(), coml);
}*/
/*#include<iostream>
#include<algorithm>
using namespace std;
int n, i, a[10], b[10], c[10], d[10], sum = 0, t = 1, w = 1, m = 1;
void wei(int j)
{
	if (j >= 10)
	{
		int s = j / 10 * 10;
		a[t] = j - s;
		t++;
		wei(j / 10);
	}
	else
		a[t] = j;
}
void wei0(int j)
{
	if (j >= 10)
	{
		int s = j / 10 * 10;
		b[w] = j - s;
		w++;
		wei0(j / 10);
	}
	else
		b[w] = j;
}
void wei1(int j)
{
	if (j >= 10)
	{
		int s = j / 10 * 10;
		c[m] = j - s;
		m++;
		wei1(j / 10);
	}
	else
		c[m] = j;
}
void check()
{
	int sum = 0, x = 1;
	for (int j = 1;; j++)
	{
		t = 1, w = 1, m = 1;
		wei(j);
		wei0(n * j - i * j);
		wei1(i);
		if (t + w + m > 9)
			break;
		sum = 0;
		if (t + w + m == 9)
		{
			sum = -1;
			x = 1;
			for (int y = 1; y <= t; y++)
			{
				d[x] = a[y];
				x++;
			}
			for (int y = 1; y <= w; y++)
			{
				d[x] = b[y];
				x++;
			}
			for (int y = 1; y <= m; y++)
			{
				d[x] = c[y];
				x++;
			}
			sort(d + 1, d + 10);
			if (d[1] == 0)
				sum = 1;
			for (int y = 2; y < 10; y++)
			{
				if (d[y] == d[y - 1] || d[y] == 0)
					sum = 1;
			}
		}
		if (sum == -1 && t + w + m == 9)
		{
				::sum++;
				for (int y = m; y >=1; y--)
				{
					cout << c[y];
				}
				cout << '+';
				for (int y = w; y >=1; y--)
				{
					cout << b[y];
				}
				cout << '/';
				for (int y = t; y >=1; y--)
				{
					cout << a[y];
				}
				cout << endl;
		}
	}
}
int main()
{
	cin >> n;
	for (i = 1; i < n; i++)
	{
		check();
	}
	cout << sum;
}*/
/*#include<iostream>
#include<algorithm>
using namespace std;
long int a[100010], b[100010], c[100010];
long int n;
char x;
void chushi(long int a[])
{
	for (int i = 0; i <= n + 1; i++)
		a[i] = 1;
}
int main()
{
	cin >> x;
	a[0] = 1;
	for (int i = 1;; i++)
	{
		cin >> a[i] >> x;
		if (x == ']')
		{
			n = i;
			break;
		}
	}
	a[n + 1] = 1;
	chushi(b);
	chushi(c);
	for (int i = 1; i <= n; i++)
	{
		b[i] = b[i - 1] * a[i - 1];
	}
	for (int i = n; i >= 1; i--)
	{
		c[i] = c[i + 1] * a[i + 1];
	}
	cout << '[';
	for (int i = 1; i <= n; i++)
	{
		cout << b[i] * c[i];
		if (i != n)
			cout << ',';
	}
	cout << ']';
}*/
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
string a, b;
vector<string> zidian;
int c[10010][2];
int n;
int main()
{
	cin >> a;
	n = a.size();
	n--;
	c[n][0] = 0;
	c[n][1] = 0;
	for (int i = n - 1; i > 4; i--)
	{
		if (i + 1 <= n)
		{
			if (i + 1 == n)
			{
				b = { a[i],a[i + 1] };
				zidian.push_back(b);
				c[i][0] = 1;
			}
			else
			{
				if (c[i + 2][0] == 0 && c[i + 2][1] == 0)
					c[i][0] = 0;
				else if (a[i] == a[i + 2] && a[i + 1] == a[i + 3] && c[i + 2][1] == 0)
					c[i][0] = 0;
				else
				{
					b = { a[i],a[i + 1] };
					zidian.push_back(b);
					c[i][0] = 1;
				}
			}
		}
		if (i + 2 <= n)
		{
			if (i + 2 == n)
			{
				b = { a[i],a[i + 1],a[i + 2] };
				zidian.push_back(b);
				c[i][1] = 1;
			}
			else
			{
				if (c[i + 3][0] == 0 && c[i + 3][1] == 0)
					c[i][1] = 0;
				else if (a[i] == a[i + 3] && a[i + 1] == a[i + 3] && a[i + 2] == a[i + 4] && c[i + 3][0] == 0)
					c[i][1] = 0;
				else
				{
					b = { a[i],a[i + 1],a[i + 2] };
					zidian.push_back(b);
					c[i][1] = 1;
				}
			}
		}
	}
	sort(zidian.begin(), zidian.end());
	cout<<zidian[0]<<endl;
	for (int i = 1; i < zidian.size(); i++)
	{
		if (zidian[i] != zidian[i - 1])
		{
			cout << zidian[i];
			if (i != zidian.size() - 1)
				cout << endl;
		}
	}
}