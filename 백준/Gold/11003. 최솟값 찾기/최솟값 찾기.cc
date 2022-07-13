//#include <iostream>
//#include <queue>
//using namespace std;
//
//int n, l;
//int a[5000001];
//priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
//int main() {
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//	cin >> n >> l;
//	for (int i = 1; i <= n; i++) {
//		cin >> a[i];
//		q.push({ a[i], i });
//		while (q.top().second < i - l + 1)q.pop();
//		cout << q.top().first << ' ';
//	}
//}

#include <iostream>
#include <deque>
using namespace std;

int n, l;
int a[5000001];
deque<pair<int, int>> dq;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> l;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		while (!dq.empty() && dq.back().first > a[i]) dq.pop_back();
		while (!dq.empty() && dq.front().second < i - l + 1)dq.pop_front();
		dq.push_back({ a[i], i });
		cout << dq.front().first << ' ';
	}
}