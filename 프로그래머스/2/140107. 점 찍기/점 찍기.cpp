#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long K = k;
    long long D = d;
    long long answer = 0;
    for(long long i=0;i<=D;i+=K){
        answer+=(long long)sqrt(D*D-i*i)/K+1;
        // printf("%lld\n", (long long)sqrt(D*D-i*i)/K);
    }
    return answer;
}