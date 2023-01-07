#include <iostream>
#include <cmath>
using namespace std;

void go(string s)
{
	if (s.length() == 1)
	{
		cout << s;
		return;
	}
	int len = s.length();
	go(s.substr(0, len / 3));
	for (int i = len / 3; i < (len / 3) * 2; i++)
	{
		s[i] = ' ';
		cout << s[i];
	}
	go(s.substr((len / 3) * 2));
}

int main()
{
	int n;
	while (cin >> n)
	{
		if (cin.eof())
		{
			break;
		}
		string s(pow(3,n), '-');
		go(s);
		cout << '\n';
	}
}