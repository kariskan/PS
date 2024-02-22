#include <string>
#include <vector>
#include <set>
using namespace std;
set<int> se;
string numbers;
bool isPrime(int n){
    if(n==0||n==1){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}
void go(int now,int idx,vector<int> vis){
    if(idx>numbers.size()){
        return;
    }
    if(isPrime(now)){
        se.insert(now);
    }
    for(int i=0;i<vis.size();i++){
        if(!vis[i]){
            vis[i]=1;
            go(now*10+(numbers[i]-'0'),idx+1,vis);
            vis[i]=0;
        }
    }
}

int solution(string numbers) {
    ::numbers=numbers;
    vector<int> vis(numbers.size());
    go(0,0,vis);
    return se.size();
}