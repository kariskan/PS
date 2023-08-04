#include <iostream>
using namespace std;

int n;
string s[100];

int main() {
    cin >> n;
    int k1, k2;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == "KBS1") {
            for (int j = 0; j < i; j++) {
                cout << "1";
            }
            for (int j = i - 1; j >= 0; j--) {
                swap(s[j], s[j + 1]);
                cout << "4";
            }
        }
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == "KBS2") {
            for (int j = 0; j < i; j++) {
                cout << "1";
            }
            for (int j = i - 1; j >= 1; j--) {
                swap(s[j], s[j + 1]);
                cout << "4";
            }
        }
    }
}