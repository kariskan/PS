#include <string>
#include <vector>

using namespace std;
int num[4][4] = { {1,2,3},{4,5,6},{7,8,9},{-1,0,-1} };
string solution(vector<int> numbers, string hand) {
    string answer = "";
    pair<int, int> l = { 3, 0 }, r = { 3, 2 };
    for (int n : numbers) {
        int a = 0;
        if (n == 1 || n == 4 || n == 7) {
            answer.push_back('L');
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (num[i][j] == n) {
                        l = { i,j };
                    }
                }
            }
        }
        else if (n == 3 || n == 6 || n == 9) {
            answer.push_back('R');
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (num[i][j] == n) {
                        r = { i,j };
                    }
                }
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 3; j++) {
                    if (num[i][j] == n) {
                        if (abs(i - l.first) + abs(j - l.second) < abs(i - r.first) + abs(j - r.second)) {
                            answer.push_back('L');
                            l = { i,j };
                        }
                        else if (abs(i - l.first) + abs(j - l.second) > abs(i - r.first) + abs(j - r.second)) {
                            answer.push_back('R');
                            r = { i,j };
                        }
                        else {
                            if (hand == "left") {
                                answer.push_back('L');
                                l = { i,j };
                            }
                            else {
                                answer.push_back('R');
                                r = { i,j };
                            }
                        }
                    }
                }
            }
        }
    }
    return answer;
}