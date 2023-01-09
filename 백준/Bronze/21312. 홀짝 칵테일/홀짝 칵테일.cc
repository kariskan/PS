#include <iostream>
using namespace std;
int multi(int a, int b, int c, int d)
{
	int res = 1;
	if (a % 2 == d)
		res *= a;
	if (b % 2 == d)
		res *= b;
	if (c % 2 == d)
		res *= c;
	return res;
}
int main()
{
	int a, b, c, odd = 0;
	cin >> a >> b >> c;
	if (a % 2 == 1 || b % 2 == 1 || c % 2 == 1)
	{
		odd = 1;
	}
	if (odd)
		cout << multi(a, b, c, 1);
	else
		cout << multi(a, b, c, 0);
}