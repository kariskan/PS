#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = -1;
    for(long long i=1;i*i<=n;i++){
        if(i*i==n){
            answer=(i+1)*(i+1);
            break;
        }
    }
    return answer;
}