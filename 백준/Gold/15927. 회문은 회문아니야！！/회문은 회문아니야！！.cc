#include <iostream>
using namespace std;

string s;
int ans = -1;

bool check()
{
	for (int i = 0; i < (s.length() + 1) / 2; i++)
	{
		if (s[i] != s[s.length() - 1 - i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;

	if (check())
	{
		int ok = 0;
		for (int i = 0; i < s.length() - 1; i++)
		{
			if (s[i] != s[i + 1])
			{
				ok = 1;
				break;
			}
		}
		if (ok == 0)
		{
			cout << -1;
		}
		else
		{
			cout << s.length() - 1;
		}
	}
	else
	{
		cout << s.length();
	}
}