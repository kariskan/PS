#include <iostream>
using namespace std;

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			cout << (char)(s[i] - 'A' + 'a');
		}
		else
		{
			cout << (char)(s[i] - 'a' + 'A');
		}
	}
}