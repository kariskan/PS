#include <iostream>
using namespace std;

int n;
string s;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		char a;
		cin >> a;
		s += a;
	}

	int left = 0, right = n - 1;
	string ans = "";
	while (left <= right)
	{
		if (s[left] != s[right])
		{
			if (s[left] < s[right])
			{
				ans += s[left];
				left++;
			}
			else
			{
				ans += s[right];
				right--;
			}
		}
		else
		{
			int tl = left, tr = right;
			while (s[tl] == s[tr] && tl <= tr)
			{
				tl++;
				tr--;
			}
			if (s[tl] < s[tr])
			{
				ans += s[left];
				left++;
			}
			else
			{
				ans += s[right];
				right--;
			}
		}
	}

	for (int i = 0; i <= ans.length() / 80; i++)
	{
		cout << ans.substr(i * 80, 80) << '\n';
	}
}