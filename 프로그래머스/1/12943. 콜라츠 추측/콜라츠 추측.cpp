#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    while(n!=1){
        if(n%2==0){
            n/=2;
        }else{
            n=n*3+1;
        }
        answer++;
        if(answer>500){
            return -1;
        }
    }
    return answer;
}