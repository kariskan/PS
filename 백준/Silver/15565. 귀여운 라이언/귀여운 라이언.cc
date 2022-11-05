#include <iostream>
#include <vector>
using namespace std;

int n, k;
vector<int> v;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
			v.push_back(i);
	}

	if (v.size() < k)
		cout << -1;
	else
	{
		int left = 0, right = k - 1;
		int ans = 1000000000;
		while (right < v.size())
		{
			ans = min(ans, v[right] - v[left] + 1);
			left++;
			right++;
		}
		cout << ans;
	}
}