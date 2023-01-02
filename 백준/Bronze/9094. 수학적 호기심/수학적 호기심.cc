#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		int cnt = 0;
		for (int j = 1; j < a; j++)
		{
			for (int k = j + 1; k < a; k++)
			{
				if ((j * j + k * k + b) % (j * k) == 0)
				{
					cnt++;
				}
			}
		}
		cout << cnt << '\n';
	}
}