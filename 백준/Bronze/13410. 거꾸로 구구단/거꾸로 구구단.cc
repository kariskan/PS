#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	int ans = 0;
	for (int i = 1; i <= k; i++)
	{
		int num = n * i;
		string s = to_string(num);
		reverse(s.begin(), s.end());
		ans = max(ans, stoi(s));
	}
	cout << ans;
}