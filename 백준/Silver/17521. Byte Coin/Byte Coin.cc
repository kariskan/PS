#include <iostream>
using namespace std;

int main() {
	long long a[16] = { 0, }, n, w, c;
	cin >> n >> w;;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i < n; i++) {
		int idx = i;
		if (a[i] < a[i + 1]) {
			c = w / a[i];
			w -= c * a[i];
			while (idx < n && a[idx] < a[idx + 1]) {
				idx++;
			}
			i = idx - 1;
			w += c * a[idx];
		}
		else {
			continue;
		}
	}
	cout << w;
}