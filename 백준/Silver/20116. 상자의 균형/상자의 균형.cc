#include <iostream>
using namespace std;
int a[200001];
double s[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = n - 1; i > 0; i--)
	{
		s[i] = (s[i + 1] * (n - i - 1) + a[i]) / (n - i);
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] - l >= s[i + 1] || a[i] + l <= s[i + 1])
		{
			cout << "unstable";
			return 0;
		}
	}
	cout << "stable";
}