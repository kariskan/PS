#include <iostream>
using namespace std;
bool ans;
bool go(string s, int start, int end)
{
	if (start >= end)
	{
		return true;
	}
	int se = start, e = end;
	while (se < e)
	{
		if (s[se++] == s[e--])
		{
			return false;
		}
	}
	return go(s, start, (start + end) / 2 - 1) && go(s, (start + end) / 2 + 1, end);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		ans = true;
		string s;
		cin >> s;
		if (go(s, 0, s.length() - 1))
		{
			cout << "YES\n";
		}
		else
		{
			cout << "NO\n";
		}
	}
}