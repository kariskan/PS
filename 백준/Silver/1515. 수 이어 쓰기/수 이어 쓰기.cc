#include <iostream>
#include <string>
using namespace std;

string s;

int main()
{
	cin >> s;
	int idx = 0;

	for (int i = 1;; i++)
	{
		string t = to_string(i);

		for (int j = 0; j < t.length(); j++)
		{
			if (s[idx] == t[j])
			{
				idx++;
			}
			if (idx == s.length())
			{
				cout << i;
				return 0;
			}
		}
	}
}