#include <cstring>
#include <iostream>
using namespace std;

int dp[10001];
pair<int, int> inp[5001];
int c;
double p;

int main() {
    while (cin >> c >> p, c != 0 && p != 0) {
        memset(dp, 0, sizeof(dp));
        int P = p * 100 + 0.5;
        for (int i = 1; i <= c; i++) {
            double a, b;
            cin >> a >> b;
            inp[i] = {a, b * 100 + 0.5};
        }
        for (int i = 1; i <= c; i++) {
            for (int j = inp[i].second; j <= 10000; j++) {
                dp[j] = max(dp[j], dp[j - inp[i].second] + inp[i].first);
            }
        }

        cout << dp[P] << '\n';
    }
}