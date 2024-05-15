#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while (1) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}

		long long arr[250001] = { 0, };
		// -3 4 9 -2 -5 8
		// -3 1 6  4 -1 7
		long long mi = 0, answer = LLONG_MIN;
		for (int i = 1; i <= n; i++) {
			cin >> arr[i];
			arr[i] += arr[i - 1];
			answer = max(answer, arr[i] - mi);
			mi = min(mi, arr[i]);
		}
		cout << answer << '\n';
	}
}