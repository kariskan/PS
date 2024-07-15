#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <map>
#include <cmath>
#include <mutex>
#include <sstream>
using namespace std;

bool isPrime[4000001];
vector<int> prime;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 2; i * i <= n; i++) {
        if (!isPrime[i]) {
            for (int j = i * 2; j <= n; j += i) {
                isPrime[j] = true;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (!isPrime[i]) {
            prime.push_back(i);
        }
    }

    int l = 0, r = 0, sum = 2;

    int ans = 0;
    while (l <= r && r < prime.size()) {
        if (sum == n) {
            ans++;
        }

        if (sum <= n) {
            sum += prime[++r];
        } else {
            sum -= prime[l++];
        }
    }

    cout << ans;
}
