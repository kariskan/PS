#include <iostream>
#include <deque>
using namespace std;

deque<int> d;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;

	int highest = max(a, b);
	for (int i = 1; i < a; i++)
	{
		d.push_back(i);
	}
	d.push_back(highest);
	for (int i = b - 1; i >= 1; i--)
	{
		d.push_back(i);
	}
	if (d.size() > n)
	{
		cout << -1;
		return 0;
	}
	int first = d.front();
	d.pop_front();
	int dSize = d.size();
	for (int i = 1; i <= n - dSize - 1; i++)
	{
		d.push_front(1);
	}
	d.push_front(first);
	for (auto &i : d)
	{
		cout << i << ' ';
	}
}