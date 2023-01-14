#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m1[26] = {
			0,
		},
			m2[26] = {
				0,
			};
		string s1, s2;
		cin >> s1 >> s2;
		for (int j = 0; j < s1.length(); j++)
		{
			m1[s1[j] - 'a']++;
		}
		for (int j = 0; j < s2.length(); j++)
		{
			m2[s2[j] - 'a']++;
		}
		int ok = 1;
		for (int j = 0; j < 26; j++)
		{
			if (m1[j] != m2[j])
			{
				cout << s1 << " & " << s2 << " are NOT anagrams.\n";
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			cout << s1 << " & " << s2 << " are anagrams.\n";
		}
	}
}