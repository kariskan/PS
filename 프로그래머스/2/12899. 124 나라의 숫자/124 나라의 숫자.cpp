#include <string>
#include <vector>

using namespace std;

int d[3]={1,2,4};
string solution(int n) {
    string answer = "";
    int digit=1;
    int p=3,sum=0;
    while(sum+p<n){
        digit++;
        sum+=p;
        p*=3;
    }
    // digit=3,p=27,sum=12
    p/=3;
    for(int i=1;i<=digit;i++){
        int temp=(n-sum-1)/p; // 0
        answer+=d[temp]+'0';
        printf("%d %d %d %d\n",i,n,sum,p,temp);
        n-=p*(temp+1);
        sum-=p;
        p/=3;
    }
    return answer;
}