#include <iostream>
using namespace std;

int n, k;
int x[1000001]; // x[i]: i번째 좌표에 x[i]만큼의 양의 얼음이 있다.

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int coor, ice; // 좌표, 얼음 양
		cin >> ice >> coor;
		x[coor] = ice;
	}
	long long ans = 0, sum = 0;
	// 초기 세팅
	for (int i = 0; i <= k; i++)
	{
		if (i <= 1000000)
		{
			sum += x[i];
		}
	}

	ans = sum;

	for (int i = 1; i <= 1000000; i++)
	{
		if (i + k <= 1000000)
		{
			sum += x[i + k];
		}
		if (i - k - 1 >= 0)
		{
			sum -= x[i - k - 1];
		}
		ans = max(ans, sum);
	}
	cout << ans;
}