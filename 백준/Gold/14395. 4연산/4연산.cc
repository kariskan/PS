#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	if (n == m)cout << 0;
	else if (m == 1)cout << '/';
	else if (m == 0)cout << '-';
	else {
		queue<long long> q;
		map<long long, string> v;
		vector<string> ans;
		q.push(n);
		v[n] = "";
		while (!q.empty()) {
			long long a = q.front();
			q.pop();
			if (a == m) {
				ans.push_back(v[a]);
				continue;
			}
			if (a == 0 || a>1000000000000000000)continue;
			
			if (v.find(a * a) == v.end()) {
				v.insert({ a * a, v[a] + '*' });
				q.push(a * a);
			}
			if (v.find(a + a) == v.end()) {
				v.insert({ a + a, v[a] + '+' });
				q.push(a + a);
			}
			if (v.find(a / a) == v.end()) {
				v.insert({ a / a, v[a] + '/' });
				q.push(a / a);
			}
		}
		if (ans.empty())cout << -1;
		else {
			int vSize = ans.size();
			string res = ans[0];
			for (int i = 1; i < vSize; i++) {
				if (res < ans[i])res = ans[i];
			}
			cout << res;
		}
	}
}