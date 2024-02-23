#include <string>
#include <vector>
using namespace std;
int solution(int n) {
    int answer = 0;
    int left=1,right=1,sum=1;
    while(right<=n){
        if(sum<=n){
            if(sum==n){
                answer++;
            }
            sum+=(++right);
        }else{
            sum-=(left++);
        }
    }
    return answer;
}