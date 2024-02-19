#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int k, int d) {
    long long K=k,D=d;
    long long answer=(D/K)*2+1;
    for(long long i=K;i<D;i+=K){
        long long s=sqrt(D*D-i*i);
        if(s==0){
            break;
        }
        answer+=s/K;
    }
    return answer;
}