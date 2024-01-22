#include <string>
#include <vector>

using namespace std;

int get(int n, long long i) {
    if(n==0){
        return 1;
    }
    if(n==1){
        if(i==3){
            return 0;
        }
        return 1;
    }
    int k = get(n-1,(i+4)/5);
    int m = i%5;
    if(k==0||m==3){
        return 0;
    }
    return 1;
}

int solution(int n, long long l, long long r) {
    int answer = 0;
    for(long long i=l;i<=r;i++){
        answer += get(n, i);
    }
    return answer;
}