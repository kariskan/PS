#include <iostream>
#include <vector>
using namespace std;

int n, mp, mf, ms, mv;
int a[15][5];
int ans = -1;
vector<int> seq;
bool check(vector<int> v)
{
	if (seq.empty())
	{
		return true;
	}
	for (int i = 0; i < min(seq.size(), v.size()); i++)
	{
		if (v[i] < seq[i])
		{
			return true;
		}
	}
	return v.size() < seq.size();
}
void go(int idx, int nmp, int nmf, int nms, int nmv, int val, vector<int> v)
{
	if (nmp >= mp && nmf >= mf && nms >= ms && nmv >= mv)
	{
		if (ans == -1 || ans >= val)
		{
			ans = val;
			if (check(v))
			{
				seq.clear();
				seq = v;
			}
		}
	}
	if (idx >= n)
	{
		return;
	}
	go(idx + 1, nmp, nmf, nms, nmv, val, v);
	v.push_back(idx + 1);
	go(idx + 1, nmp + a[idx][0], nmf + a[idx][1], nms + a[idx][2], nmv + a[idx][3], val + a[idx][4], v);
}
int main()
{
	cin >> n >> mp >> mf >> ms >> mv;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1] >> a[i][2] >> a[i][3] >> a[i][4];
	}
	go(0, 0, 0, 0, 0, 0, {});

	cout << ans << '\n';
	for (int i = 0; i < seq.size(); i++)
	{
		cout << seq[i] << ' ';
	}
}