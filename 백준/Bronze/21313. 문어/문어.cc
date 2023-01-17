#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n % 2 == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (i % 2 == 0)
			{
				cout << 1 << ' ';
			}
			else
			{
				cout << 2 << ' ';
			}
		}
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (i % 2 == 0)
			{
				cout << 1 << ' ';
			}
			else
			{
				cout << 2 << ' ';
			}
		}
		if (n == 1)
		{
			cout << 1;
		}
		else
		{
			cout << 3;
		}
	}
}