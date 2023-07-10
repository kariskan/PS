#include <iostream>
using namespace std;

void toCamel(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '_') {
            cout << (char)(s[i + 1] - 'a' + 'A');
            i++;
            continue;
        } else if (i == 0 && s[i] >= 'A' && s[i] <= 'Z') {
            cout << (char)(s[i] - 'A' + 'a');
            continue;
        }
        cout << s[i];
    }
    cout << '\n';
}

void toSnake(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            if (i != 0) {
                cout << "_";
            }
            cout << (char)(s[i] - 'A' + 'a');
            continue;
        }
        cout << s[i];
    }
    cout << '\n';
}

void toPascal(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (i == 0 && s[i] >= 'a' && s[i] <= 'z') {
            cout << (char)(s[i] - 'a' + 'A');
            continue;
        } else if (s[i] == '_') {
            cout << (char)(s[i + 1] - 'a' + 'A');
            i++;
            continue;
        }
        cout << s[i];
    }
    cout << '\n';
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    if (n == 1) {
        cout << s << '\n';
        toSnake(s);
        toPascal(s);
    } else if (n == 2) {
        toCamel(s);
        cout << s << '\n';
        toPascal(s);
    } else {
        toCamel(s);
        toSnake(s);
        cout << s << '\n';
    }
}