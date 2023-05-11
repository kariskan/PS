#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    getline(cin, s);

    string firstVar;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            firstVar = s.substr(0, i);
            break;
        }
    }

    string temp = "";
    vector<string> var;
    for (int i = firstVar.length() + 1; i < s.length(); i++) {
        if (s[i] == ',' || s[i] == ';') {
            var.push_back(temp);
            temp = "";
            i++;
        } else {
            temp += s[i];
        }
    }
    if (temp != "") {
        var.push_back(temp);
    }
    for (int i = 0; i < var.size(); i++) {
        // cout<<var[i]<<'\n';
        reverse(var[i].begin(), var[i].end());
        cout << firstVar;
        int idx;
        for (int j = 0; j < var[i].size(); j++) {
            if (var[i][j] != '[' && var[i][j] != ']' && var[i][j] != '*' && var[i][j] != '&') {
                idx = j;
                break;
            }
            if (var[i][j] == ']') {
                cout << "[]";
                j++;
                continue;
            }
            cout << var[i][j];
        }
        cout << ' ';
        for (int j = var[i].size() - 1; j >= idx; j--) {
            cout << var[i][j];
        }
        cout << ';' << '\n';
    }
}