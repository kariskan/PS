#include <string>
#include <vector>

using namespace std;

int c(int n){
    int res=0;
    while(n){
        res+=n%2;
        n/=2;
    }
    return res;
}

bool get(int n,int i){
    return c(n)==c(i);
}

int solution(int n) {
    for(int i=n+1;;i++){
        if(get(n,i)){
            return i;
        }
    }
}