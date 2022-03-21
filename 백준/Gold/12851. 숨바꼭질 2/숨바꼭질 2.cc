#include <iostream>
#include <queue>
using namespace std;
pair<int, int> visit[200001];
int main() {
	int n, m;
	cin >> n >> m;
	queue<int> q;
	q.push(n);
	visit[n] = { 1,1 };
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		if (a + 1 <= 200000) {
			if (!visit[a + 1].first || visit[a + 1].first > visit[a].first + 1) {
				visit[a + 1].first = visit[a].first + 1;
				visit[a + 1].second = 1;
				q.push(a + 1);
			}
			else if (visit[a + 1].first == visit[a].first + 1) {
				visit[a + 1].second++;
				q.push(a + 1);
			}
		}
		if (a - 1 >= 0) {
			if (!visit[a - 1].first || visit[a - 1].first > visit[a].first + 1) {
				visit[a - 1].first = visit[a].first + 1;
				visit[a - 1].second = 1;
				q.push(a - 1);
			}
			else if (visit[a - 1].first == visit[a].first + 1) {
				visit[a - 1].second++;
				q.push(a - 1);
			}
		}
		if (a * 2 <= 200000) {
			if (!visit[a * 2].first || visit[a * 2].first > visit[a].first + 1) {
				visit[a * 2].first = visit[a].first + 1;
				visit[a * 2].second = 1;
				q.push(a * 2);
			}
			else if (visit[a * 2].first == visit[a].first + 1) {
				visit[a * 2].second++;
				q.push(a * 2);
			}
		}
	}
	cout << visit[m].first - 1 << "\n" << visit[m].second;
}