#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int answer,vis[7];
string numbers;
set<int> se;
bool isPrime(int n){
    if(n<=1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void go(int num,int cnt){
    if(isPrime(num)){
        se.insert(num);
    }
    if(cnt>=numbers.length()){
        return;
    }
    for(int i=0;i<numbers.length();i++){
        if(!vis[i]){
            vis[i]=1;
            go(num*10+(numbers[i]-'0'),cnt+1);
            vis[i]=0;
        }
    }
}
int solution(string numbers) {
    ::numbers=numbers;
    go(0,0);
    return (int)se.size();
}