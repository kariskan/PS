#include <string>
#include <vector>

using namespace std;

int solution(int num) {
    int answer = 0;
    long long n = num;
    if(n==1)return 0;
    for(int i=1;;i++){
        if(n%2==0)n=n/2;
        else n=n*3+1;
        if(n==1)return i;
        if(i>=500)return -1;
    }
}