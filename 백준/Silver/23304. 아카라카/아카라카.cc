#include <algorithm>
#include <iostream>
using namespace std;

bool isPal(string s) {
    if (s.length() == 1) {
        return true;
    }
    string temp = s;
    reverse(temp.begin(), temp.end());
    return s == temp && isPal(s.substr(0, s.length() / 2)) && isPal(s.substr(s.length() - s.length() / 2));
}

int main() {
    string s;
    cin >> s;
    if (isPal(s)) {
        cout << "AKARAKA";
    } else {
        cout << "IPSELENTI";
    }
}