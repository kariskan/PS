#include <iostream>
#include <string>
using namespace std;

int s[1000001];

int main()
{
	for (int i = 0; i <= 1000000; i++)
	{
		string d = to_string(i);
		int cnt = 0;
		for (int j = 0; j < d.length(); j++)
		{
			if (d[j] == '0')
			{
				cnt++;
			}
		}
		s[i] = cnt + s[i - 1];
	}
	int t;
	cin >> t;
	while (t--)
	{
		int a, b;
		cin >> a >> b;
		if (a == 0)
		{
			cout << s[b] << '\n';
		}
		else
			cout << s[b] - s[a - 1] << '\n';
	}
}