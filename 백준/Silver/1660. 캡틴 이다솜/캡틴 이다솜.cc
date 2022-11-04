#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

int dp[300001], a[200];

int go(int n)
{
	if (n <= 0)
		return 0;
	if (dp[n] != -1)
	{
		return dp[n];
	}
	int res = INT_MAX;
	for (int i = 1; i < 200; i++)
	{
		if(n - a[i] < 0) break;
		res = min(res, 1 + go(n - a[i]));
	}
	return dp[n] = res;
}

int main()
{
	int s = 0;
	int pre = 0;
	int pre2 = 0;

	memset(dp, -1, sizeof(dp));

	for (int i = 1; i < 200; i++)
	{
		s++;
		pre += s;
		pre2 += pre;
		a[i] = pre2;
		if (pre2 > 300000)
			break;
		dp[pre2] = 1;
	}

	int n;
	cin >> n;

	cout << go(n);

	return 0;
}