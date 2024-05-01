#include <iostream>
using namespace std;

int a[1001], dp[1001];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    dp[1] = a[1];
    int answer = dp[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j]) {
                dp[i] = max(dp[i], dp[j] + a[i]);
            }
        }
        answer = max(answer, dp[i]);
    }
    cout << answer;
}