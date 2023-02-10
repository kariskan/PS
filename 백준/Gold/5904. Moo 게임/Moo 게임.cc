#include <iostream>
using namespace std;

int n;
long long len[30];

void go(int i, int j)
{
	if (i == 0)
	{
		if (j == 1)
		{
			cout << 'm';
		}
		else
		{
			cout << 'o';
		}
		return;
	}
	if (j > len[i - 1] && j <= len[i - 1] + i + 3) // 중간에 위치하면
	{
		if (j == len[i - 1] + 1)
		{
			cout << 'm';
		}
		else
		{
			cout << 'o';
		}
		return;
	}
	else
	{
		if (j <= len[i - 1]) // 왼쪽에 위치하면
		{
			go(i - 1, j);
		}
		else // 오른쪽에 위치하면
		{
			go(i - 1, j - len[i - 1] - 3 - i);
		}
	}
}

int main()
{
	cin >> n;
	len[0] = 3;
	for (int i = 1; i < 30; i++)
	{
		len[i] = len[i - 1] * 2 + 3 + i;
	}
	if (n <= 3)
	{
		go(0, n);
		return 0;
	}
	for (int i = 0; i < 30; i++)
	{
		if (n > len[i - 1] && n <= len[i])
		{
			go(i, n);
			break;
		}
	}
	return 0;
}