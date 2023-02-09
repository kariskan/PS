#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

set<string> front = {"c", "j", "n", "m", "t", "s", "l", "d", "qu"};
set<string> back = {"a", "e", "i", "o", "u", "h"};

int main()
{
	string s;
	getline(cin, s);
	vector<string> v;
	string temp = "";
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' || s[i] == '-')
		{
			v.push_back(temp);
			temp = "";
			continue;
		}
		temp += s[i];
	}
	v.push_back(temp);
	int ans = (int)v.size();
	for (auto &i : v)
	{
		for (int j = 0; j < i.length(); j++)
		{
			if (i[j] == '\'')
			{
				if (j == 1 && front.count(i.substr(j - 1, 1)) && back.count(i.substr(j + 1, 1)))
				{
					ans++;
				}
				else if (j == 2 && front.count(i.substr(j - 2, 2)) && back.count(i.substr(j + 1, 1)))
				{
					ans++;
				}
			}
		}
	}

	cout << ans;
}