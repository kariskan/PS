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

int main() {
    int n;
    vector<pair<int,int>> v;
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;cin>>a>>b;
        v.push_back({a,b});
    }
    int ans=0,grade;
    for(int i=1;i<=5;i++){
        vector<int> prefix(n);
        if(v[0].first==i||v[0].second==i){
            prefix[0]=1;
        }
        for(int j=1;j<n;j++){
            if(v[j].first==i||v[j].second==i){
                prefix[j]=prefix[j-1]+1;
            }
        }
        for(int j=0;j<n;j++){
            if(ans<prefix[j]){
                ans=prefix[j];
                grade=i;
            }
        }
    }
    cout<<ans<<' '<<grade;
}