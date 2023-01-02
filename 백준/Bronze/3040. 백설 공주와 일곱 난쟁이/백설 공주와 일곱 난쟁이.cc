#include <iostream>
using namespace std;

int a[9];

int main()
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9 && i != j; j++)
		{
			if (a[i] + a[j] == sum - 100)
			{
				for (int k = 0; k < 9; k++)
				{
					if (k == i || k == j)
						continue;
					cout << a[k] << ' ';
				}
				return 0;
			}
		}
	}
}