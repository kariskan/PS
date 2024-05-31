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

using namespace std;

string t[10][5] = {
        {"###", "#.#", "#.#", "#.#", "###"},
        {"..#", "..#", "..#", "..#", "..#"},
        {"###", "..#", "###", "#..", "###"},
        {"###", "..#", "###", "..#", "###"},
        {"#.#", "#.#", "###", "..#", "..#"},
        {"###", "#..", "###", "..#", "###"},
        {"###", "#..", "###", "#.#", "###"},
        {"###", "..#", "..#", "..#", "..#"},
        {"###", "#.#", "###", "#.#", "###"},
        {"###", "#.#", "###", "..#", "###"}
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s[5];
    for (int i = 0; i < 5; i++) {
        getline(cin, s[i]);
    }

    for (int j = 0; j < s[0].length(); j += 4) {
        for (int num = 0; num < 10; num++) {
            bool flag = true;
            for (int i = 0; i < 5; i++) {
                for (int k = 0; k < 3; k++) {
                    if (t[num][i][j % 4 + k] == '.' && s[i][j + k] == '#') {
                        flag = false;
                        break;
                    }
                }
            }
            if (flag) {
                cout << num;
                if (j == 4) {
                    cout << ":";
                }
                break;
            }
        }
    }
}