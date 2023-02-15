#include <iostream>
#include <vector>
using namespace std;

bool check(int n)
{
	if (n == 0 || n == 1)
	{
		return false;
	}
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int n;

void go(int val, int idx)
{
	if (idx == n)
	{
		cout << val << '\n';
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		int temp = val * 10 + i;
		if (check(temp))
		{
			go(temp, idx + 1);
		}
	}
}

int main()
{
	cin >> n;
	go(0, 0);
}