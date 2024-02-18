#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long R1=r1;
    long long R2=r2;
    long long answer = (R2-R1+1)*4;
    for(long long i=1;i<R2;i++){
        long long coor1=sqrt(R1*R1-i*i);
        long long coor2=sqrt(R2*R2-i*i);
        answer+=(coor2-coor1)*4;
        if(i<R1&&coor1*coor1==R1*R1-i*i){
            answer+=4;
        }
    }
    return answer;
}