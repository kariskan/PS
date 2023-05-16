#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct traf {
    int des;
    string type;
    int fee;
};

int n, r, m, k, board1[100][100], board2[100][100];
map<string, int> city;
vector<string> v;
map<int, vector<traf>> ma;

int main() {
    cin >> n >> r;
    r *= 2;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (city.find(s) == city.end()) {
            city[s] = i;
        }
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        v.push_back(s);
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        string type, c1, c2;
        int fee;
        cin >> type >> c1 >> c2 >> fee;

        ma[city[c1]].push_back({city[c2], type, fee * 2});
        ma[city[c2]].push_back({city[c1], type, fee * 2});
    }

    int citySize = city.size();

    for (int i = 0; i < citySize; i++) {
        for (int j = 0; j < ma[i].size(); j++) {
            traf f = ma[i][j];

            if (board1[i][f.des] == 0 || board1[i][f.des] > f.fee) {
                board1[i][f.des] = f.fee;
            }
            if (board1[f.des][i] == 0 || board1[f.des][i] > f.fee) {
                board1[f.des][i] = f.fee;
            }
        }
    }

    memset(board2, -1, sizeof(board2));
    for (int i = 0; i < citySize; i++) {
        for (int j = 0; j < ma[i].size(); j++) {
            traf f = ma[i][j];

            if (f.type.substr(0, 3) == "ITX" || f.type == "Mugunghwa") {
                f.fee = 0;
            } else if (f.type == "S-Train" || f.type == "V-Train") {
                f.fee /= 2;
            }

            if (board2[i][f.des] == -1 || board2[i][f.des] > f.fee) {
                board2[i][f.des] = f.fee;
            }
        }
    }

    for (int k = 0; k < citySize; k++) {
        for (int i = 0; i < citySize; i++) {
            for (int j = 0; j < citySize; j++) {
                if (i == j) {
                    continue;
                }
                if (board1[i][k] && board1[k][j]) {
                    if (board1[i][j] == 0 || board1[i][j] > board1[i][k] + board1[k][j]) {
                        board1[i][j] = board1[i][k] + board1[k][j];
                    }
                }
            }
        }
    }
    int ans1 = 0;
    for (int i = 1; i < m; i++) {
        ans1 += board1[city[v[i - 1]]][city[v[i]]];
    }

    for (int k = 0; k < citySize; k++) {
        for (int i = 0; i < citySize; i++) {
            for (int j = 0; j < citySize; j++) {
                if (i == j) {
                    continue;
                }
                if (board2[i][k] != -1 && board2[k][j] != -1) {
                    if (board2[i][j] == -1 || board2[i][j] > board2[i][k] + board2[k][j]) {
                        board2[i][j] = board2[i][k] + board2[k][j];
                    }
                }
            }
        }
    }
    int ans2 = r;
    for (int i = 1; i < m; i++) {
        ans2 += board2[city[v[i - 1]]][city[v[i]]];
    }
    if (ans1 > ans2) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}