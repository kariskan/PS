#include <iostream>
using namespace std;

int trip[51];

int main()
{
	for (int i = 1; i <= 50; i++)
	{
		trip[i] = (i * (i + 1)) / 2;
	}
	int n;
	cin >> n;
	for (int t = 0; t < n; t++)
	{
		int a;
		cin >> a;
		int ok = 0;
		for (int i = 1; i <= 50; i++)
		{
			for (int j = 1; j <= 50; j++)
			{
				for (int k = 1; k <= 50; k++)
				{
					if (trip[i] + trip[j] + trip[k] == a)
					{
						cout << "1\n";
						ok = 1;
						break;
					}
				}
				if (ok)
				{
					break;
				}
			}
			if (ok)
			{
				break;
			}
		}
		if (!ok)
		{
			cout << "0\n";
		}
	}
}