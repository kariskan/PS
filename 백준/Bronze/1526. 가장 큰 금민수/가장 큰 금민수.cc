#include <iostream>
using namespace std;

bool check(int n) {
    while (n) {
        if (n % 10 != 4 && n % 10 != 7) {
            return false;
        }
        n /= 10;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    while (1) {
        if (check(n)) {
            cout << n;
            return 0;
        }
        n--;
    }
}
