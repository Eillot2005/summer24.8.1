
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
using namespace std;
int arr1[1000000];
inline int gcd(int a, int b)
{
	return b ? gcd(b, a % b) : a;
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			arr1[i] = 0;
			int temp;
			scanf("%d", &temp);
			arr1[temp] = 1;
		}
		while (m--)
		{
			int num;
			scanf("%d", &num);
			int g = 0;
			for (int i = 1; i * num <= n; i++)
			{
				if (arr1[i * num])
				{
					g = gcd(g, i * num);
					if (g == num)
					{
						printf("YES\n");
						break;
					}
				}
			}
			if (g != num)printf("NO\n");
		}
	}
}
