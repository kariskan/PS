#include <iostream>
using namespace std;

int n, k, p, x, ans;
int num[10][7] = {
	{1, 1, 1, 0, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 0},
	{1, 0, 1, 1, 1, 0, 1},
	{1, 0, 1, 1, 0, 1, 1},
	{0, 1, 1, 1, 0, 1, 0},
	{1, 1, 0, 1, 0, 1, 1},
	{1, 1, 0, 1, 1, 1, 1},
	{1, 0, 1, 0, 0, 1, 0},
	{1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 0, 1, 1},
};
int rever[10][10];

int getDigit(int now)
{
	int cnt = 0;
	while (now)
	{
		now /= 10;
		cnt++;
	}
	return cnt;
}

int getDigitDiff(int now)
{
	return abs(getDigit(now) - getDigit(n));
}

int main()
{
	cin >> n >> k >> p >> x;

	for (int i = 0; i < 10; i++)
	{
		for (int j = i; j < 10; j++)
		{
			for (int c = 0; c < 7; c++)
			{
				if (num[i][c] != num[j][c])
				{
					rever[i][j]++;
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (i == x)
		{
			continue;
		}
		int temp = 0;

		int a = x;
		int b = i;

		while (a != 0 || b != 0)
		{
			int c = a % 10;
			int d = b % 10;
			
			temp += rever[min(c, d)][max(c, d)];

			a /= 10;
			b /= 10;
		}
		if (temp <= p)
		{
			ans++;
		}
	}

	cout << ans;
}