//容器vector的简单使用;
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void com(int i)
{
	cout << i << ' ';
}
int main()
{
	vector<int> a;
	int c[3] = { 1,2,3 };
	for(int i=0;i<=4;i++)
		a.push_back(i);
	vector<int>::iterator b = a.begin();
	for (; b != a.end(); b++)
		cout << *b << ' ';
	cout << endl;
	for_each(c, c+3, com);
	cout << endl;
	for_each(a.begin(),a.end(), com);
	return 0;
}*/
//vector的嵌套;
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int p=0;
void com1(int a)
{
	p++;
	cout << a << ' ';
	if (p == 9)
		cout << endl;
}
void com(vector<int> a)
{
	for_each(a.begin(), a.end(), com1);
}
int main()
{
	vector<vector<int>> a;
	vector<int> b[3];
	for (int i = 0; i < 3; i++)
	{
		b[0].push_back(i);
		b[1].push_back(i + 3);
		b[2].push_back(i + 6);
	}
	for (int i = 0; i < 3; i++)
		a.push_back(b[i]);
	for_each(a.begin(), a.end(), com);
	int i = 0;
	for (vector<vector<int>>::iterator d = a.begin(); d != a.end(); d++)
		for (vector<int>::iterator e = (*d).begin(); e != (*d).end(); e++)
		{
			cout << *e << ' ';
		}
		return 0;
}*/
//string的赋值;
/*#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str,str1;
	str1 = "Hello world!";
	str.assign(str1,0,7);
	cout << str;
	return 0;
}*/
//string的查找以及对比;
/*#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a = "nihaoaihahahaaide",b=a;
	int c=a.find("ai");
	cout << "find=" << c << "rfind="<<a.rfind("ai")<<endl;
	cout << a.compare(b)<<endl;
	a.replace(0, 5, "Hello world!");
	cout << a<<endl;
	cout<<a.compare(b)<<endl;
	cout << b.compare(a);
	return 0;
}*/
//string中通过at访问单个字符;
/*#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a = "hello world!";
	for (int i = 0; i < a.size(); i++)
		cout << a.at(i);
		return 0;
}*/
//字符串的插入(insert)和删除(erase);
/*#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a = "Hello  world!";
	a.insert(5, " ");
	cout << a<<endl;
	a.erase(5, 2);
	cout << a;
	return 0;
}*/
//string的截取;
/*#include<iostream>
#include<string>
using namespace std;
int main()
{
	string a = "zhangsan@12345";
	string a1 = a.substr(a.find("@"));
	cout << a1;
	return 0;
}*/
//关于我学的vector;
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void com(int x)
{
	cout << x << ' ';
}
void print(vector<int>& v)
{
	for_each(v.begin(), v.end(), com);
	cout << endl;
}
int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	print(v);
	cout << v.size() << endl;
	v.resize(16, 5);
	print(v);
	v.insert(v.begin() + 3, 5);
	print(v);
	v.erase(v.begin() + 1, v.end() - 1);
	print(v);
	v.pop_back();
	print(v);
	v.clear();
	print(v);
	return 0;
}*/
//vector的单个成员读取;
/*#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void print(const vector<int>& v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << ' ';
	cout << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << ' ';
	cout << endl;
	cout << v.front() << ' ' << v.back() << endl;
}
int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	print(v);
	return 0;
}*/
//巧用swap收缩vector容器大小;
/*#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v;
	for (int i = 0; i < 10000; i++)
		v.push_back(i);
	cout << "当前容器大小:" << v.capacity() << endl;
	v.resize(100);
	vector<int>(v).swap(v);
	cout << "当前容器大小:" << v.capacity() << endl;
}*/
//利用reserve为vactor容器预留空间;
/*#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> v,v1;
	int num=0, num1=0,*p=NULL,*p1=NULL;
	v1.reserve(10000);
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		v1.push_back(i);
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
		if (p1 != &v1[0])
		{
			p1 = &v1[0];
			num1++;
		}
	}
	cout << num << ' ' << num1;
}*/
//sort排序;
/*#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void com(int x)
{
	cout << x << ' ';
}
void print(vector<int>& v)
{
	for_each(v.begin(), v.end(), com);
	cout << endl;
}
int main()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(12);
	v.push_back(3);
	v.push_back(6);
	v.push_back(9);
	v.push_back(23);
	print(v);
	sort(v.begin(), v.end());
	print(v);
}*/
//stack(栈)容器;
/*#include<iostream>
#include<stack>
using namespace std;
int main()
{
	stack<int> a;
	for(int i=0;i<10;i++)
		a.push(i);
	while (!a.empty())
	{
		cout << a.top() << ' ';
		a.pop();
	}
}*/
//list;
/*#include<iostream>
#include<algorithm>
#include<list>
using namespace std;
void com(int x)
{
	cout << x << ' ';
}
void print(const list<int>& a)
{
	for_each(a.begin(), a.end(), com);
	cout << endl;
}
int main()
{
	list<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
	print(a);
	a.assign(9, 10);
	print(a);
}*/
//sort函数给数组排序;
/*#include<iostream>
#include<algorithm>
using namespace std;
bool com(int a, int b)
{
	return a > b;
}
int main()
{
	int a[10];
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	cout << *(a + 9) << endl;
	sort(a, a+10,com);//有第三个参数less<int>()(从小到大排序),greater<int>()(从大到小排序)
	for (int i = 0; i < 10; i++)
		cout << a[i] << ' ';
}*/
//list用法;
/*#include<iostream>
#include<algorithm>
#include<list>
#include<string>
using namespace std;
class person
{
public:
	string name;
	int age;
	int hight;
	person(string na,int a,int b):name(na),age(a),hight(b){}
};
void com(person& a)
{
	cout << "名字:" << a.name << "年龄:" << a.age << "身高:" << a.hight << endl;
}
void print(list<person>& a)
{
	for_each(a.begin(), a.end(), com);
}
bool comp(person& a, person& a1)
{
	if (a.age == a1.age)
		return a.hight < a1.hight;
	return a.age < a1.age;
}
int main()
{
	person p1("wangkenan", 19, 180), p2("wangweilin", 25, 168), p3("hhh", 34, 178), p4("hfy", 23, 174), p5("ahgdu", 19, 176), p6("hii", 16, 170);
	list<person> a;
	a.push_back(p1);
	a.push_back(p2);
	a.push_back(p3);
	a.push_back(p4);
	a.push_back(p5);
	a.push_back(p6);
	print(a);
	a.sort(comp);
	cout << "**********************************" << endl;
	print(a);
}*/
//关于我学的那些算法;
/*#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
bool myfind(int val)
{
	return val > 5;
}
int com(int a)
{
	return a + 200;
}
class b
{
public:
	int operator()(int a)
	{
		return a + 200;
	}
};
class c
{
public:
	int xve;
	string name;
	c(int xve,const string name):xve(xve),name(name){}
	bool operator==(const c& a)
	{
		if (xve == a.xve && name == a.name)
			return true;
		return false;
	}
};
void coml(int a)
{
	cout << a<<' ';
}
int main()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
		v.push_back(i);
	vector<int> v1;
	v1.resize(10);
	transform(v.begin(), v.end(), v1.begin(), b());//transform,b仿函数
	for_each(v.begin(), v.end(), coml);
	cout << endl; 
	for_each(v1.begin(), v1.end(), coml);
	vector<int>::iterator it=find(v.begin(), v.end(), 2000);//find普通
	if (it == v.end())
		cout <<endl<< "没有找到!" << endl;
	else
	cout << endl << *it << endl;
	vector<c> v2;
	c a1(111, "aaa");
	c a2(222, "bbb");
	c a3(333, "ccc");
	c a4(444, "ddd");
	v2.push_back(a1);
	v2.push_back(a2);
	v2.push_back(a3);
	v2.push_back(a4);
	vector<c>::iterator it1 = find(v2.begin(), v2.end(), a2);//find自定义
	if (it1 == v2.end())
		cout << "没找到" << endl;
	else
		cout << it1->xve << " "<<it1->name << endl;
	it=find_if(v.begin(), v.end(), myfind);
	if (it == v.end())
		cout << "没有找到!" << endl;
	else
		cout << *it << endl;
}*/
//adjacent_find
/*#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(1);
	v.push_back(5);
	v.push_back(5);
	v.push_back(6);
	v.push_back(5);
	v.push_back(5);
	v.push_back(4);
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	cout << *it << ' ' << *(it + 2)<<endl;
    it = adjacent_find(it+1, v.end());
	cout << *it << ' ' << *(it + 2);
}*/
//关于我初学dp学不懂的那些事
/* #include<iostream>
#include<algorithm>
using namespace std;
int n,i,c,w[100]={0},p[100]={0},f[100][100]={0};
int k(int i,int z)
{
   if(i==n)
   return w[i]>z?0:p[i];
   if(z<w[i])
   return k(i+1,z);
   return max(k(i+1,z),k(i+1,z-w[i])+p[i]);
}
int main()
{
    cin>>n>>c;
    for(i=1;i<=n;i++)
    {
       cin>>w[i];
    }
    for(i=1;i<=n;i++)
    cin>>p[i];
    c=k(1,c);
    cout<<c;
} */
//关于我学到的双指针
/*#include<iostream>
#include<algorithm>
using namespace std;
int a[100010],n,h,l,t,w,i,j;
bool com(int a,int b)
{
    return a>b;
}
int main()
{
    cin>>n>>l;
    for(i=1;i<=n;i++)
    cin>>a[i];
    sort(a+1,a+n+1,com);
    h=n;
    t=n;
    for(i=0;i<=n;i++)
    {
        if(a[i+1]<h)
        {
            w=i;
            break;
        }
    }
    for(;t>0;)
    {
     if(a[t]>=h-1&&t-w<=l)
     break;
     t--;
     h=t;
     while(a[w+1]>=h&&h>0)
     {
         w++;
     }
    }
    cout<<h;
}*/
//值得我纪念的代码(哈哈应该是这样)
/*#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
string a,b;
vector<string> zidian;
int c[10010][2];
int n,sum=0;
int main()
{
    cin>>a;
    n=a.size();
    n=n-1;
    c[n][0]=0;
    c[n][1]=0;
    for(int i=n-1;i>4;i--)
    {
        if(i+1<=n)
        {
            if(i+1==n)
            {
                b={a[i],a[i+1]};
                zidian.push_back(b);
                c[i][0]=1;
            }
            else
            {
                if(c[i+2][0]==0&&c[i+2][1]==0);
                else if(a[i]==a[i+2]&&a[i+1]==a[i+3]&&c[i+2][1]==0);
                else
                {
                    b={a[i],a[i+1]};
                    zidian.push_back(b);
                    c[i][0]=1;
                }
            }
        }
        if(i+2<=n)
        {
            if(i+2==n)
            {
                b={a[i],a[i+1],a[i+2]};
                zidian.push_back(b);
                c[i][1]=1;
            }
            else
            {
                if(c[i+3][0]==0&&c[i+3][1]==0);
                else if(a[i]==a[i+3]&&a[i+1]==a[i+3]&&a[i+2]==a[i+4]&&c[i+3][0]==0);
                else
                {
                    b={a[i],a[i+1],a[i+2]};
                    zidian.push_back(b);
                    c[i][1]=1;
                }
            }
        }
    }
    sort(zidian.begin(),zidian.end());
    if(zidian.size()!=0)
    sum++;
    for(int i=1;i<zidian.size();i++)
    {
        if(zidian[i]!=zidian[i-1])
        sum++;
    }
    cout<<sum<<endl;
    if(zidian.size()!=0)
    {
    cout<<zidian[0]<<endl;
    for(int i=1;i<zidian.size();i++)
    {
        if(zidian[i]!=zidian[i-1])
        cout<<zidian[i]<<endl;
    }
    }
}*/
/*#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int z = 0;
	int a[80];
	for (int i = 80; i > 0; i--)
	{
		a[z++] = i;
	}
	for (int i = 0; i < 80; i++)
		cout << a[i] << ' ';
	cout << endl;
	sort(a, a + 80);
	for (int i = 0; i < 80; i++)
		cout << a[i]<<' ';
}*/
/*#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main() {
	int x, y;
	cin >> x >> y;
	int cnt = 0; // 用于计数回文素数的数量  

	for (int i = x; i <= y; i++) {
		bool isPrime = true;

		// 判断素数  
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				isPrime = false;
				break;
			}
		}

	if (isPrime) {
			int temp = i;
			int reversed = 0; // 用于存储 i 的反转值  

			// 反转整数  
			while (temp > 0) {
				int temp1 = temp % 10;
				reversed = reversed * 10 + temp1;
				temp = temp / 10;
			}

			// 检查是否为回文素数  
			if (i == reversed) {
				cout << i << endl;
			}
		}
	}
	return 0;
}*/
/*#include<iostream>
using namespace std;
int shequ(int a, int m)
{
	double b = (a - m) * 1.0 / (m - 1);
	b = b - (a - m) / (m - 1);
	if (b > 0.4)
		return (a - m) / (m - 1) + 1;
	else
		return (a - m) / (m - 1);
}
int main()
{
	int a = 21, x = 2, m = 11, u = 1,x0=1;
	char o = '@';
	cout << "    欢迎使用屎山正比例直线生成器!\n";
	cout << "************************************\n";
	cout << "是否更换图标?默认为@。(0.否,1.是)\n";
	cin >> u;
	if (u == 1)
	{
		cout << "请输入你喜欢的样式:";
		cin >> o;
	}
	else
		u = 1;
	for (int y = 0;; y++)
	{
		if (u == 1)
		{
			if (x0 != 2)
			{
				cout << "是否采用默认设置?(0.否,1.是,2.否且不再询问,-1.退出)\n";
				cin >> u, x0 = u;
			}
			else
				cout<<"任意数字继续,-1退出\n",cin >> u;
			if (u == -1)
				break;
			if (u == 0||x0==2)
			{
				cout << "请设置长度:";
				cin >> a;
				cout << "请设置宽度:";
				cin >> m;
				cout << "请设置间隔:";
				cin >> x;
				if (x == 0)
				{
					cout << "间隔不可为0,已改为默认1!\n";
					x = 1;
				}
			}
			else
				a = 21, x = 2, m = 11;
			u = 1;
		}
		for (int i = 0; i < m * x; i += x)
		{
			for (int j = 0; j < a - 1 - i; j++)
				cout << ' ';
			cout << o << endl;
		}
		if (u == 1 && x != shequ(a,m) + 1)
		{
			cout << "是否对角线化?(0.否,1.是)\n";
			cin >> u;
			if (u == 1)
				x = shequ(a,m) + 1, u = 0;
			else
				u = 1;
		}
		else
			u = 1;
	}
	cout << "************************************" << endl;
	cout << "          欢迎下次使用!" << endl;;
	return 0;
}*/
//kmp(在a字符串中快速找到和b匹配的个数)
/*#include<iostream>
#include<cstring>
using namespace std;
string a,b;
int kmp[100010];
int n = 0;
int main()
{
	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	for (int i = 2, j = 0; i <= b.size()-1; i++)
	{
		while (j && b[i] != b[j + 1])j = kmp[j];
		if (b[i] == b[j + 1])
			j++;
		kmp[i] = j;
	}
	for (int i = 1,j=0; i <= a.size()-1; i++)
	{
		while (j && a[i] != b[j + 1])j = kmp[j];
		if (a[i] == b[j + 1])
			j++;
		if (j == b.size() - 1)
			cout << i - j + 1 << ' ' << i<<endl, n++, j = kmp[j];
	}
	cout << n;
}*/
//Trie(高效的存储和查找字符串)
/*#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string a;
int Trie[100][26], cnt[100], idx = 0;
void charu(string& a)
{
	int p = 0;
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] < 'a' || a[i]>'z')
			break;
		int x = a[i] - 'a';
		if (!Trie[p][x])
		{
			Trie[p][x] = ++idx;
			if (idx > 99)
			{
				Trie[p][x] = 0;
				cout << "空间不足,插入失败!" << endl;
				if (i > 0)
					cout << "当前插入到" << a[i - 1] << ",第" << i << "个字符!" << endl, cnt[p]++;
				return;
			}
		}
		p = Trie[p][x];
	}
	cnt[p]++;
	cout << "成功!" << endl;
	return;
}
int search(string& a)
{
	int p = 0;
	for (int i = 0; i < a.size(); i++)
	{
		int x = a[i] - 'a';
		if (!Trie[p][x])
			return 0;
		p = Trie[p][x];
	}
	return cnt[p];
}
int main()
{
	int x;
	printf("             欢迎使用屎山字符串字典生成器!\n");
	printf("用户须知:\n");
	printf("     1.用户请按照系统所给的指示输入!\n");
	printf("     2.本生成器默认内存为99个字符!\n");
	printf("     3.输入-1自行退出程序!\n");
	printf("                                     ----简约而不简单。\n");
	printf("******************************************************\n");
	for (int i = 0;; i++)
	{
		printf("1.插入,2.查询,3.内存。\n");
		cin >> x;
		if (x == 1)
		{
			cout << "输入字符:";
			cin >> a;
			if (a == "能干嘛")
				printf("那可多了\n1.登录系统的密码录入和比对\n2.简单的存储和查找\n3.此处省略1000+条\n");
			else
				charu(a);
		}
		else if (x == 2)
		{
			cout << "查找目标:";
			cin >> a;
			cout << "当前字典中该字符串出现" << search(a) << "次!" << endl;
		}
		else if (x == 3)
		{
			cout << "存储空间:" << min(99, idx) << "/" << 99 << endl;
		}
		else
			break;
	}
	printf("******************************************************\n");
	printf("                  欢迎下次使用!");
	return 0;
}*/
//并查集(1.将两个集合合并,2.询问两个元素是否在一个集合当中)
/*#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int b[100010];
int find(int x)
{
	if (b[x] != x)b[x] = find(b[x]);
	return b[x];
}
int main()
{
	char a;
	int c, d,n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> c, b[c] = c;
	for (int m = 0;; m++)
	{
		cin >> a;
		cin >> c >> d;
		if (a == 'M')
			b[find(c)] = find(d);
		else
		{
			find(c) == find(d) ? cout << "yes" << endl : cout << "no" << endl;
		}
	}
}*/
//复习kmp
/*#include<iostream>
#include<cstring>
using namespace std;
int kmp[100010];
int main()
{
	int n = 0;
	string a, b;
	cin >> a >> b;
	a = ' ' + a;
	b = ' ' + b;
	for (int i = 2,j=0; i < b.size(); i++)
	{
		while (j && b[i] != b[j + 1])j = kmp[j];
		if (b[i] == b[j + 1])
			j++;
		kmp[i] = j;
	}
	for (int i = 1, j = 0; i < a.size(); i++)
	{
		while (j && a[i] != b[j + 1])j = kmp[j];
		if (a[i] == b[j + 1])
			j++;
		if (j == b.size() - 1)
			n++, cout << i - j + 1 << ' ' << i << endl,j=kmp[j];
	}
	cout << n;
}*/
//来学点新东西
/*#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> p;
	for (int i = 0; i < 100; i++)
		p.push_back(i);
	for (int i : p)
		cout << i << ' ';
}*/
//堆(1.插入一个数,2.求集合中最小值,3.删除最小值,4.删除任意元素,5.改变任意元素)
//数组模拟二叉树左子树为2x右子树为2x+1
//1.heap[++size]=x;up(size);
//2.heap[1]
//3.heap[1]=heap[size];size--;down(1)
//4.heap[k]=heap[size];size--;down(k);up(k);
//5.heap[k]=x;diwn[k];up[k];
//6.建立堆:for(int i=size/2;i;i--)down(i);时间复杂度:O(n)
//7.运用:堆排序
/*#include<iostream>
#include<algorithm>
using namespace std;
int heap[100010],s=1;
void down(int x)
{
	int t=x;
	if (2 * x <= s && heap[2*x] < heap[t])t = 2 * x;
	if (2 * x + 1 <= s && heap[2 * x + 1] < heap[t])t = 2 * x + 1;
	if (t != x)
		swap(heap[x], heap[t]), down(t);
	return;
}
void up(int x)
{
	while (x / 2 && heap[x / 2] > heap[x])
	{
		swap(heap[x], heap[x / 2]);
			x /= 2;
	}
}
int main()
{
	int n;
	cin >> n;
	s = n;
	for (int i = 1; i <= n; i++)
		cin >> heap[i];
	for (int i = s / 2; i > 0; i--)
		down(i);
	while (s)
	{
		cout << heap[1] << ' ';
		if (s > 0)
			heap[1] = heap[s--];
		down(1);
	}
	return 0;
}*/
//hash表(拉链法)
/*#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10003;//为质数重合概率越小
int h[N], e[N+1], ne[N+1],idx=1;
void insert(int x)
{
	int k = (x % N + N) % N;
	e[idx] = x, ne[idx] = h[k], h[k] = idx++;
	return;
}
bool find(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != 0; i = ne[i])
		if (e[i] == x)
			return true;
	return false;
}
int main()
{
	char a;
	int n;
	int x;
	cin >> n;
	while (n--)
	{
		cin >> a >> x;
		if (a == 'I')
			insert(x);
		else
			if (find(x))
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
	}
	return 0;
}*/
//hash表(开放寻址法)
/*#include<iostream>
#include<cstring>
using namespace std;
const int N = 20003, null = 0x3f3f3f3f; //无穷大
int h[N];
int find(int x)
{
	int k = (x % N + N) % N;
	while (h[k] != null && h[k] != x)
	{
		k++;
		if (k == N)
			k = 0;
	}
	return k;
}
int main()
{
	char a;
	int n;
	int x,k;
	cin >> n;
	memset(h, 0x3f, sizeof h);//0,-1,0x3f->0x3f3f3f3f
	while (n--)
	{
		cin >> a >> x;
		k = find(x);
		if (a == 'I')
			h[k]=x;
		else
			if (h[k]==x)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
	}
	return 0;
}*/
//字符串hash
//将字符串每位看成p进制(经验值131或者13331)mod取2的64次方,大多数情况没有冲突
//高位(0)->低位(a.size())
#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010, P = 131;
typedef unsigned long long LL;
string a;
LL h[N],p[N];
LL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r-l+1];
}
int main()
{
	int n;
	cin >> a >> n;
	a = ' ' + a;
	p[0] = 1;
	for (int i = 1; i < a.size(); i++)
	{
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + a[i];
	}
	while (n--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (get(x1, y1) == get(x2, y2))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}