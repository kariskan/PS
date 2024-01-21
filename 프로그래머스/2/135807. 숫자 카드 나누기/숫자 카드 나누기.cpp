#include <string>
#include <vector>
using namespace std;

int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int a=arrayA[0],b=arrayB[0];
    for(int i=1;i<arrayA.size();i++){
        a=gcd(a,arrayA[i]);
        b=gcd(b,arrayB[i]);
    }
    bool flagA=true,flagB=true;
    for(int i=0;i<arrayA.size();i++){
        if(arrayB[i]%a==0){
            flagA=false;
        }
        if(arrayA[i]%b==0){
            flagB=false;
        }
    }
    if(!flagA){
        a=0;
    }
    if(!flagB){
        b=0;
    }
    return max(a,b);
}