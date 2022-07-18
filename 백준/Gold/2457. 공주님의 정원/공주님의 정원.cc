#include <iostream>
#include <algorithm>
using namespace std;
int day[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
pair<int, int> inp[100000];
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int m1, d1;
		cin >> m1 >> d1;
		inp[i].first = day[m1 - 1] + d1;
		cin >> m1 >> d1;
		inp[i].second = day[m1 - 1] + d1 - 1;
	}
	sort(inp, inp + n);
	int now = day[2] + 1;
	int idx = 0;
	int ans = 0;
	while (now <= day[11] && idx < n) {
		int maxDay = -1;
		for (; inp[idx].first <= now && idx < n; idx++) {
			if (maxDay < inp[idx].second) {
				maxDay = inp[idx].second;
			}
		}
		if (maxDay == -1) {
			cout << 0;
			return 0;
		}
		ans++;
		now = maxDay + 1;
	}
	if (now <= day[11])cout << 0;
	else cout << ans;
}