#include <iostream>
using namespace std;
string s[10];
int main()
{
	int n, m, a;
	cin >> n >> m >> a;
	for (int i = 0; i < m; i++)
	{
		cin >> s[i];
	}
	string ans = "";
	for (int i = 0; i < n; i++)
	{
		int ok = 0;
		for (int j = 0; j < m; j++)
		{
			for (int k = i * a; k < i * a + a; k++)
			{
				if (s[j][k] != '?')
				{
					ans += s[j][k];
					ok = 1;
					break;
				}
			}
			if (ok)
			{
				break;
			}
		}
		if (!ok)
		{
			ans += "?";
		}
	}

	cout << ans;
}