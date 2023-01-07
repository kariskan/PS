#include <iostream>
#include <string>
using namespace std;
int vis[55], lenv[55], alen;
string s;
bool go(int idx, int maxNum, string ans)
{
	if (idx >= s.length())
	{
		for (int i = 1; i <= maxNum; i++)
		{
			if (!vis[i])
			{
				return false;
			}
		}
		cout << ans.substr(1);
		return true;
	}
	string t = "";
	for (int i = idx; i < s.length(); i++)
	{
		t += s[i];
		int numT = stoi(t);
		if (alen < numT)
		{
			return false;
		}
		if (!vis[numT])
		{
			vis[numT] = 1;
			if (go(i + 1, max(maxNum, numT), ans + " " + t))
			{
				return true;
			}
			vis[numT] = 0;
		}
	}
	return false;
}
int main()
{
	int len = 0;
	for (int i = 1; i <= 50; i++)
	{
		len += to_string(i).length();
		lenv[i] = len;
	}
	cin >> s;
	for (int i = 1; i <= 50; i++)
	{
		if (lenv[i] == s.length())
		{
			alen = i;
		}
	}
	go(0, 0, "");
}