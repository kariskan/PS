#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a[1000] = { 0, }, d[1000] = { 0, }, o[1000] = { 0, };
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	int idx;
	for (int i = 0; i < n; i++) {
		d[i] = 1;
		o[i] = i;
		for (int j = 0; j <= i; j++) {
			if (a[j] < a[i]) {
				if (d[i] < d[j] + 1) {
					d[i] = d[j] + 1;
					o[i] = j;
				}
			}
		}
		if (ans < d[i]) {
			ans = d[i];
			idx = i;
		}
	}
	vector<int> order;
	while (idx != o[idx]) {
		order.push_back(a[idx]);
		idx = o[idx];
	}
	order.push_back(a[idx]);
	reverse(order.begin(), order.end());
	cout << ans << "\n";
	int orSize = order.size();
	for (int i = 0; i < orSize; i++) {
		cout<<order[i] << " ";
	}
}