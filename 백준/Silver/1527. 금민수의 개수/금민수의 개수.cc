#include <iostream>
#include <vector>
using namespace std;

vector<int> v;

void go(long long num) {
	if (num > 1000000000) {
		return;
	}
	v.push_back(num);

	go(num * 10 + 4);
	go(num * 10 + 7);
}

int main() {
	int n, m;
	cin >> n >> m;

	go(0);
	int ans = 0;
	for (auto& i : v) {
		if (i >= n && i <= m) {
			ans++;
		}
	}
	cout << ans;
}