#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[1000000], b[1000000];
void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < m; i++)
	{
		cin >> b[i];
	}
}

// a[i]보다 작은것 중 가장 큰 것을 찾는 함수
// now = a[i]
int smallSearch(int now)
{
	int ret = b[0];
	int left = 0, right = m - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (b[mid] < now)
		{					 // a[i]가 b[mid]보다 크면
			left = mid + 1; // 왼쪽 탐색
			ret = b[mid];
		}
		else
		{					// 그렇지 않으면
			right = mid - 1; // 오른쪽 탐색
		}
	}
	return ret;
}

// a[i]보다 큰것 중 가장 작은 것을 찾는 함수
// now = a[i]
int largeSearch(int now)
{
	int ret = b[m - 1];
	int left = 0, right = m - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;

		if (b[mid] < now)
		{					// a[i]가 b[mid]보다 크면
			left = mid + 1; // 오른쪽 탐색
		}
		else
		{					 // 그렇지 않으면
			right = mid - 1; // 왼쪽
			ret = b[mid];
		}
	}
	return ret;
}

void Solve()
{
	long long ans = 0;
	sort(b, b + m);

	for (int i = 0; i < n; i++)
	{
		int s = smallSearch(a[i]);
		int l = largeSearch(a[i]);
		if (abs(a[i] - s) > abs(a[i] - l))
		{
			ans += l;
		}
		else
		{
			ans += s;
		}
	}

	cout << ans << '\n';
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		Input();
		Solve();
	}
}