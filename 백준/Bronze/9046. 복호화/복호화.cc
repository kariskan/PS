#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	map<char, int> m;
	getchar();
	while (n--)
	{
		string s;
		getline(cin, s);
		int maxCount = 0, c[27] = {
							  0,
						  };
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == ' ')
				continue;
			c[s[i] - 'a']++;
			maxCount = max(maxCount, c[s[i] - 'a']);
		}
		char ans = '0';
		for (int i = 0; i < 26; i++)
		{
			if (ans != '0' && c[i] == maxCount)
			{
				ans = '?';
				break;
			}
			if (c[i] == maxCount)
			{
				ans = i + 'a';
			}
		}
		cout << ans << '\n';
	}
}