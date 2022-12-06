#include <iostream>
#include <map>
using namespace std;

int n;
string s;
int check[27];

bool checkSame(string t)
{
	int check2[27] = {
		0,
	};
	for (int i = 0; i < t.length(); i++)
	{
		check2[t[i] - 'A']++;
	}
	for (int i = 0; i < 27; i++)
	{
		if (check[i] != check2[i])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	int ans = 0;
	cin >> s;

	for (int i = 0; i < s.length(); i++)
	{
		check[s[i] - 'A']++;
	}

	for (int i = 0; i < n - 1; i++)
	{
		string t;
		cin >> t;

		int check2[27] = {
			0,
		};

		for (int j = 0; j < 27; j++)
		{
			check2[j] = check[j];
		}
		int same = 0;
		for (int j = 0; j < t.length(); j++)
		{
			if (check2[t[j] - 'A'])
			{
				same++;
				check2[t[j] - 'A']--;
			}
		}

		if (same == s.length() && t.length() == s.length())
		{
			ans++;
			continue;
		}

		// 더하기
		if (same == s.length() - 1 && t.length() == s.length() - 1)
		{
			ans++;
			continue;
		}

		// 빼기
		if (same == s.length() && t.length() == s.length() + 1)
		{
			ans++;
			continue;
		}

		// 바꾸기
		if (same == s.length() - 1 && t.length() == s.length())
		{
			ans++;
			continue;
		}
	}

	cout << ans;
}