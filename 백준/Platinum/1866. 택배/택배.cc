#include <algorithm>
#include <iostream>
using namespace std;

int n, box[3001], truck, helicopter, dp[3001], sum[3001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> box[i];
    }
    cin >> truck >> helicopter;

    sort(box + 1, box + 1 + n);

    for (int i = 1; i <= n; i++) {
        sum[i] = box[i] + sum[i - 1];
        dp[i] = dp[i - 1] + box[i] * truck;

        for (int j = 1; j <= i; j++) {
            int mid = (i + j) / 2;
            int left = truck * (box[mid] * (mid - j + 1) - (sum[mid] - sum[j - 1]));
            int right = truck * (sum[i] - sum[mid - 1] - box[mid] * (i - mid + 1));

            dp[i] = min(dp[i], dp[j - 1] + helicopter + left + right);
        }
    }
    
    cout << dp[n];
}