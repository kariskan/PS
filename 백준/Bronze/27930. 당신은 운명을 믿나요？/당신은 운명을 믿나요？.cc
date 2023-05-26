#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;
    string k = "", y = "";
    for (int i = 0; i < s.length(); i++) {
        if (k == "" && s[i] == 'K') {
            k += s[i];
        } else if (k == "K" && s[i] == 'O') {
            k += s[i];
        } else if (k == "KO" && s[i] == 'R') {
            k += s[i];
        } else if (k == "KOR" && s[i] == 'E') {
            k += s[i];
        } else if (k == "KORE" && s[i] == 'A') {
            k += s[i];
        }
        if (y == "" && s[i] == 'Y') {
            y += s[i];
        } else if (y == "Y" && s[i] == 'O') {
            y += s[i];
        } else if (y == "YO" && s[i] == 'N') {
            y += s[i];
        } else if (y == "YON" && s[i] == 'S') {
            y += s[i];
        } else if (y == "YONS" && s[i] == 'E') {
            y += s[i];
        } else if (y == "YONSE" && s[i] == 'I') {
            y += s[i];
        }
        if (k == "KOREA") {
            cout << k;
            return 0;
        }
        if (y == "YONSEI") {
            cout << y;
            return 0;
        }
    }
}