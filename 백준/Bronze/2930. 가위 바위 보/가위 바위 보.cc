#include <iostream>
using namespace std;

int r, n;
char a[50];
int b[50][3];

int getScore(char s, char f) {
    if (s == f) {
        return 1;
    }
    if (s == 'S' && f == 'P') {
        return 2;
    }
    if (s == 'P' && f == 'R') {
        return 2;
    }
    if (s == 'R' && f == 'S') {
        return 2;
    }
    return 0;
}

int main() {
    cin >> r;
    for (int i = 0; i < r; i++) {
        cin >> a[i];
    }
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < r; j++) {
            char c;
            cin >> c;
            if (c == 'S') {
                b[j][0]++;
            } else if (c == 'P') {
                b[j][1]++;
            } else {
                b[j][2]++;
            }
            ans += getScore(a[j], c);
        }
    }
    int ans2 = 0;
    for (int i = 0; i < r; i++) {
        char k;
        int temp = 0;
        temp = max(temp, b[i][0] * 2 + b[i][2]);
        temp = max(temp, b[i][1] * 2 + b[i][0]);
        temp = max(temp, b[i][2] * 2 + b[i][1]);
        ans2 += temp;
    }

    cout << ans << '\n' << ans2;
}