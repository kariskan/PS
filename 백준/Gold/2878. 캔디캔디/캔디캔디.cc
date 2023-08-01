#include <algorithm>
#include <iostream>
using namespace std;

long long a[100001];

int main() {
    long long m, n, sum = 0;
    cin >> m >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    sort(a + 1, a + n + 1);

    long long ans = 0;
    sum -= m;

    for (int i = 1; i <= n; i++) {
        long long k = min(a[i], sum / (n - i + 1));
        ans += k * k;
        sum -= k;
    }

    cout << ans;
}