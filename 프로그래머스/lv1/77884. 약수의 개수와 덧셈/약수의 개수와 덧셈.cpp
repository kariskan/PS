#include <string>
#include <vector>

using namespace std;

int solution(int left, int right) {
    int answer = 0;
    for(int num=left;num<=right;num++){
        int cnt=0;
        for(int i=1;i*i<=num;i++){
            if(i*i==num){
                cnt++;
                break;
            }
            if(num%i==0){
                cnt+=2;
            }
        }
        if(cnt%2==0)answer+=num;
        else answer-=num;
    }
    return answer;
}