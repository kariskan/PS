#include <iostream>
#include <queue>
using namespace std;

int visit[100001];

bool ok(int n) {
	if (n > 100000 || n < 0 || visit[n])return false;
	return true;
}

int main() {

	int A, B, n, m;
	cin >> A >> B >> n >> m;

	queue<int> q;
	q.push(n);
	visit[n] = 1;

	while (!q.empty()) {
		int a = q.front();
		q.pop();
		
		if (a == m) {
			cout << visit[a] - 1;
			return 0;
		}

		if (ok(a - 1)) {
			visit[a - 1] = visit[a] + 1;
			q.push(a - 1);
		}
		if (ok(a + 1)) {
			visit[a + 1] = visit[a] + 1;
			q.push(a + 1);
		}
		if (ok(a - A)) {
			visit[a - A] = visit[a] + 1;
			q.push(a - A);
		}
		if (ok(a - B)) {
			visit[a - B] = visit[a] + 1;
			q.push(a - B);
		}
		if (ok(a + A)) {
			visit[a + A] = visit[a] + 1;
			q.push(a + A);
		}
		if (ok(a + B)) {
			visit[a + B] = visit[a] + 1;
			q.push(a + B);
		}
		if (ok(a * A)) {
			visit[a * A] = visit[a] + 1;
			q.push(a * A);
		}
		if (ok(a * B)) {
			visit[a * B] = visit[a] + 1;
			q.push(a * B);
		}
	}
}