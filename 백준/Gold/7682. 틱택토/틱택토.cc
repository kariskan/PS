#include <iostream>
using namespace std;

bool ok;

bool isGameEnd(string s)
{
	for (int i = 0; i < 3; i++)
	{
		if (s[i] != '.' && s[i] == s[i + 3] && s[i + 3] == s[i + 6])
		{
			return true;
		}
	}
	for (int i = 0; i < 9; i += 3)
	{
		if (s[i] != '.' && s[i] == s[i + 1] && s[i + 1] == s[i + 2])
		{
			return true;
		}
	}
	if (s[0] != '.' && s[0] == s[4] && s[4] == s[8])
	{
		return true;
	}
	if (s[2] != '.' && s[2] == s[4] && s[4] == s[6])
	{
		return true;
	}
	return false;
}

void go(string s, string now, int cnt, int p)
{
	if (isGameEnd(now) || cnt == 9)
	{
		if (s == now)
		{
			ok = true;
		}
		return;
	}
	for (int i = 0; i < 9; i++)
	{
		if (s[i] == '.' || now[i] != '.')
		{
			continue;
		}
		if ((p == 0 && s[i] == 'O') || (p == 1 && s[i] == 'X'))
		{
			continue;
		}
		now[i] = s[i];
		go(s, now, cnt + 1, 1 - p);
		now[i] = '.';
	}
}

int main()
{
	string s;
	while (cin >> s, s != "end")
	{
		ok = false;
		go(s, ".........", 0, 0);

		if (ok)
		{
			cout << "valid\n";
		}
		else
		{
			cout << "invalid\n";
		}
	}
}