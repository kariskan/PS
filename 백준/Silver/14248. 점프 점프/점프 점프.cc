#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int a[100001], vis[100001];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int s;
	cin >> s;
	queue<int> q;
	q.push(s);
	vis[s] = 1;

	int answer = 0;
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		answer++;

		if (now - a[now] >= 1 && !vis[now - a[now]]) {
			q.push(now - a[now]);
			vis[now - a[now]] = 1;
		}
		if (now + a[now] <= n && !vis[now + a[now]]) {
			q.push(now + a[now]);
			vis[now + a[now]] = 1;
		}
	}

	cout << answer;
}