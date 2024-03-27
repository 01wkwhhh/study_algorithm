#include<stdio.h>
#include<time.h>
int main()
{
	int a, b,c=6,i,d=0,e=100,les=1,sum=1,j=0;
	srand(time(NULL));
	a = rand() % 100;
	printf("欢迎游玩屎山猜数字游戏!\n*******************************\n");
	printf("是否打开辅助器?(打开0,不打开1)\n");
	scanf("%d", &les);
	if (les == 0)
	{
		printf("是否打开推荐功能?(打开0,不打开1)\n");
		scanf("%d", &sum);
	}
	for (i = 0;i<c; i++)
	{
		printf("剩余猜测次数:%d\n", c-i);
		if (les == 0)
		{
			printf("猜测范围为:%d-%d\n", d, e);
			if (sum == 0)
			{
				if (i != 5)
					printf("推荐猜测:%d\n", (d + e) / 2);
				else
				{
					if (j == 5)
					{
						printf("哦不!你把它变成了输入数字的游戏,你确定还要提示吗?(要0,不要1)\n");
						scanf("%d", &sum);
					}
					if(sum==0)
						printf("推荐猜测:%d\n", a);
				}
			}
		}
		printf("请输入你猜的数字:\n");
		scanf("%d", &b);
		if (b == (d + e) / 2)
			j++;
		if (b > a)
		{
			printf("大了!\n");
			e = b;
		}
		else if (b < a)
		{
			printf("小了!\n");
			d = b;
		}
		else
		{
			printf("恭喜你猜对了!!!");
			break;
		}
	}
	if (i == c)
	{
		if (sum == 0)
			printf("你不信推荐功能,你打开它干嘛?@_@\n");
		printf("下次走运!!!\n正确答案为:%d", a);
	}
	return 0;
}
