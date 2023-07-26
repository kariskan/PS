#include <iostream>
using namespace std;

int n, a[100000];

int main() {
    cin >> n;
    bool up = false, down = false;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i == 0) {
            continue;
        }
        if (a[i] > a[i - 1]) {
            if (down == true) {
                cout << "NO";
                return 0;
            }
            up = true;
        } else if (a[i] < a[i - 1]) {
            down = true;
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}