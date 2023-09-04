#include <iostream>
using namespace std;

int getD(int n) {
    int cnt = 0;
    while (n) {
        n /= 10;
        cnt++;
    }
    return cnt;
}
int n;
void go(int num, int cnt, int digit, int vis[10]) {
    if (cnt == digit) {
        int copy[10] = {0};
        for (int i = 0; i <= 9; i++) {
            copy[i] = vis[i];
        }
        int other = n - num;
        int temp = other;
        if (temp <= 0) {
            return;
        }
        while (temp) {
            if (copy[temp % 10]) {
                return;
            }
            copy[temp % 10] = 1;
            temp /= 10;
        }
        cout << num << " + " << other;
        exit(0);
    }
    for (int i = 0; i < 10; i++) {
        if (i == 0 && cnt == 0) {
            continue;
        }
        if (!vis[i]) {
            vis[i] = 1;
            go(num * 10 + i, cnt + 1, digit, vis);
            vis[i] = 0;
        }
    }
}

int main() {
    cin >> n;
    int digit = getD(n);
    for (int i = 1; i <= digit; i++) {
        int vis[10] = {0};
        go(0, 0, i, vis);
    }
    cout << -1;
}