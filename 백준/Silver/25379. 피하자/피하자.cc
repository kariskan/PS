#include <iostream>
using namespace std;

string s;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % 2 == 1) {
            s += "H";
        } else {
            s += "T";
        }
    }

    int HL = 0, TL = 0;
    int pre = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H') {
            HL += i - (pre + 1);
            pre++;
        }
    }
    pre = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'T') {
            TL += i - (pre + 1);
            pre++;
        }
    }
    cout << min(HL, TL);
}