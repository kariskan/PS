#include <iostream>
#include <map>
#include <queue>
using namespace std;
map<string, int> m;
int main() {
	string s = "";
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			char c; cin >> c;
			s += c;
		}
	}
	queue<string> q;
	q.push(s);
	m[s] = 1;
	int x[4] = { 0,0,1,-1 };
	int y[4] = { 1,-1,0,0 };
	while (!q.empty()) {
		string s = q.front();
		q.pop();
		if (s == "123456780") {
			cout << m[s] - 1;
			return 0;
		}
		int idx = s.find('0');
		int i = idx / 3;
		int j = idx % 3;
		for (int k = 0; k < 4; k++) {
			int nx = i + x[k];
			int ny = j + y[k];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string t = s;
				char temp;
				temp = t[idx];
				t[idx] = t[nx * 3 + ny];
				t[nx * 3 + ny] = temp;
				if (m.find(t) == m.end()) {
					q.push(t);
					m[t] = m[s] + 1;
				}
			}
		}
	}
	cout << -1;
}