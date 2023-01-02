#include <iostream>
#include <string>
using namespace std;

bool ok(string s)
{
	for (int i = 0; i < s.length() / 2; i++)
	{
		if (s[i] != s[s.length() - i - 1])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	string s;
	while (cin >> s, s != "0")
	{
		int cnt = 0;
		while (!ok(s))
		{
			cnt++;
			string now = to_string(stoi(s) + 1);
			for (int i = 0; i < now.length(); i++)
			{
				s[s.length() - now.length() + i] = now[i];
			}
		}
		cout << cnt << '\n';
	}
}