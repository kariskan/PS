#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

pair<int, int> inp[101];
int dp[100001];

int main()
{
	for (int t = 0; t < 3; t++)
	{
		int n, sum = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> inp[i].first >> inp[i].second;
			sum += inp[i].first * inp[i].second;
		}
		sort(inp + 1, inp + n + 1);
		dp[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= sum; j++)
			{
				if (dp[j] != i + 1 && dp[j] != 0)
				{
					for (int k = 1; k <= inp[i].second; k++)
					{
						if (dp[j + inp[i].first * k] == 0)
						{
							dp[j + inp[i].first * k] = i + 1;
						}
					}
				}
			}
		}
		if (sum % 2 == 0 && dp[sum / 2] != 0)
		{
			cout << "1\n";
		}
		else
		{
			cout << "0\n";
		}
		memset(inp, 0, sizeof(inp));
		memset(dp, 0, sizeof(dp));
	}
}
