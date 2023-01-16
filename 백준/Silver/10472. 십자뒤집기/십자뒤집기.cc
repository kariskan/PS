#include <iostream>
using namespace std;

string res[1000];
int ans[1000];
int idx;
int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};

string change(int i, int j, string now)
{
	if (now[i * 3 + j] == '0')
	{
		now[i * 3 + j] = '1';
	}
	else
	{
		now[i * 3 + j] = '0';
	}
	for (int k = 0; k < 4; k++)
	{
		int nx = i + x[k];
		int ny = j + y[k];
		if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3)
		{
			int d = nx * 3 + ny;
			if (now[d] == '0')
			{
				now[d] = '1';
			}
			else
			{
				now[d] = '0';
			}
		}
	}
	return now;
}

void go(int i, int j, string now, int cnt)
{
	if (j == 3)
	{
		go(i + 1, 0, now, cnt);
		return;
	}
	if (i == 3)
	{
		ans[idx] = cnt;
		res[idx++] = now;
		return;
	}

	go(i, j + 1, now, cnt);
	now = change(i, j, now);
	go(i, j + 1, now, cnt + 1);
}

int main()
{
	go(0, 0, "000000000", 0);

	int t;
	cin >> t;
	while (t--)
	{
		string s(9, ' ');
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				char c;
				cin >> c;
				if (c == '*')
				{
					s[i * 3 + j] = '1';
				}
				else
				{
					s[i * 3 + j] = '0';
				}
			}
		}

		for (int i = 0; i < idx; i++)
		{
			if (s == res[i])
			{
				cout << ans[i] << '\n';
				break;
			}
		}
	}
}