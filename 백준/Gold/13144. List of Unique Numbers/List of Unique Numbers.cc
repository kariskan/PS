
#include <iostream>
using namespace std;

int a[100001], cnt[100001], prefixSum[100001];

int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	for (int i = 1; i <= 100000; i++)
	{
		prefixSum[i] = i + prefixSum[i - 1];
	}

	int left = 1, right = 1;
	cnt[a[right]] = 1;
	long long ans = 0;

	while (left <= right && right <= n)
	{
		ans += right - left + 1;
		right++;
		cnt[a[right]]++;

		if (right > n)
		{
			break;
		}

		while (cnt[a[right]] >= 2)
		{
			cnt[a[left]]--;
			left++;
		}
	}

	cout << ans;
}