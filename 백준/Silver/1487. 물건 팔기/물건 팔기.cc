#include <iostream>
#include <algorithm>
using namespace std;

int n;
pair<int, int> a[50];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].first >> a[i].second;
	}
	sort(a, a + n);
	int ans = 0, maxSum = 0;
	for (int i = 0; i < n; i++)
	{
		int price = a[i].first;
		int sum = 0;
		for (int j = 0; j < n; j++)
		{
			if (a[j].first < price)
			{
				continue;
			}
			else
			{
				sum += max(0, min(price, a[j].first) - a[j].second);
			}
		}
		if (sum > maxSum)
		{
			maxSum = sum;
			ans = a[i].first;
		}
	}

	cout << ans;
}