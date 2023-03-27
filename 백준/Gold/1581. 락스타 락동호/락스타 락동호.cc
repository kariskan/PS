#include <iostream>
using namespace std;

int a, b, c, d;

int main()
{
	cin >> a >> b >> c >> d;

	if (!a && !b)
	{
		cout << d + min(1, c);
	}
	else if (b == 0)
	{
		cout << a;
	}
	else if (b > c)
	{
		cout << 2 * c + 1 + a + d;
	}
	else
	{
		cout << 2 * b + a + d;
	}
}