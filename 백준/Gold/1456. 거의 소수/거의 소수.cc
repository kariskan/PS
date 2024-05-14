#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

bool isNotPrime[10000001] = { 1,1, };
int main() {
	long long a, b;
	cin >> a >> b;

	int answer = 0;
	for (long long i = 2; i <= 10000000; i++) {
		if (!isNotPrime[i]) {
			long long num = i;
			while ((double)num <= (double)b / (double)i) {
				if ((double)num >= (double)a / (double)i) {
					answer++;
				}
				num *= i;
			}
			for (int j = i * 2; j <= 10000000; j += i) {
				isNotPrime[j] = true;
			}
		}
	}
	cout << answer;
}