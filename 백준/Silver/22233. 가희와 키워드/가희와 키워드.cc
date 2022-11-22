#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

unordered_set<string> s;
int n, m;

vector<string> parse(string t)
{
	string temp = "";
	vector<string> res;

	for (int i = 0; i < t.length(); i++)
	{
		if (t[i] == ',')
		{
			res.push_back(temp);
			temp = "";
			continue;
		}
		temp += t[i];
	}
	res.push_back(temp);
	return res;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string t;
		cin >> t;
		s.insert(t);
	}
	for (int i = 0; i < m; i++)
	{
		string t;
		cin >> t;
		vector<string> temp = parse(t);
		for (auto &j : temp)
		{
			if (s.find(j) != s.end())
			{
				s.erase(j);
			}
		}
		cout << s.size() << '\n';
	}

}