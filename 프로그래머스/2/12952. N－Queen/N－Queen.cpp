#include <string>
#include <vector>

using namespace std;
int a[13],n,answer;
bool isValid(int col,int idx){
    for(int i=1;i<col;i++){
        if(a[i]==idx||abs(col-i)==abs(a[i]-idx)){
            return false;
        }
    }
    return true;
}
void go(int col) {
    if(col>n){
        answer++;
        return;
    }
    for(int i=1;i<=n;i++){
        if(isValid(col,i)){
            a[col]=i;
            go(col+1);
            a[col]=0;
        }
    }
}
int solution(int n) {
    ::n=n;
    go(1);
    return answer;
}