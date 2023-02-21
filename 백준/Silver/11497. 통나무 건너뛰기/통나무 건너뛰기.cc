#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//freopen("jump.inp", "r", stdin);
	//freopen("jump.out", "w", stdout);

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		deque<int> d;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			int temp;
			cin >> temp;
			v.push_back(temp);
		}
		sort(v.begin(), v.end());
		d.push_back(v[n - 1]);
		int ans = 0;
		int count = 1;
		for (int i = n - 2; i >= 0; i-=2) {
			d.push_front(v[i]);
			ans = max(ans, abs(d[0] - d[1]));
			if (n > count + 1) {
				d.push_back(v[i - 1]);
				ans = max(ans, abs(d[count] - d[count + 1]));
			}
			count += 2;
		}
		cout << max(ans, abs(d[0] - d[n - 1])) << "\n";
	}
}