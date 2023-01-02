#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	while (1)
	{
		string s1, s2;
		cin >> s1;
		if (cin.eof())
		{
			break;
		}
		cin >> s2;
		int ans = 0;
		int n1 = stoi(s1), n2 = stoi(s2);
		for (int i = n1; i <= n2; i++)
		{
			int ok = 1;
			int cnt[10] = {
				0,
			};
			string s = to_string(i);
			for (int j = 0; j < s.length(); j++)
			{
				cnt[s[j] - '0']++;
				if (cnt[s[j] - '0'] >= 2)
				{
					ok = 0;
					break;
				}
			}
			if (ok)
			{
				ans++;
			}
		}
		cout << ans << '\n';
	}
}