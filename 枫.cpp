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
#include<iostream>
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
}
