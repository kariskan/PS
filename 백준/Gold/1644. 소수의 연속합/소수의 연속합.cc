#include <iostream>
using namespace std;
int n;
int prime[4000001];
int idx;
int a[4000001];
void p() {
    for (int i = 2; i <= n; i++) {
        if (prime[i]) continue;
        prime[idx++] = i;
        for (int j = i * 2; j <= n; j += i) {
            prime[j] = 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    p();
    int p1 = 0, p2 = 0;
    int ans = 0, sum = prime[0];
    while (p1 <= p2 && p2 < idx) {
        if (sum == n) {
            ans++;
            sum += prime[++p2];
        }
        else if (sum > n) {
            sum -= prime[p1++];
            if (p1 > p2) {
                p2 = p1;
                sum = prime[p1];
            }
        }
        else {
            sum += prime[++p2];
        }
    }
    cout << ans;
}