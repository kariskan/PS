#include <iostream>
#include <stack>
using namespace std;

int n, parent[2001], x, y, visi[2001];
int in[2001], ret[2001];

int main()
{
	cin >> n;
	string s;
	cin >> s;
	cin >> x >> y;

	stack<int> st;
	st.push(0);
	int idx = 1;

	for (int i = 0; i < s.length(); i++)
	{

		if (s[i] == '0')
		{
			st.push(idx);
			in[idx++] = i + 1;
		}
		if (s[i] == '1')
		{
			int now = st.top();
			st.pop();
			parent[now] = st.top();
			ret[now] = i + 1;
		}
	}
	int c;
	for (int i = 1; i <= n; i++)
	{
		if (ret[i] == x)
		{
			c = i;
			break;
		}
		if (in[i] == x)
		{
			c = i;
			break;
		}
	}

	while (c != 0)
	{
		visi[c] = 1;
		c = parent[c];
	}

	for (int i = 1; i <= n; i++)
	{
		if (ret[i] == y)
		{
			c = i;
			break;
		}
		if (in[i] == y)
		{
			c = i;
			break;
		}
	}
	while (1)
	{
		if (visi[c])
		{
			cout << in[c] << ' ' << ret[c];
			return 0;
		}
		c = parent[c];
	}
}