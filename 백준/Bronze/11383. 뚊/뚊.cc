#include <iostream>
using namespace std;

string s1[10], s2[10], res[10];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> s2[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < s1[i].length(); j++) {
            res[i] += s1[i][j];
            res[i] += s1[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < res[i].length(); j++) {
            if (s2[i][j] != res[i][j]) {
                cout << "Not Eyfa";
                return 0;
            }
        }
    }
    cout << "Eyfa";
}