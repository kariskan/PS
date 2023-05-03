#include <iostream>
using namespace std;
int a[5];
int main() {
    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    while (1) {
        bool flag = false;
        for (int i = 0; i < 4; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                for (int j = 0; j < 5; j++) {
                    cout << a[j] << ' ';
                }
                cout << '\n';
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
    }
}