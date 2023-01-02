#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	for (int i = 1; i <= 1000000; i++)
	{
		if (max(c, d) <= i && (i - c) % a == 0 && (i - d) % b == 0)
		{
			cout << i;
			return 0;
		}
	}
	cout << -1;
}