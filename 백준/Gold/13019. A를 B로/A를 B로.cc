#include <iostream>
#include <algorithm>
using namespace std;

string s1, s2;
int alpha[26], n;

bool notCheck()
{
	return s1 != s2;
}

bool can()
{
	string t1 = s1;
	string t2 = s2;
	sort(t1.begin(), t1.end());
	sort(t2.begin(), t2.end());
	return t1 == t2;
}

int main()
{
	cin >> s1 >> s2;

	if (s1.length() != s2.length() || !can())
	{
		cout << -1;
		return 0;
	}

	int ans = 0;

	for (int i = s1.length() - 1; i >= 0; i--)
	{
		if (s1[i] == s2[s1.length() - 1 - ans])
		{
			ans++;
		}
	}

	cout << s1.length() - ans;
}