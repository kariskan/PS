#include <iostream>
using namespace std;

#define max(a, b, c) max(max(a, b), c)
#define min(a, b, c) min(min(a, b), c)

int main()
{
	while (1)
	{
		int a, b, c;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}

		if (a + b + c - max(a, b, c) <= max(a, b, c))
		{
			cout << "Invalid\n";
			continue;
		}

		if (a == b && b == c)
		{
			cout << "Equilateral\n";
			continue;
		}
		if (a == b || b == c || a == c)
		{
			cout << "Isosceles\n";
			continue;
		}
		if (a != b && b != c && a != c)
		{
			cout << "Scalene\n";
		}
	}
}