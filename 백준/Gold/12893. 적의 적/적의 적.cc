#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v;
int n, m, p[2001];
int e[2001];

int Find(int x)
{
	if (p[x] == x)
	{
		return x;
	}
	return p[x] = Find(p[x]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);

	p[a] = b;
}

int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		p[i] = i;
	}

	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;

		int pa = Find(a);
		int pb = Find(b);

		if (pa == pb)
		{
			cout << 0;
			return 0;
		}

		if (e[a] != 0)
		{
			Union(e[a], b);
		}
		else {
			e[a] = b;
		}
		
		if (e[b] != 0)
		{
			Union(e[b], a);
		}
		else {
			e[b] = a;
		}
	}

	cout << 1;
}