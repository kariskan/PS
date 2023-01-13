#include <iostream>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int idx = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (s1[i] == ' ')
		{
			cout << ' ';
		}
		else
		{
			int a = s1[i] + 25 - s2[idx];
			a %= 26;
			char k = a + 'a';
			cout << k;
		}
		idx = (idx + 1) % s2.length();
	}
}