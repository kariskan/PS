#include <iostream>
#include <string>
#include <queue>
using namespace std;

queue<int> q;
int n, t, g, visit[100000];

int parse(int a) {
	string s = to_string(a *= 2);
	s[0]--;
	if (s[0] == '0')s.erase(s.begin());
	if (s.empty())return 0;
	return stoi(s);
}

int main() {
	cin >> n >> t >> g;

	q.push(n);
	visit[n] = 1;

	while (!q.empty()) {
		int a = q.front();
		q.pop();

		if (visit[a] - 1 > t) continue;
		if (a == g) {
			cout << visit[a] - 1;
			return 0;
		}

		//btn A
		if (a + 1 < 100000 && !visit[a + 1]) {
			visit[a + 1] = visit[a] + 1;
			q.push(a + 1);
		}

		//btn B
		if (a != 0 && a * 2 < 100000) {
			int p = parse(a);
			if (!visit[p]) {
				visit[p] = visit[a] + 1;
				q.push(p);
			}
		}
	}

	cout << "ANG";
}