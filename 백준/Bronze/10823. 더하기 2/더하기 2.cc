#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    string s, t = "";
    while (1) {
        cin >> s;
        if (cin.eof()) {
            break;
        }
        t += s;
    }

    stringstream ss(t);
    string temp;
    long long ans = 0;
    while (getline(ss, temp, ',')) {
        ans += stoll(temp);
    }

    cout << ans;
}