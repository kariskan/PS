#include <iostream>
#include <queue>
#include <map>
using namespace std;

int a, b, c, d;
map<pair<int, int>, int> m;

int main() {

	cin >> a >> b >> c >> d;

	queue<pair<int, int>> q;
	m[{0, 0}] = 1;
	q.push({ 0,0 });

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (m.count({ a, y }) == 0) {
			m[{a, y}] = m[{x, y}] + 1;
			q.push({ a,y });
		}
		if (m.count({ x,b }) == 0) {
			m[{x, b}] = m[{x, y}] + 1;
			q.push({ x,b });
		}

		if (m.count({ 0, y }) == 0) {
			m[{0, y}] = m[{x, y}] + 1;
			q.push({ 0,y });
		}
		if (m.count({ x,0 }) == 0) {
			m[{x, 0}] = m[{x, y}] + 1;
			q.push({ x,0 });
		}

		if (b > x + y && m.count({ 0,x + y }) == 0) {
			m[{0, x + y}] = m[{x, y}] + 1;
			q.push({ 0,x + y });
		}
		if (b <= x + y && m.count({ x + y - b,b }) == 0) {
			m[{ x + y - b, b}] = m[{x, y}] + 1;
			q.push({ x + y - b,b });
		}

		if (a > x + y && m.count({ x + y,0 }) == 0) {
			m[{x + y, 0}] = m[{x, y}] + 1;
			q.push({ x + y,0 });
		}
		if (a <= x + y && m.count({ a,x + y - a }) == 0) {
			m[{ a, x + y - a }] = m[{x, y}] + 1;
			q.push({ a,x + y - a });
		}

	}

	if (m.count({ c,d }) == 0)cout << -1;
	else cout << m[{c, d}] - 1;
}