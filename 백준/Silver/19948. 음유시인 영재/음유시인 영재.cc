// #include <iostream>
// #include <set>
// using namespace std;

// int main()
// {
// 	string s = "";
// 	while (cin >> s, s != "*")
// 	{
// 		int ok = 1;
// 		for (int i = 0; i <= s.length() - 2; i++)
// 		{
// 			set<string> se;
// 			for (int j = 0; j < s.length() - i - 1; j++)
// 			{
// 				string t = "";
// 				t = t + s[j] + s[j + i + 1];
// 				if (se.count(t))
// 				{
// 					ok = 0;
// 					break;
// 				}
// 				se.insert(t);
// 			}
// 			if (!ok)
// 			{
// 				break;
// 			}
// 		}
// 		if (ok)
// 		{
// 			cout << s << " is surprising.\n";
// 		}
// 		else
// 		{
// 			cout << s << " is NOT surprising.\n";
// 		}
// 	}
// }

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int a[26] = {
		0,
	},
		n;
	string s;

	getline(cin, s);
	cin >> n;
	for (int i = 0; i < 26; i++)
	{
		cin >> a[i];
	}
	s.erase(unique(s.begin(), s.end()), s.end());
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' && n)
		{
			n--;
			continue;
		}
		if (s[i] == ' ' && !n)
		{
			cout << -1;
			return 0;
		}
		if (a[tolower(s[i]) - 'a'])
		{
			a[tolower(s[i]) - 'a']--;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}
	string ans = "";
	ans += (char)toupper(s[0]);
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == ' ')
		{
			ans += (char)toupper(s[i + 1]);
		}
	}
	string ans2 = ans;
	ans.erase(unique(ans.begin(), ans.end()), ans.end());
	for (int i = 0; i < ans.length(); i++)
	{
		if (ans[i] == ' ')
		{
			continue;
		}
		if (a[tolower(ans[i]) - 'a'])
		{
			a[tolower(ans[i]) - 'a']--;
		}
		else
		{
			cout << -1;
			return 0;
		}
	}

	cout << ans2;
}