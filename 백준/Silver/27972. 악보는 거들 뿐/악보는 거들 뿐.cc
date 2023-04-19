#include <iostream>
using namespace std;

int a[500001], b[500001], c[500001];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, ans = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 뒤에서 부터 앞으로 오면서 증가하는 수열의 최대 길이를 구함
    b[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] > a[i + 1]) {  // 증가한다면
            b[i] = b[i + 1] + 1;
        } else if (a[i] == a[i + 1]) {  // 같다면
            b[i] = b[i + 1];
        } else {  // 감소한다면
            b[i] = 1;
        }
        ans = max(ans, b[i]);
    }

    // 앞에서 부터 뒤로 가면서 증가하는 수열의 최대 길이를 구함
    c[0] = 1;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {  // 증가한다면
            c[i] = c[i - 1] + 1;
        } else if (a[i] == a[i - 1]) {  // 같다면
            c[i] = c[i - 1];
        } else {  // 감소한다면
            c[i] = 1;
        }
        ans = max(ans, c[i]);
    }

    cout << ans;
}