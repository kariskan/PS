#include <iostream>
#include <map>
using namespace std;

int m[6][3][3], a[55];  // 큐브 모양
int t, n;

// 전개도
int seq[6][12] = {
    {36, 37, 38, 18, 19, 20, 45, 46, 47, 27, 28, 29},  // U
    {33, 34, 35, 51, 52, 53, 24, 25, 26, 42, 43, 44},  // D
    {6, 7, 8, 44, 41, 38, 11, 10, 9, 45, 48, 51},      // F
    {2, 1, 0, 53, 50, 47, 15, 16, 17, 36, 39, 42},     // B
    {0, 3, 6, 35, 32, 29, 9, 12, 15, 18, 21, 24},      // L
    {8, 5, 2, 26, 23, 20, 17, 14, 11, 27, 30, 33}      // R
};

int te[3][3];  // 돌리기 위한 임시 배열

// 매핑
char ch[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
map<char, int> ma = {{'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5}, {'-', 3}, {'+', 1}};

// 돌리는 면, 횟수
void rot(int idx, int cnt) {
    char temp[12];

    while (cnt--) {
        // 옆 면 돌리기
        for (int i = 0; i < 12; i++) {
            temp[i] = a[seq[idx][i]];
        }

        // 세 칸을 뭉쳐서 밀어버린다
        for (int i = 0; i < 12; i++) {
            a[seq[idx][i]] = temp[(i + 3) % 12];
        }

        // 해당 면 돌리기
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                te[j][2 - i] = a[m[idx][i][j]];
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                a[m[idx][i][j]] = te[i][j];
            }
        }
    }
}

int main() {
    cin >> t;

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                m[i][j][k] = i * 9 + j * 3 + k;
            }
        }
    }

    while (t--) {
        cin >> n;

        // 전개도 초기화
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 9; j++) {
                a[i * 9 + j] = ch[i];
            }
        }

        for (int i = 0; i < n; i++) {
            char a, b;
            cin >> a >> b;
            rot(ma[a], ma[b]);
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << char(a[m[0][i][j]]);
            }
            cout << '\n';
        }
    }
}
