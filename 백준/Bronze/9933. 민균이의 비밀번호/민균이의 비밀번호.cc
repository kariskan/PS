#include <iostream>
#include <algorithm>
using namespace std;
int n;
string s[100];
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			string s1 = s[i];
			reverse(s1.begin(), s1.end());
			if (s1 == s[j])
			{
				cout << s1.length() << ' ' << s1[s1.length() / 2];
				return 0;
			}
		}
	}
}