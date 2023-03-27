#include <iostream>
#include <regex>
using namespace std;

string s;

int main()
{
	cin >> s;
	regex re("(100+1+|01)+");
	if (regex_match(s, re))
	{
		cout << "SUBMARINE";
	}
	else
	{
		cout << "NOISE";
	}
}