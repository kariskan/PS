#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string get(int n,int k){
    string res="";
    while(n){
        res+=(n%k+'0');
        n/=k;
    }
    reverse(res.begin(),res.end());
    return res;
}
bool isPrime(long long a){
    if(a==0||a==1){
        return false;
    }
    for(long long i=2;i*i<=a;i++){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int solution(int n, int k) {
    int answer = 0;
    string g=get(n,k);
    string temp="";
    for(int i=0;i<g.length();i++){
        if(g[i]=='0'){
            if(temp!=""&&isPrime(stoll(temp))){
                answer++;
            }
            temp="";
            continue;
        }
        temp+=g[i];
    }
    if(temp!=""&&isPrime(stoll(temp))){
        answer++;
    }
    return answer;
}