#include <string>
#include <cmath>
#include <iostream>
using namespace std;
int a[4] = {1, 2, 4};
long long getT[20]={0,};
void go() {
    int t=0,p=3,cnt=1;
    while (cnt<20) {
        getT[cnt]=t;
        t+=p;
        p*=3;
        cnt++;
    }
}

string solution(int n) {
    go();
    int t = 0, p = 3, cnt = 0;
    while (t < n) {
        t += p;
        cnt++;
        p *= 3;
    }
    string answer = "";
    while (cnt) {
        int nxt = (n - getT[cnt] - 1) / (long long) pow(3, cnt - 1);
        answer += a[nxt] + '0';
        n -= (nxt + 1) * (long long) pow(3, cnt - 1);
        cnt--;
    }
    return answer;
}