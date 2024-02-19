#include <string>
#include <vector>

using namespace std;

int get(int n, long long i){
    if(n==0){
        return 1;
    }
    if(n==1){
        if(i==2){
            return 0;
        }
        return 1;
    }
    int pre=get(n-1,i/5);
    if(pre==0){
        return 0;
    }
    if(i%5==2){
        return 0;
    }
    return 1;
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    for(long long i=l;i<=r;i++){
        if(get(n,i-1)==1){
            answer++;
        }
    }
    return answer;
}