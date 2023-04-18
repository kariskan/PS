#include <cmath>
#include <iostream>
using namespace std;

int get(long long n) {
    int cnt = 0;
    while (n) {
        cnt++;
        n /= 10;
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    long long n, m;
    cin >> n >> m;
    long long g = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = get(i);
        g = ((g * (long long)pow(10, cnt)) % m + i) % m;
    }

    cout << g;
}