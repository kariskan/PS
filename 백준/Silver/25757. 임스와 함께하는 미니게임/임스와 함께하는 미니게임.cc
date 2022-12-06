#include <iostream>
#include <set>
using namespace std;

set<string> se;

int main()
{
	int cnt;

	int n;
	char c;

	cin >> n >> c;
	if (c == 'Y')
	{
		cnt = 1;
	}
	else if (c == 'F')
	{
		cnt = 2;
	}
	else
	{
		cnt = 3;
	}
	int num = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (se.count(s))
		{
			continue;
		}
		else
		{
			se.insert(s);
			num++;
		}
		if (num == cnt)
		{
			ans++;
			num = 0;
		}
	}

	cout << ans;
}