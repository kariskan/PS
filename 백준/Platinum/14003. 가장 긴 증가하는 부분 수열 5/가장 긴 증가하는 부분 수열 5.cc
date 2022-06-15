#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[1000001];
int seq[1000001];
vector<int> dp;
int ans[1000001];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp.push_back(arr[0]);
	int maxi = 0;
	for (int i = 1; i < n; i++) {
		if (dp.back() < arr[i]) {
			dp.push_back(arr[i]);
			seq[i] = dp.size() - 1;
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
			seq[i] = start;
		}
		maxi = max(seq[i], maxi);
	}
	cout << dp.size() << "\n";
	for (int i = n - 1; i >= 0; i--) {
		if (seq[i] == maxi) {
			ans[maxi] = arr[i];
			maxi--;
		}
		if (maxi < 0)break;
	}
	for (int i = 0; i < dp.size(); i++) {
		cout << ans[i] << " ";
	}
	return 0;
}