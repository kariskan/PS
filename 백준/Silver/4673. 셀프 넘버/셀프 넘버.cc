#include <iostream>
using namespace std;

int arr[10001];

int get(int n) {
	int ret = n;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

int main() {

	for (int i = 1; i <= 10000; i++) {
		if (!arr[i]) {
			cout << i << "\n";
			int a = i;
			while (a <= 10000) {
				a = get(a);
				arr[a] = 1;
			}
		}
	}
}