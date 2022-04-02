#include <iostream>
#include <stack>
using namespace std;

int n;
stack<pair<long long, long long>> st;

int main() {

	cin >> n;

	long long ans = 0;
	for (int i = 0; i < n; i++) {
		long long a;
		cin >> a;
		if (st.empty()) {
			st.push({ a,1 });
		}
		else {
			if (st.top().first < a) {
				int cnt = 1;
				while (!st.empty() && st.top().first <= a) {
					if (st.top().first == a)cnt += st.top().second;
					ans += st.top().second;
					st.pop();
				}
				if (!st.empty())ans++;
				st.push({ a,cnt });
			}
			else if (st.top().first == a) {
				st.top().second++;
				if (st.size() == 1)ans += st.top().second - 1;
				else ans += st.top().second;
			}
			else {
				st.push({ a,1 });
				ans++;
			}
		}
	}
	cout << ans;
}