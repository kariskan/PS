#include <iostream>
using namespace std;

int n, m, a[200000];
long long sum[200000];
void calculate()
{
	long long ret = 0;
	for (int i = 0; i < n; i++)
	{
		sum[i] = a[i] * a[(i + 1) % n] * a[(i + 2) % n] * a[(i + 3) % n];
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	calculate();
	long long ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret += sum[i];
	}

	for (int i = 0; i < m; i++)
	{
		int num;
		cin >> num;
		num--;
		a[num] = -a[num];
		long long temp = ret;
		for (int j = (num - 3 + n) % n, k = 0; k < 4; j = (j + 1) % n, k++)
		{
			sum[j] = -sum[j];
			temp += 2 * sum[j];
		}
		ret = temp;
		cout << temp << '\n';
	}
}