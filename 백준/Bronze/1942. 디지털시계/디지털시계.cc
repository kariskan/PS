#include <iostream>
#include <string>
using namespace std;

int parse(string s)
{
	return stoi(s.substr(0, 2) + s.substr(3, 2) + s.substr(6));
}

string add(string s)
{
	string nextSecond = to_string(stoi(s.substr(6)) + 1);
	if (nextSecond == "60")
	{
		nextSecond = "00";
		string nextMinute = to_string(stoi(s.substr(3, 2)) + 1);
		if (nextMinute == "60")
		{
			nextMinute = "00";
			string nextHour = to_string(stoi(s.substr(0, 2)) + 1);
			if (nextHour == "24")
			{
				nextHour = "00";
			}
			if (nextHour.length() == 1)
			{
				s[1] = nextHour[0];
				s[0] = '0';
			}
			else
			{
				s[0] = nextHour[0];
				s[1] = nextHour[1];
			}
		}
		if (nextMinute.length() == 1)
		{
			s[4] = nextMinute[0];
			s[3] = '0';
		}
		else
		{
			s[3] = nextMinute[0];
			s[4] = nextMinute[1];
		}
	}
	if (nextSecond.length() == 1)
	{
		s[7] = nextSecond[0];
		s[6] = '0';
	}
	else
	{
		s[6] = nextSecond[0];
		s[7] = nextSecond[1];
	}

	return s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int t = 0; t < 3; t++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int ans = 0;
		while (1)
		{
			int num = parse(s1);
			if (num % 3 == 0)
			{
				ans++;
			}
			if (s1 == s2)
			{
				break;
			}
			s1 = add(s1);
		}
		cout << ans << '\n';
	}
}
