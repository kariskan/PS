#include <iostream>
using namespace std;

int a[26];

int main()
{
	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		a[s[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		cout << a[i] << ' ';
	}
}