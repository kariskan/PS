#include <iostream>
using namespace std;

string s;
char seq[4] = {'w', 'o', 'l', 'f'};

bool matchOrder(int order, int idx)
{
	return seq[order] == s[idx];
}
int cnt, order;
void go(int idx)
{
	if (idx >= s.length())
	{
		return;
	}
	if (!matchOrder(order, idx))
	{
		cout << 0;
		exit(0);
	}
	if (order == 0)
	{
		cnt = 0;
		while (s[idx] == 'w')
		{
			cnt++;
			idx++;
		}
		order++;
		go(idx);
	}
	else
	{
		for (int i = idx; i < idx + cnt; i++)
		{
			if (!matchOrder(order, i))
			{
				cout << 0;
				exit(0);
			}
		}
		order = (order + 1) % 4;
		go(idx + cnt);
	}
}

int main()
{
	cin >> s;
	go(0);

	if (order == 0)
	{
		cout << 1;
	}
	else
	{
		cout << 0;
	}
}