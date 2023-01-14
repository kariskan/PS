#include <iostream>
#include <sstream>
#include <vector>
#include <set>
using namespace std;

vector<string> parse(string s)
{
	istringstream iss(s);
	string buffer;
	vector<string> res;

	while (getline(iss, buffer, ' '))
	{
		res.push_back(buffer);
	}

	return res;
}

int main()
{
	int t;
	cin >> t;
	getchar();
	while (t--)
	{
		set<string> se;
		string s;
		getline(cin, s);
		while (1)
		{
			string t;
			getline(cin, t);
			if (t == "what does the fox say?")
			{
				break;
			}
			vector<string> v = parse(t);
			se.insert(v[2]);
		}

		vector<string> v = parse(s);
		string ans = "";
		for (auto &i : v)
		{
			if (se.find(i) == se.end())
			{
				ans += i + " ";
			}
		}

		cout << ans << '\n';
	}
}