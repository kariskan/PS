#include <iostream>
using namespace std;
long long cost[100001];
long long money[100001];
int n;
int main() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> cost[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> money[i];
	}
	long long ans = 0;
	for (int i = 1; i < n; i++) {
		int less = i;
		long long sum = 0;
		while (money[i] <= money[less]) {
			sum += cost[less];
			less++;
		}
		ans += sum * money[i];
		i = less - 1;
	}
	cout << ans;
}