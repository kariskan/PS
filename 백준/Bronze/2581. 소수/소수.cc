#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <climits>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

bool isPrime(int n){
    if(n<2){
        return false;
    }
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main() {
    int a,b;cin>>a>>b;
    int ans=-1,sum=0;
    for(int i=a;i<=b;i++){
        if(isPrime(i)){
            if(ans==-1){
                ans=i;
            }
            sum+=i;
        }
    }
    if(ans==-1){
        cout<<-1;
    }else{
        cout<<sum<<'\n'<<ans;
    }
}