#include <iostream>
#include <string>
#include <map>
#include <cstring>
#include <queue>
using namespace std;

int n, k;
int ans, len;
int m[1000001];

int main() {
	cin >> n >> k;
	len = to_string(n).length();
	if (len < 2) {
		cout << -1;
		return 0;
	}
	queue<string> q;
	string s = to_string(n);
	m[stoi(s)] = 1;
	q.push(s);
	int ans = -1;
	int t = 0;
	while (t < k && !q.empty()) {
		int qSize = q.size();
		memset(m, 0, sizeof(m));
		for (int Q = 0; Q < qSize; Q++) {
			string now = q.front();
			q.pop();

			for (int i = 0; i < now.length() - 1; i++) {
				for (int j = i + 1; j < now.length(); j++) {
					if (i == 0 && now[j] == '0')continue;
					string ns = now;
					swap(ns[i], ns[j]);
					if (m[stoi(ns)])continue;
					q.push(ns);
					m[stoi(ns)] = 1;
					if (t == k - 1 && ans < stoi(ns))ans = stoi(ns);
				}
			}
		}

		t++;
	}
	cout << ans;
}