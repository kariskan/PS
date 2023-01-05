#include <iostream>
#include <string>
using namespace std;

int parse(string t)
{
	return stoi(t.substr(0, 2)) * 60 * 60 +
		   stoi(t.substr(3, 2)) * 60 +
		   stoi(t.substr(6, 2));
}

void print(int diff)
{
	string ans = "00:00:00";
	ans[0] = (diff / 3600) / 10 + '0';
	ans[1] = (diff / 3600) % 10 + '0';

	ans[3] = (diff % 3600 / 60) / 10 + '0';
	ans[4] = (diff % 3600 / 60) % 10 + '0';

	ans[6] = (diff % 60) / 10 + '0';
	ans[7] = (diff % 60) % 10 + '0';

	cout << ans;
}

int main()
{
	string t1, t2;
	cin >> t1 >> t2;
	int tt1 = parse(t1);
	int tt2 = parse(t2);

	if (tt1 >= tt2)
	{
		tt2 += 60 * 60 * 24;
	}

	int diff = tt2 - tt1;

	print(diff);
}