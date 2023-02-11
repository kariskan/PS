#include <iostream>
#include <set>
using namespace std;

int n, m;
string s[1000];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char c;
			cin >> c;
			s[j] += c;
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		set<string> se;
		int ok = 1;
		for (int j = 0; j < m; j++)
		{
			if (se.count(s[j].substr(i + 1)))
			{
				ok = 0;
				break;
			}
			se.insert(s[j].substr(i + 1));
		}
		if (!ok)
		{
			cout << cnt;
			return 0;
		}
		cnt++;
	}
	
	cout << cnt;
}