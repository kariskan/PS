#include <iostream>
using namespace std;

long long a[500000], b[500000]; // a: 잉크 지수, b; 점도 지수
int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}
	for (int i = 0; i < n; i++)
	{
		int now = a[i]; // 현재 잉크 지수

		int left = i + 1, right = n - 1;
		int cnt = -1;

		while (left <= right)
		{
			int mid = (left + right) / 2;

			if (b[mid] <= a[i])
			{ // 조건이 충족하면 ++
				left = mid + 1;
				cnt = mid;
			}
			else
			{
				right = mid - 1; // 아니라면 --
			}
		}

		if (cnt != -1)
		{
			cout << cnt - i << ' ';
		}
		else {
			cout << "0 ";
		}
	}
}