#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a, int b)
{
	return a > b;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int arr[1000] = {
			0,
		};
		for (int i = 0; i < m; i++)
		{
			int a, b;
			cin >> a >> b;
			arr[i] = a * b;
		}
		sort(arr, arr + m, compare);
		int cnt = 0;
		while (n > 0)
		{
			n -= arr[cnt++];
		}
		cout << cnt << '\n';
	}
}