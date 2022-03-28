#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[50], b[50];
vector <vector<int>> seq(1001);
bool compare(int a1, int a2) {
	return a1 > a2;
}
void run(int num) {
	int temp = num;
	int idx = 0;
	while (temp) {
		if (temp % 2 == 0) {
			seq[num].push_back(2);
			temp /= 2;
		}
		else {
			seq[num].push_back(1);
			temp--;
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= 1000; i++) {
		run(i);
	}
	sort(b, b + n, compare);
	int plusSum = 0, maxDouble = 0;
	for (int i = 0; i < n; i++) {
		if (b[i]) {
			int tempDouble = 0;
			for (int k : seq[b[i]]) {
				if (k == 1) {
					plusSum++;
				}
				else {
					tempDouble++;
				}
			}
			maxDouble = max(maxDouble, tempDouble);
		}
	}
	cout << plusSum + maxDouble;
}