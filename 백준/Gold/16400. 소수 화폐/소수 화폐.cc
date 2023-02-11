#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int a[40001], dp[40001];
vector<int> prime;

int main()
{
	int n;
	cin >> n;
	for (int i = 2; i * i <= 40000; i++)
	{
		if (!a[i])
		{
			for (int j = i * i; j <= 40000; j += i)
			{
				a[j] = 1;
			}
		}
	}
	for (int i = 2; i <= 40000; i++)
	{
		if (!a[i])
		{
			prime.push_back(i);
		}
	}
	int mod = 123456789;
	dp[0] = 1;
	for (int i = 0; i < prime.size(); i++)
	{
		for (int j = prime[i]; j <= n; j++)
		{
			dp[j] = (dp[j] % mod + dp[j - prime[i]] % mod) % mod;
		}
	}

	cout << dp[n];
}