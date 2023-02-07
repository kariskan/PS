#include <iostream>
using namespace std;

string num[10][5] = {
	{"***", "* *", "* *", "* *", "***"},
	{"  *", "  *", "  *", "  *", "  *"},
	{"***", "  *", "***", "*  ", "***"},
	{"***", "  *", "***", "  *", "***"},
	{"* *", "* *", "***", "  *", "  *"},
	{"***", "*  ", "***", "  *", "***"},
	{"***", "*  ", "***", "* *", "***"},
	{"***", "  *", "  *", "  *", "  *"},
	{"***", "* *", "***", "* *", "***"},
	{"***", "* *", "***", "  *", "***"}};

string a[5];
int go(int j)
{
	for (int l = 0; l < 10; l++)
	{
		int ok = 1;
		for (int i = 0; i < 5; i++)
		{
			for (int k = 0; k <= 2; k++)
			{
				if (num[l][i][k] != a[i][j + k])
				{
					ok = 0;
					break;
				}
			}
			if (!ok)
			{
				break;
			}
		}
		if (ok)
		{
			return l;
		}
	}
	return -1;
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		getline(cin, a[i]);
	}
	int ten = 1;
	int ans = 0;
	for (int i = a[0].length() - 3; i >= 0; i -= 4)
	{
		int k = go(i);
		if (k == -1)
		{
			cout << "BOOM!!";
			return 0;
		}
		ans += k * ten;
		ten *= 10;
	}
	if (ans % 6 == 0)
	{
		cout << "BEER!!";
	}
	else
	{
		cout << "BOOM!!";
	}
}