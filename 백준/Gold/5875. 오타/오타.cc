#include <iostream>
#include <vector>
using namespace std;

string s;

int main() {
    cin >> s;

    int leftCnt = 0, rightCnt = 0, totalCnt = 0, ans = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            leftCnt++;
            totalCnt++;
        } else {
            rightCnt++;
            totalCnt--;
        }
        
        if(totalCnt == 1) {
            leftCnt = 0;
        }
        if(totalCnt == -1) {
            ans = rightCnt;
            break;
        }
    }
    
    if(totalCnt == 2) {
        ans = leftCnt;
    }
    
    cout << ans;
}