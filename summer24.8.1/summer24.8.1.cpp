//欧拉函数的sigma函数
#include<iostream>
#include<math.h>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> notprime;
vector<ll> prime;
void getprime(int n)
{
	notprime.resize(n + 1, 0);
	for (ll i = 2; i <= n; i++)
	{
		if (notprime[i] == 0)
		{
			for (ll j = 2; i * j <= n; j++)
			{
				notprime[i * j] = 1;
			}
		}
		if (notprime[i] == 0)
		{
			prime.push_back(i);
		}
	}
}
int main()
{
	while(1)
	{
		int n;
		int m;
		cout << "是否为平方形式？" << endl;
		int judge;
		cin >> judge;
		if (judge)
		{
			cin >> n >> m;
			ll s = pow(n, m);
			getprime(s);
			bool j=false;
			for (ll f = 0; f < prime.size() && n >= prime[f]; f++)
			{
				if (n == prime[f])
				{
					j = 1;
					break;
				}
			}
			if (j)
			{
				cout << pow(n, m) - pow(n, m - 1) << endl;
			}
			else
			{
				vector<ll> dp;
				for (ll i = 0; i < prime.size(); i++)
				{
					if (s % prime[i] == 0)dp.push_back(prime[i]);
				}
				double sum = s;
				for (ll i = 0; i < dp.size(); i++)
				{
					sum *= 1.0 - (1.0 / dp[i]);
				}
				cout << sum << endl;
			}
		}
		else
		{
			cin >> n;
			getprime(n);
			vector<ll> dp;
			for (ll i = 0; i < prime.size(); i++)
			{
				if (n % prime[i] == 0)dp.push_back(prime[i]);
			}
			double sum = n;
			for (ll i = 0; i < dp.size(); i++)
			{
				sum *= 1.0 - (1.0 / dp[i]);
			}
			cout << sum << endl;
		}
	}
}