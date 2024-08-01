//错误代码
#include<iostream>
using namespace std;
int extend_gcd(int a, int b, int &x, int &y)
{
	if (!b)
	{
		x = 1;
		y = 0;
		return a;
	}
	else
	{
		int etdgcd = extend_gcd(b, a % b, x, y);
		int temp = x;
		x = y;
		y = temp - (a / b) * y;
		return etdgcd;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		sum += temp;
	}
	int x, y;
	int a = n;
	int b = n * (n + 1) / 2;
	int g1 = extend_gcd(a, b, x, y);
	int k, t;
	int g2 = extend_gcd(g1, m, k, t);
	int z = (m - sum % m) / g2;
	k = (k * z) % m;
	x = x * k;
	y = y * k;
	cout << z << endl;
	cout << x << " " << y << endl;
}