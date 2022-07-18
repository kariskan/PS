#include <iostream>
#include <queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	int da;
	priority_queue<int> pq;
	for (int i = 0; i < n; i++) {
		if (!i)cin >> da;
		else {
			int num; cin >> num;
			pq.push(num);
		}
	}
	int ans = 0;
	while (!pq.empty() && pq.top() >= da) {
		int num = pq.top(); pq.pop();
		pq.push(num - 1);
		da++;
		ans++;
	}
	cout << ans;

}