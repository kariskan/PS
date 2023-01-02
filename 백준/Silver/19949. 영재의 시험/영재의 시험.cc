#include <iostream>
#include <vector>
using namespace std;

int inp[10], ans;

void go(vector<int> v, int score)
{
	if (v.size() == 10)
	{
		if (score >= 5)
		{
			ans++;
		}
		return;
	}

	int vSize = v.size();
	for (int i = 1; i <= 5; i++)
	{
		if (vSize >= 2 && v[vSize - 1] == v[vSize - 2] && v[vSize - 1] == i)
		{
			continue;
		}
		v.push_back(i);
		int ns = score + (inp[vSize] == i ? 1 : 0);
		go(v, ns);
		v.pop_back();
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		cin >> inp[i];
	}
	go({}, 0);
	cout << ans;
}