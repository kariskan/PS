#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <cstring>

using namespace std;



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    getline(cin, s);

    for (int i = 0; i < s.length() - 1; i++) {
        if (s.substr(i, 2) == "D2" || s.substr(i, 2) == "d2") {
            cout << "D2";
            return 0;
        }
    }

    cout << "unrated";
}