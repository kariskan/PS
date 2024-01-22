#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool prime(long long n){
    if(n==0||n==1){
        return false;
    }
    for(long long i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

string parse(int n, int k){
    string res = "";
    while(n){
        res+=(n%k)+'0';
        n/=k;
    }
    reverse(res.begin(),res.end());
    return res;
}

int solution(int n, int k) {
    int answer = 0;
    string a = parse(n,k);
    long long sum=0;
    for(int i=0;i<a.length();i++){
        if(sum!=0&&a[i]=='0'){
            if(prime(sum)){
                answer++;
            }
            sum=0;
        }
        sum=sum*10+(a[i]-'0');
    }
    if(sum!=0&&prime(sum)){
        answer++;
    }
    return answer;
}