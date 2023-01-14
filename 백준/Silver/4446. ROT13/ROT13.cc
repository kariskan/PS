#include <iostream>
using namespace std;

char mo[6] = {'a', 'i', 'y', 'e', 'o', 'u'};
char ja[20] = {'b', 'k', 'x', 'z', 'n', 'h', 'd', 'c', 'w', 'g', 'p', 'v', 'j', 'q', 't', 's', 'r', 'l', 'm', 'f'};
string s, ans = "";

void change(int idx)
{
	if (s[idx] >= 'A' && s[idx] <= 'Z')
	{
		ans[idx] = char(ans[idx] - 'a' + 'A');
	}
}

int main()
{

	while (1)
	{
		ans = "";
		getline(cin, s);
		if (cin.eof())
		{
			break;
		}
		for (int i = 0; i < s.length(); i++)
		{
			if (!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')))
			{
				ans += s[i];
				continue;
			}
			for (int j = 0; j < 6; j++)
			{
				if (tolower(s[i]) == mo[j])
				{
					ans += mo[(j + 3) % 6];
					break;
				}
			}
			for (int j = 0; j < 20; j++)
			{
				if (tolower(s[i]) == ja[j])
				{
					ans += ja[(j + 10) % 20];
					break;
				}
			}
			change(i);
		}

		cout << ans << '\n';
	}
}