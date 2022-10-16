#include <iostream>
#include <vector>
using namespace std;

int n,t,r,d,s;
vector<vector<pair<int, int>>> v;

void go(int node, int pre, int depth, int sum) {
    if(depth >= d) {
        if((depth == d && sum < s) || depth > d) {
            r = node;
            d = depth;
            s = sum;
        }
    }
    
    for(auto&i:v[node]) {
        if(i.first != pre) {
            go(i.first, node, depth + 1, sum + i.second);
        }
    }
}

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>t;
    v.resize(n+1);
    
    for(int i=0;i<n-1;i++){
        int a,b,c;cin>>a>>b>>c;
        v[a].push_back({b,c});
        v[b].push_back({a,c});
    }
    
    go(1, 0, 0, 0);
    d = 0; s = 0;
    go(r, 0, 0, 0);
    cout<<s / t + (s % t == 0 ? 0 : 1)<<'\n';
}
