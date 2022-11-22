#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int acnt = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'a')
			acnt++;
	}
	int ans = 1001;
	for (int i = 0; i < s.length(); i++)
	{
		int cnt = 0;
		for (int j = i; j < i + acnt; j++)
		{
			if (s[j % s.length()] == 'b')
			{
				cnt++;
			}
		}
		ans = min(ans, cnt);
	}
	cout << ans;
}