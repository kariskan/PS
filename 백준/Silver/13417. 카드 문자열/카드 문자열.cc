#include <iostream>
#include <deque>
using namespace std;

int main() {
	int t; cin >> t;
	while (t--) {
		int n;
		cin >> n;
		deque<char> ans;
		for (int i = 0; i < n; i++) {
			char c; cin >> c;
			if (!i)ans.push_back(c);
			else {
				if (ans[0] >= c) {
					ans.push_front(c);
				}
				else {
					ans.push_back(c);
				}
			}
		}
		for (auto i : ans)cout << i;
		cout << '\n';
	}
}