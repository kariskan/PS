#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		queue<pair<string, int>> q;
		q.push({ "1", 1 % n });
		int visit[20000] = { 0, };
		while (!q.empty()) {
			string s = q.front().first;
			int m = q.front().second;
			q.pop();
			if (s.length() > 100) {
				cout << "BRAK\n";
				break;
			}
			if (m == 0) {
				cout << s << "\n";
				break;
			}
			if (!visit[((m % n) * 10) % n]) {
				q.push({ s + "0",((m % n) * 10) % n });
				visit[((m % n) * 10) % n] = 1;
			}
			if (!visit[((m % n) * 10 + 1) % n]) {
				q.push({ s + "1",((m % n) * 10 + 1) % n });
				visit[((m % n) * 10 + 1) % n] = 1;
			}
		}
	}
}