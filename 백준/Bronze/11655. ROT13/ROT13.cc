#include <iostream>
using namespace std;

int main()
{
	string s;
	getline(cin, s);

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == ' ' || (s[i] >= '0' && s[i] <= '9'))
		{
			cout << s[i];
			continue;
		}
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			cout << (char)((s[i] - 'A' + 13) % 26 + 'A');
		}
		else
		{
			cout << (char)((s[i] - 'a' + 13) % 26 + 'a');
		}
	}
}