#include <iostream>
using namespace std;

int a[9][2];

int main() {
    int s1 = 0, s2 = 0, flag = 0;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[j][i];
        }
    }
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 2; j++) {
            if (j == 0) {
                s1 += a[i][j];
            } else {
                s2 += a[i][j];
            }
            if (s1 > s2) {
                flag = 1;
            }
        }
    }
    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}