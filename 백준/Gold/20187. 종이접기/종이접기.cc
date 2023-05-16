// #include <iostream>
// #include <vector>
// using namespace std;

// int k, h;
// vector<char> seq;
// int map[257][257];

// struct dot {
//     int x;
//     int y;
//     int pos;
// };

// int getPos(char dir, int now) {
//     if (dir == 'L' || dir == 'R') {
//         if (now == 0 || now == 1) {
//             return 1 - now;
//         }
//         if (now == 2 || now == 3) {
//             return 5 - now;
//         }
//     } else {
//         if (now == 0) {
//             return 2;
//         } else if (now == 2) {
//             return 0;
//         } else if (now == 1) {
//             return 3;
//         }
//         return 1;
//     }
// }

// void go(int idx, vector<dot> pos, int i1, int i2, int j1, int j2) {
//     if (idx < 0) {
//         return;
//     }
//     int siz = pos.size();
//     if (seq[idx] == 'L') {
//         for (int i = 0; i < siz; i++) {
//             pos.push_back({pos[i].x, 2 * j1 - pos[i].y - 1, getPos(seq[idx], pos[i].pos)});
//             map[pos[i].x][2 * j1 - pos[i].y - 1] = getPos(seq[idx], pos[i].pos);
//         }
//         j1 = 2 * j1 - j2 - 1;
//     } else if (seq[idx] == 'R') {
//         for (int i = 0; i < siz; i++) {
//             pos.push_back({pos[i].x, 2 * j2 - pos[i].y + 1, getPos(seq[idx], pos[i].pos)});
//             map[pos[i].x][2 * j2 - pos[i].y + 1] = getPos(seq[idx], pos[i].pos);
//         }
//         j2 = 2 * j2 - j1 + 1;
//     } else if (seq[idx] == 'U') {
//         for (int i = 0; i < siz; i++) {
//             pos.push_back({2 * i1 - pos[i].x - 1, pos[i].y, getPos(seq[idx], pos[i].pos)});
//             map[2 * i1 - pos[i].x - 1][pos[i].y] = getPos(seq[idx], pos[i].pos);
//         }
//         i1 = 2 * i1 - i2 - 1;
//     } else {  // D
//         for (int i = 0; i < siz; i++) {
//             pos.push_back({2 * i2 - pos[i].x + 1, pos[i].y, getPos(seq[idx], pos[i].pos)});
//             map[2 * i2 - pos[i].x + 1][pos[i].y] = getPos(seq[idx], pos[i].pos);
//         }
//         i2 = 2 * i2 - i1 + 1;
//     }
//     go(idx - 1, pos, i1, i2, j1, j2);
// }

// int main() {
//     cin >> k;
//     int i1 = 1, i2 = 1 << k, j1 = 1, j2 = 1 << k;
//     for (int i = 0; i < k * 2; i++) {
//         char a;
//         cin >> a;
//         if (a == 'R') {
//             a = 'L';
//             j1 = (j1 + j2) / 2 + 1;
//         } else if (a == 'D') {
//             a = 'U';
//             i1 = (i1 + i2) / 2 + 1;
//         } else if (a == 'L') {
//             a = 'R';
//             j2 = (j1 + j2) / 2;
//         } else {
//             a = 'D';
//             i2 = (i1 + i2) / 2;
//         }
//         seq.push_back(a);
//     }
//     cin >> h;

//     map[i1][j1] = h;
//     go(seq.size() - 1, {{i1, j1, h}}, i1, i2, j1, j2);

//     for (int i = 1; i <= (1 << k); i++) {
//         for (int j = 1; j <= (1 << k); j++) {
//             cout << map[i][j] << ' ';
//         }
//         cout << '\n';
//     }
// }

#include <stdio.h>
#include <vector>
#define NMAX 10
using namespace std;
 
int N, H;
char c;
 
vector< char > inp;
int maps[1<<NMAX][1<<NMAX];
 
// 대칭값으로 변환
int convert(int val, int k) {
    if(k == 0) {
        switch(val) {
            case 0: return 2;
            case 1: return 3;
            case 2: return 0;
            default: return 1;
        }
    }
 
    else {
        switch(val) {
            case 0: return 1;
            case 1: return 0;
            case 2: return  3;
            default: return 2;
        }
    }
}
 
 
void sv(int idx, int i1, int i2, int j1, int j2) {
    if(idx == N*2) maps[i1][j1] = H;
    else {
        if(inp[idx] == 'U') {
            sv(idx+1, i1, (i1+i2)/2, j1, j2);
 
            for(int i=(i1+i2)/2+1;i<=i2;i++) {
                for(int j=j1;j<=j2;j++) {
                    maps[i][j] = convert(maps[(i1+i2) - i][j], 0);
                }
            }
        }
 
        else if(inp[idx] == 'D') {
            sv(idx+1, (i1+i2)/2+1, i2, j1, j2);
 
            for(int i=i1;i<=(i1+i2)/2;i++) {
                for(int j=j1;j<=j2;j++) {
                    maps[i][j] = convert(maps[(i1+i2) - i][j], 0);
                }
            }
        }
 
        else if(inp[idx] == 'R') {
            sv(idx+1, i1, i2, (j1+j2)/2+1, j2);
 
            for(int i=i1;i <=i2;i++) {
                for(int j=j1;j<=(j1+j2)/2;j++) {
                    maps[i][j] = convert(maps[i][(j1+j2) - j], 1);
                }
            }
        }
 
        else {
            sv(idx+1, i1, i2, j1, (j1+j2)/2);
 
            for(int i=i1;i<=i2;i++) {
                for(int j=(j1+j2)/2+1;j<=j2;j++) {
                    maps[i][j] = convert(maps[i][(j1+j2) - j], 1);
                }
            }
        }
    }
}
 
int main() {
    // 입력
    scanf("%d\n", &N);
    for(int i=0;i<N*2;i++) {
        scanf("%c ", &c);
        inp.push_back(c);
    }
    scanf("%d", &H);
 
    // solve
    sv(0, 1, 1<<N, 1, 1<<N);
    
    // 출력
    for(int i=1;i<=(1<<N);i++,puts(""))
        for(int j=1;j<=(1<<N);j++) printf("%d ", maps[i][j]);
        
}
