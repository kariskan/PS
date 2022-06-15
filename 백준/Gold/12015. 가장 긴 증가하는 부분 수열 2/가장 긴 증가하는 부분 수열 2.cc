#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000001];
vector<int> dp;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp.push_back(arr[0]);
	for (int i = 1; i < n; i++) {
		if (dp.back() < arr[i]) {
			dp.push_back(arr[i]);
		}
		else {
			int start = 0;
			int end = dp.size() - 1;
			int mid = (start + end) / 2;
			while (start <= end) {
				mid = (start + end) / 2;

				if (arr[i] <= dp[mid]) {
					end = mid - 1;
				}
				else {
					start = mid + 1;
				}
			}
			dp[start] = arr[i];
		}
	}
	cout << dp.size();
	return 0;
}