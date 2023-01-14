#include <iostream>
using namespace std;

int gcd(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	return gcd(b, a % b);
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	int g = (s1.length() * s2.length()) / gcd(s1.length(), s2.length());

	string t1 = "", t2 = "";

	while (t1.length() != g)
	{
		t1 += s1;
	}

	while (t2.length() != g)
	{
		t2 += s2;
	}

	if (t1 == t2)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}