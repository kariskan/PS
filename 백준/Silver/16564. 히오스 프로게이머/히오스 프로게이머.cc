#include <iostream>
using namespace std;
int n, k;		// n: 캐릭터의 개수, k: 올릴 수 있는 레벨 수
int x[1000000]; // x[i]: i번째 캐릭터 레벨
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	int left = 1000000000, right = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> x[i];
		left = min(left, x[i]);
		right = max(right, x[i]);
	}

	right += k;
	int ans = 0;
	while (left <= right)
	{
		int mid = (left + right) / 2; // 레벨 기준

		long long cnt = 0; // 필요한 레벨업의 총 합
		for (int i = 0; i < n; i++)
		{
			if (x[i] < mid) // 레벨업이 필요한 상황이면
			{
				cnt += mid - x[i];
			}
		}

		if (cnt > k) // 필요한 레벨업의 총 합이 가능한 레벨업의 수보다 크면
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
			ans = mid;
		}
	}

	cout << ans;
}