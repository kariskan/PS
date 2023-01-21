#include <iostream>
#include <set>
using namespace std;

int main()
{
	string s = "";
	while (cin >> s, s != "*")
	{
		int ok = 1;
		if (s.length() > 1)
		{
			for (int i = 0; i <= s.length() - 2; i++)
			{
				set<string> se;
				for (int j = 0; j < s.length() - i - 1; j++)
				{
					string t = "";
					t = t + s[j] + s[j + i + 1];
					if (se.count(t))
					{
						ok = 0;
						break;
					}
					se.insert(t);
				}
				if (!ok)
				{
					break;
				}
			}
		}
		if (ok)
		{
			cout << s << " is surprising.\n";
		}
		else
		{
			cout << s << " is NOT surprising.\n";
		}
	}
}