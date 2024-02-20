#include <string>
#include <vector>

using namespace std;

int gcd(int a,int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int a=arrayA[0],b=arrayB[0];
    for(int i=1;i<arrayA.size();i++){
        a=gcd(a,arrayA[i]);
        b=gcd(b,arrayB[i]);
    }
    printf("%d %d\n", a,b);
    int flag=1;
    for(int i=0;i<arrayA.size();i++){
        if(arrayA[i]%b==0){
            flag=0;
        }
    }
    if(flag){
        answer=max(answer,b);
    }
    flag=1;
    for(int i=0;i<arrayB.size();i++){
        if(arrayB[i]%a==0){
            flag=0;
        }
    }
    if(flag){
        answer=max(answer,a);
    }
    return answer;
}