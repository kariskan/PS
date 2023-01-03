#include <iostream>
using namespace std;
int n, m, hideLine = -1;
string result;
char map[1000][26];

string go(int start, int end, string s)
{
	for (int i = start; i < end; i++)
	{
		string newS(m, ' ');
		for (int j = 0; j < m; j++)
		{
			if (j == 0)
			{
				if (map[i][j] == '-')
				{
					newS[j + 1] = s[j];
				}
				else
				{
					newS[j] = s[j];
				}
			}
			else if (j == m - 1)
			{
				if (map[i][j - 1] == '-')
				{
					newS[j - 1] = s[j];
				}
				else
				{
					newS[j] = s[j];
				}
			}
			else
			{
				if (map[i][j - 1] == '-')
				{
					newS[j - 1] = s[j];
				}
				else if (map[i][j] == '-')
				{
					newS[j + 1] = s[j];
				}
				else
				{ // 직선
					newS[j] = s[j];
				}
			}
		}
		s = newS;
	}
	return s;
}

void outError()
{
	for (int i = 0; i < m - 1; i++)
	{
		cout << "x";
	}
}

int main()
{
	cin >> m >> n >> result;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 1; j++)
		{
			if (hideLine != -1)
			{
				cin >> map[n - i + hideLine][j];
			}
			else
			{
				cin >> map[i][j];
			}
			if (j == m - 2 && map[i][j] == '?')
			{
				hideLine = i;
			}
		}
	}
	string s(m, ' ');
	for (int j = 0; j < m; j++)
	{
		s[j] = (j + 'A');
	}
	s = go(0, hideLine, s);
	string s2 = go(hideLine + 1, n, result);
	string ans = "";
	for (int i = 0; i < m - 1; i++)
	{
		if (s[i] == s2[i])
		{
			ans += "*";
		}
		else
		{
			if (s[i + 1] == s2[i])
			{
				ans += "-";
				if (i < m - 2)
				{
					ans += "*";
					i++;
				}
			}
			else
			{
				outError();
				return 0;
			}
		}
	}
	cout << ans;
	return 0;
}