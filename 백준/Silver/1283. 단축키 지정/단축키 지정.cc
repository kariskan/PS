#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <stack>
#include <climits>
#include <cstring>
#include <set>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

int vis[26];
vector<string> split(string s) {
    stringstream ss(s);
    vector<string> v;
    string temp;
    while (getline(ss, temp, ' ')) {
        v.push_back(temp);
    }
    return v;
}

// 대소문자 구분없이 몇 번째 알파벳인지 구하는 함수
int toIdx(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a';
    }
    return c - 'A';
}

void shortOutput(string s) {
    vector<string> v = split(s);
    for (int i = 0; i < v.size(); i++) {
        string t = v[i];
        // 각 단어의 첫 글자가 단축키로 사용되지 않았으면
        if (!vis[toIdx(t[0])]) {
            // 현재 단어의 첫 글자를 단축키로 지정
            vis[toIdx(t[0])] = 1;
            for (int j = 0; j < v.size(); j++) {
                // 현재 단어가 단축키를 포함하고 있으면
                if (i == j) {
                    cout << '[' << v[j][0] << ']';
                    if (v[j].size() >= 2) {
                        cout << v[j].substr(1);
                    }
                    if (j != v.size() - 1) {
                        cout << ' ';
                    }
                } else {
                    cout << v[j];
                    if (j != v.size() - 1) {
                        cout << ' ';
                    }
                }
            }
            cout << '\n';
            return;
        }
    }
    // 단어 상관없이 공백 제외한 모든 알파벳을 검사함
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            continue;
        }
        // 현재 알파벳이 단축키로 사용되지 않았다면
        if (!vis[toIdx(s[i])]) {
            // 현재 알파벳을 단축키로 지정
            vis[toIdx(s[i])] = 1;
            cout << s.substr(0, i) << '[' << s[i] << ']';
            if (s.length() >= i + 2) {
                cout << s.substr(i + 1);
            }
            cout << '\n';
            return;
        }
    }
    // 단축키 없으면 그냥 출력
    cout << s << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        shortOutput(s);
    }
}