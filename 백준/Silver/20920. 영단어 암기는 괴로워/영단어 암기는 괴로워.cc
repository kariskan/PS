#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
using namespace std;
map<string, int> ma;
vector<string> v;

bool compare(string s1, string s2)
{
	if (ma[s1] == ma[s2])
	{
		if (s1.length() == s2.length())
		{
			return s1 < s2;
		}
		return s1.length() > s2.length();
	}
	return ma[s1] > ma[s2];
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		if (s.length() >= m)
		{
			v.push_back(s);
			ma[s]++;
		}
	}

	sort(v.begin(), v.end(), compare);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (auto &i : v)
	{
		cout << i << '\n';
	}
}