#include <iostream>
#include <cstring>
using namespace std;
string s[100];
int vis[26];
bool change(int i, int j)
{
	int changed[100] = {
		0,
	};
	string s1 = s[i];
	string s2 = s[j];
	for (int k = 0; k < s1.length(); k++)
	{
		if (changed[k])
		{
			continue;
		}
		char before = s1[k];
		char after = s2[k];
		if (vis[after - 'a'])
		{
			continue;
		}
		vis[after - 'a'] = 1;
		for (int l = 0; l < s1.length(); l++)
		{
			if (s[i][l] == before)
			{
				s1[l] = after;
				changed[l] = 1;
			}
		}
	}
	for (int k = 0; k < s1.length(); k++)
	{
		if (!changed[k])
		{
			return false;
		}
	}
	return s1 == s2;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (change(i, j))
			{
				ans++;
			}
			memset(vis, 0, sizeof(vis));
		}
	}

	cout << ans;
}