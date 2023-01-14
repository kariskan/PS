#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

char toLower(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return char(c - 'A' + 'a');
	}
	return c;
}

bool compare(string &s1, string &s2)
{
	for (int i = 0; i < min(s1.length(), s2.length()); i++)
	{
		char c1 = toLower(s1[i]);
		char c2 = toLower(s2[i]);

		if (c1 == c2)
		{
			continue;
		}

		return c1 < c2;
	}

	return s1.length() < s2.length();
}

int main()
{
	int t;
	while (cin >> t, t != 0)
	{
		vector<string> v;
		for (int i = 0; i < t; i++)
		{
			string s;
			cin >> s;
			v.push_back(s);
		}

		sort(v.begin(), v.end(), compare);
		cout << v[0] << '\n';
	}
}