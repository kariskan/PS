#include <cmath>
#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    if (n == 0) {
        cout << 0;
    }

    else if (n == 1) {
        cout << 1;
    } else {
        cout << ceil(log2(n)) + 1;
    }
}