#include <iostream>
#include <map>
#include <string>
using namespace std;

string s[20000];
map<string, int> m;
int main()
{
	int n;
	cin >> n;
	int maxCnt = 0;
	string maxString = "";
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
		string t = "";
		for (int j = 0; j < s[i].length(); j++)
		{
			t += s[i][j];
			m[t]++;
			if (t.length() > maxCnt && m[t] > 1)
			{
				maxCnt = t.length();
				maxString = t;
			}
		}
	}
	int ansCnt = 0;
	string firstAns = "";
	for (int i = 0; i < n; i++)
	{
		if (s[i].substr(0, maxString.length()) == maxString && s[i] != firstAns)
		{
			cout << s[i] << '\n';
			ansCnt++;
			firstAns = s[i];
		}
		if (ansCnt == 2)
		{
			break;
		}
	}
}