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

int n, k, board[10][10], a[3][21];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // 2일 경우, i가 j를 이김, 1일 경우 비김, 0일 경우 i가 j한테 짐
            cin >> board[i][j];
        }
    }

    for (int i = 1; i <= 2; i++) {
        for (int j = 0; j < 20; j++) {
            cin >> a[i][j];
        }
    }

    vector<int> seq;
    for (int i = 0; i < n; i++) {
        seq.push_back(i + 1);
    }
    do {
        for (int i = 0; i < n; i++) {
            a[0][i] = seq[i];
        }
        int score[3] = {0,}, idx[3] = {0,};
        int first = 0, second = 1, pending = 2;
        while (idx[0] < n) {
            int p1 = a[first][idx[first]++];
            int p2 = a[second][idx[second]++];
            if (board[p1][p2] == 2) {
                score[first]++;
                swap(second, pending);
            } else if (board[p1][p2] == 0) {
                score[second]++;
                int temp = first;
                first = second;
                second = temp;
                swap(second, pending);
            } else {
                if (first < second) {
                    score[second]++;
                    int temp = first;
                    first = second;
                    second = temp;
                    swap(second, pending);
                } else {
                    score[first]++;
                    swap(second, pending);
                }
            }
            if (score[0] >= k) {
                cout << 1;
                return 0;
            }
            if (score[1] >= k || score[2] >= k) {
                break;
            }
        }
    } while (next_permutation(seq.begin(), seq.end()));
    cout << 0;
}