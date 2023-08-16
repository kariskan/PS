#include <algorithm>
#include <iostream>
using namespace std;

int n, a[100000], b[100000];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    int adx = 0, bdx = 0, score = 0;
    while (adx < n && bdx < n) {
        if (a[adx] < b[bdx]) {
            score++;
            adx++;
            bdx++;
        } else {
            bdx++;
        }
    }
    if (score >= (n + 1) / 2) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}