#include <iostream>
using namespace std;

// s[i]: 각 줄에 사용되는 숫자의 수, num[i]: 숫자 i를 사용할 수 있는지 없는지
int n, s[7], k, ans, num[10], tot;

bool getLen(int a, int m)
{
	int cnt = 0;

	while (a)
	{
		cnt++;
		a /= 10;
	}

	return s[m] == cnt;
}

bool check(int first, int second)
{
	int finalResult = first * second;
	int idx = 2;
	while (second)
	{
		int temp = first * (second % 10);
		if (!getLen(temp, idx++))
		{
			return false;
		}
		while (temp)
		{
			if (!num[temp % 10])
			{
				return false;
			}
			temp /= 10;
		}
		second /= 10;
	}
	if (!getLen(finalResult, idx++))
	{
		return false;
	}
	while (finalResult)
	{
		if (!num[finalResult % 10])
		{
			return false;
		}
		finalResult /= 10;
	}

	return true;
}

void go(int cnt, int first, int second)
{
	if (cnt == tot) // 기저 조건
	{
		if (check(first, second))
		{
			ans++;
		}
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		if (!num[i]) // 사용하면 안되는 수이면
		{
			continue;
		}
		if (cnt >= s[0])
		{
			go(cnt + 1, first, second * 10 + i);
		}
		else
		{
			go(cnt + 1, first * 10 + i, second);
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		if (i < 2)
		{
			tot += s[i];
		}
	}
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		int c;
		cin >> c;
		num[c] = 1;
	}
	go(0, 0, 0);

	cout << ans;
}

/*
	X X X X X
		X X X
-------------
	X X X X X
  X X X X X
X X X X X
-------------
X X X X X X X
*/

// 1 2 3 4 5 6 7 8 9