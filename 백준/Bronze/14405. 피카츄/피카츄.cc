#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	string a[3] = {"pi", "ka", "chu"};
	for (int i = 0; i < s.length(); i++)
	{
		int ok = 0;
		for (int j = 0; j < 3; j++)
		{
			if (s.substr(i, a[j].length()) == a[j])
			{
				ok = 1;
				i = i + a[j].length() - 1;
				break;
			}
		}
		if (ok == 0)
		{
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES";
}