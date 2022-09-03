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

	long long ans = 0;

	for (int i = 1; i <= n; i++) {
		ans += arr[i].second;
		if (ans >= (sum + 1) / 2) {
			cout << arr[i].first;
			break;
		}
	}
}