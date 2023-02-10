#include <iostream>
using namespace std;

int minDp[5][5], maxDp[5][5];
char a[5][5];

// s: 이전 dp 값, a: 연산자, b: 피연산자
int calc(int s, char c, char b)
{
	if (c == '+')
	{
		return s + (b - '0');
	}
	if (c == '-')
	{
		return s - (b - '0');
	}
	return s * (b - '0');
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	}
	minDp[0][0] = maxDp[0][0] = a[0][0] - '0';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == 0 && j == 0)
			{
				continue;
			}
			if ((i + j) % 2 != 0)
			{
				continue;
			}
			else
			{
				if (j == 0)
				{
					minDp[i][j] = calc(minDp[i - 2][j], a[i - 1][j], a[i][j]);
					maxDp[i][j] = calc(maxDp[i - 2][j], a[i - 1][j], a[i][j]);
				}
				else if (i == 0)
				{
					minDp[i][j] = calc(minDp[i][j - 2], a[i][j - 1], a[i][j]);
					maxDp[i][j] = calc(maxDp[i][j - 2], a[i][j - 1], a[i][j]);
				}
				else
				{
					minDp[i][j] = min(calc(minDp[i - 1][j - 1], a[i][j - 1], a[i][j]), calc(minDp[i - 1][j - 1], a[i - 1][j], a[i][j]));
					maxDp[i][j] = max(calc(maxDp[i - 1][j - 1], a[i][j - 1], a[i][j]), calc(maxDp[i - 1][j - 1], a[i - 1][j], a[i][j]));
					if (i >= 2)
					{
						minDp[i][j] = min(minDp[i][j], calc(minDp[i - 2][j], a[i - 1][j], a[i][j]));
						maxDp[i][j] = max(maxDp[i][j], calc(maxDp[i - 2][j], a[i - 1][j], a[i][j]));
					}
					if (j >= 2)
					{
						minDp[i][j] = min(minDp[i][j], calc(minDp[i][j - 2], a[i][j - 1], a[i][j]));
						maxDp[i][j] = max(maxDp[i][j], calc(maxDp[i][j - 2], a[i][j - 1], a[i][j]));
					}
				}
			}
		}
	}

	cout << maxDp[n - 1][n - 1] << ' ' << minDp[n - 1][n - 1];
}