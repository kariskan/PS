#include <iostream>
using namespace std;

int ans;

void go(int n) {
    if (n <= 1) {
        return;
    }
    ans += (n / 2) * (n - n / 2);
    go(n / 2);
    go(n - n / 2);
}

int main() {
    int n;
    cin >> n;
    go(n);
    cout << ans;
}