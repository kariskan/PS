#include <iostream>
using namespace std;

int l, n, arr[1001];
int s[1001];

int main() {
    cin >> l >> n;
    int ans1 = 0, ans2 = 0, inter = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (inter < b - a) {
            inter = b - a;
            ans1 = i + 1;
        }
        for (int j = a; j <= b; j++) {
            if (!arr[j]) {
                arr[j] = i + 1;
            }
        }
    }

    for (int i = 1; i <= 1000; i++) {
        if (arr[i]) {
            s[arr[i]]++;
        }
    }
    inter = 0;
    for (int i = 1; i <= n; i++) {
        if (inter < s[i]) {
            inter = s[i];
            ans2 = i;
        }
    }
    cout << ans1 << '\n' << ans2;
}