#include <iostream>
using namespace std;

int n, r, c;

int main() {
    cin >> n >> r >> c;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if ((i + j) % 2 == (r + c) % 2) {
                cout << "v";
            } else {
                cout << '.';
            }
        }
        cout << '\n';
    }
}