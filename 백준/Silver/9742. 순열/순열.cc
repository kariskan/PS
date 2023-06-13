#include <algorithm>
#include <iostream>
using namespace std;

int fac[11];

int main() {
    for (int i = 1; i <= 10; i++) {
        int sum = 1;
        for (int j = 1; j <= i; j++) {
            sum *= j;
        }
        fac[i] = sum;
    }

    while (1) {
        string a;
        int b;
        cin >> a >> b;
        if (cin.eof()) {
            break;
        }
        cout << a << ' ' << b << " = ";
        if (fac[(int)a.length()] < b) {
            cout << "No permutation\n";
            continue;
        }

        sort(a.begin(), a.end());

        do {
            b--;
            if (b == 0) {
                cout << a << '\n';
                break;
            }
        } while (next_permutation(a.begin(), a.end()));
    }
}