#include <iostream>
#include <string>
using namespace std;
int a[48 * 60 + 1];

string parseToAns(int t)
{
	string hour = to_string(t / 60);
	string minute = to_string(t % 60);
	if (hour.length() < 2)
	{
		hour = "0" + hour;
	}
	if (minute.length() < 2)
	{
		minute = "0" + minute;
	}
	return hour + ":" + minute;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int m;
		cin >> m;
		string t;
		cin >> t;
		int tt = stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3));
		a[tt] = m;
	}
	int score1 = 0, score2 = 0;
	int t1 = 0, t2 = 0;
	for (int i = 0; i < 48 * 60; i++)
	{
		if (a[i])
		{
			if (a[i] == 1)
			{
				score1++;
			}
			else
			{
				score2++;
			}
		}
		if (score1 > score2)
		{
			t1++;
		}
		else if (score2 > score1)
		{
			t2++;
		}
	}

	cout << parseToAns(t1) << '\n'
		 << parseToAns(t2);
}