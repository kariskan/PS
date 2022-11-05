#include <iostream>
using namespace std;

typedef struct room
{
	int start;
	int end;
	int num;
};

int n, dp[100001][2];
room a[100001];

int go(int i, int j)
{
	if (i > n)
	{
		return 0;
	}
	if (dp[i][j])
	{
		return dp[i][j];
	}
	int res = 0;
	if (j == 0)
	{
		res = max(go(i + 1, 0), go(i + 1, 1) + a[i].num);
	}
	else
	{
		res = go(i + 1, 0);
	}
	return dp[i][j] = res;
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].start >> a[i].end >> a[i].num;
	}

	cout << max(go(1, 0), go(1, 1));
}