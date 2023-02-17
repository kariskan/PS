#include <iostream>
#include <algorithm>
using namespace std;

long long n, a[5000], c;

bool checkOne()
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == c)
		{
			return true;
		}
	}
	return false;
}

bool checkTwo()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] == c)
			{
				return true;
			}
		}
	}
	return false;
}

bool checkThree()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[i] + a[j] >= c)
			{
				continue;
			}
			int left = j + 1, right = n - 1;
			while (left <= right)
			{
				int mid = (left + right) / 2;

				if (a[mid] + a[i] + a[j] == c)
				{
					return true;
				}
				else if (a[mid] + a[i] + a[j] > c)
				{
					right = mid - 1;
				}
				else
				{
					left = mid + 1;
				}
			}
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort(a, a + n);
	if (checkOne() || checkTwo() || checkThree())
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}