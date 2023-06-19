#include <iostream>
using namespace std;

int n, s, r, damaged[11], l[11];

int main() {
    cin >> n >> s >> r;
    for (int i = 0; i < s; i++) {
        int a;
        cin >> a;
        damaged[a] = 1;
    }
    for (int i = 0; i < r; i++) {
        int a;
        cin >> a;
        l[a] = 1;
    }
    for (int i = 1; i <= n; i++) {
        if (damaged[i] && l[i]) {
            damaged[i] = 0;
            l[i] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        if (!damaged[i]) {
            continue;
        }
        if (l[i - 1]) {
            l[i - 1] = 0;
            damaged[i] = 0;
            continue;
        }
        if (l[i + 1]) {
            l[i + 1] = 0;
            damaged[i] = 0;
            continue;
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (damaged[i]) {
            ans++;
        }
    }
    cout << ans;
}