#include <cmath>
#include <iostream>
using namespace std;

long double a[500];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long double ans = numeric_limits<long double>::max();

    for (int i = m; i <= n; i++) {
        long double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += a[j];
        }
        long double avg = sum / i;
        long double v = 0;
        for (int j = 0; j < i; j++) {
            v += (a[j] - avg) * (a[j] - avg);
        }
        v = sqrt(v / i);
        ans = min(ans, v);

        for (int j = 1; j <= n - i; j++) {
            avg = avg - a[j - 1] / i + a[j + i - 1] / i;
            v = 0;
            for (int k = j; k < j + i; k++) {
                v += (a[k] - avg) * (a[k] - avg);
            }
            v = sqrt(v / i);

            ans = min(ans, v);
        }
    }

    printf("%.7Lf", ans);
}