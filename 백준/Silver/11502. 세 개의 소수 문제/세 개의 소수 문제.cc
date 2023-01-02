#include <iostream>
#include <vector>
using namespace std;

int p[1001];
vector<int> prime;

void go(int a)
{
	int s = prime.size();
	for (int i = 0; i < s; i++)
	{
		for (int j = i; j < s; j++)
		{
			for (int k = j; k < s; k++)
			{
				if (prime[i] + prime[j] + prime[k] == a)
				{
					cout << prime[i] << ' ' << prime[j] << ' ' << prime[k] << '\n';
					return;
				}
			}
		}
	}
	cout << "0\n";
}

int main()
{
	int n;
	cin >> n;

	for (int i = 2; i <= 1000; i++)
	{
		if (!p[i])
		{
			prime.push_back(i);
			for (int j = i * 2; j <= 1000; j += i)
			{
				p[j] = 1;
			}
		}
	}

	for (int t = 0; t < n; t++)
	{
		int a;
		cin >> a;
		go(a);
	}
}