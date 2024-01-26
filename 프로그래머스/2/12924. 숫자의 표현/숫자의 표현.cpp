#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int l=0,r=0,s=0;
    while(r<=n){
        if(s==n){
            answer++;
        }
        if(s<=n){
            r++;
            s+=r;
        }else if(s>n){
            s-=l;
            l++;
        }
    }
    return answer;
}