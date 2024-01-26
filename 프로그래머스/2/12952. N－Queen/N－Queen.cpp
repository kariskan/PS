#include <string>
#include <vector>

using namespace std;
int answer,n;
int a[12];
void go(int idx){
    if(idx>=n){
        answer++;
        return;
    }
    for(int i=0;i<n;i++){
        bool flag=true;
        for(int j=0;j<idx;j++){
            if(a[j]==i||abs(j-idx)==abs(i-a[j])){
                flag=false;
                break;
            }
        }
        if(flag){
            a[idx]=i;
            go(idx+1);
            a[idx]=0;
        }
    }
}
int solution(int n) {
    ::n=n;
    go(0);
    return answer;
}