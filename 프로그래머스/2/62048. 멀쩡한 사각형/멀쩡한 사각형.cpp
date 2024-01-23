#include <cmath>
#include <iostream>
using namespace std;

long long solution(int w,int h) {
    long long answer=0;
    long long W=w,H=h;
    double last=0;
    for(long long i=1;i<=W;i++){
        double now = ((double)H*i)/W;
        answer+=(long long)ceil(now)-(long long)floor(last);
        // printf("%lf %lf %lld\n", last, now, (long long)ceil(now)-(long long)floor(last));
        last=now;
    }
    return W*H-answer;
}