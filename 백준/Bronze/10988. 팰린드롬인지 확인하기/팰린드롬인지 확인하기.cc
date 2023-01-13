#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string s1 = s;
	reverse(s1.begin(), s1.end());

	if (s == s1)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}