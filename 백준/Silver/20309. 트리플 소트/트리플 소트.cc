#include <iostream>
using namespace std;

int n, a[300001], pos[300001];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] % 2 != i % 2) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}