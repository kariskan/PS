#include <iostream>
using namespace std;
int a[100001];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	int left = 1, right = n;
	int ans = 200000000;
	while (left < right)
	{
		int s = a[right] + a[left];
		if (abs(ans) >= abs(s))
		{
			ans = s;
		}

		if (s < 0)
		{
			left++;
		}
		else
		{
			right--;
		}
	}

	cout << ans;
}