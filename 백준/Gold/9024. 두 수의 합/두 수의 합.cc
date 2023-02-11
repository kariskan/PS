#include <iostream>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;

int t, n, k, a[1000000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;
	while (t--)
	{
		memset(a, 0, sizeof(a));
		map<int, int> ma;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sort(a, a + n);
		int left = 0, right = n - 1;
		int minSum = 2000000000;
		while (left < right)
		{
			int sum = a[left] + a[right];
			minSum = min(minSum, abs(sum - k));
			ma[abs(sum - k)]++;

			if (sum < k)
			{
				left++;
			}
			else
			{
				right--;
			}
		}

		cout << ma[minSum] << '\n';
	}
}