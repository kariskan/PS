#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[10000];
int n;
int day[10001];
bool compare(pair<int, int>& p1, pair<int, int>& p2) {
	if (p1.first == p2.first) {
		return p1.second < p2.second;
	}
	return p1.first > p2.first;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n, compare);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int date = arr[i].second;
		while (day[date]) {
			date--;
		}
		if (date != 0) {
			day[date] = arr[i].first;
			ans += day[date];
		}
	}
	cout << ans;
}