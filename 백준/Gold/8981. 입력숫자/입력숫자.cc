#include <iostream>
using namespace std;

int num[101], ans[101];

int main() {
    int i, n;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    cout << n << '\n';

    int count = 0, idx = 0;

    while (1) {
        ans[idx] = num[count];

        if (count == n - 1) {
            break;
        }

        idx = (idx + num[count]) % n;
        while (ans[idx] != 0) {
            idx = (idx + 1) % n;
        }

        count++;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}