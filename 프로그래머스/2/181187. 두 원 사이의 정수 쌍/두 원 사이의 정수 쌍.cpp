#include <string>
#include <vector>
#include <cmath>
using namespace std;

long long solution(int r1, int r2) {
    long long r11 = r1;
    long long r22 = r2;
    long long answer = (r22-r11+1)*4;
    for(long long y=1;y<r22;y++){
        long long x1 = sqrt(r11*r11-y*y);
        long long x2 = sqrt(r22*r22-y*y);
        if(y<r1&&fmod(sqrt(r11*r11-y*y),1)==0){
            answer+=4;
        }
        answer += (x2-x1)*4;
    }
    
    return answer;
}