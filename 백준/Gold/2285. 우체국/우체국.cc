#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n;
pair<long long, long long> arr[100001];
long long sum;

int main() {

	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i].first >> arr[i].second;
		sum += arr[i].second;
	}

	sort(arr + 1, arr + 1 + n);

	long long ans = 0, minAns = LLONG_MAX, idx = 0;

	for (int i = 1; i <= n; i++) {
		long long left = ans;
		long long right = sum - ans - arr[i].second;
		ans += arr[i].second;
		if (abs(left - right) < minAns) {
			minAns = abs(left - right);
			idx = arr[i].first;
		}
	}

	cout << idx;
}