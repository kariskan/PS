#include <iostream>
using namespace std;

int n;

int main()
{
	cin >> n;
	while (n--)
	{
		int t;
		cin >> t;
		int a[20] = {
			0,
		};
		int ans = 0;
		for (int i = 0; i < 20; i++)
		{
			int num;
			cin >> num;
			bool isExist = false;
			int idx = i;
			for (int j = 0; j < i; j++)
			{
				if (num < a[j])
				{
					isExist = true;
					idx = j;
					break;
				}
			}
			if (isExist)
			{
				for (int j = i; j > idx; j--)
				{
					a[j] = a[j - 1];
					ans++;
				}
			}
			a[idx] = num;
		}
		cout << t << ' ' << ans << '\n';	
	}
}