#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int visit[2000001];
int a[21];

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> v;
	for (int i = 1; i < (1 << n); i++) {
		int sum = 0;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				sum += a[j];
			}
		}
		visit[sum] = 1;
	}
	for (int i = 1; i <= 2000000; i++) {
		if (!visit[i]) {
			cout << i;
			return 0;
		}
	}
}