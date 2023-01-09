#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
	string n;
	int b;
	cin >> n >> b;
	reverse(n.begin(), n.end());
	int ans = 0, p = 0;
	for (int i = 0; i < n.length(); i++)
	{
		if (n[i] >= 'A' && n[i] <= 'Z')
		{
			ans += pow(b, p) * (n[i] - 'A' + 10);
		}
		else
		{
			ans += pow(b, p) * (n[i] - '0');
		}
		p++;
	}
	
	cout << ans;
}