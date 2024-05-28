#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
#include <set>
#include <cmath>
#include <string>
using namespace std;

long long a[1000000];
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	long long l = 1, r = (long long) 1000000 * 1000000, answer = LLONG_MAX;
	while (l <= r) {
		long long mid = (l + r) / 2;

		long long cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += mid / a[i];
		}

		if (cnt >= m) {
			r = mid - 1;
			answer = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << answer;
}