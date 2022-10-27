#include <climits>
#include <iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while (cin >> n, n != 0)
	{
		int arr[250001] = {
			0,
		};
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i];
			arr[i] += arr[i - 1];
		}

		int minValue = 0;
		int ans = INT_MIN;

		for (int i = 1; i <= n; i++)
		{	
			ans = max(ans, arr[i] - minValue);
			
			if (minValue > arr[i])
			{
				minValue = arr[i];
			}
		}
		
		cout << ans << '\n';
	}
}