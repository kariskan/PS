#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> v;
int check[300001];

long long ncr(int r) {
    if(r <= 2) return 0;
    return (r * (r - 1) * (r - 2)) / 6;
}

long long d, g;

int main() {
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n;
    v.resize(n+1);
    
    for(int i=0;i<n-1;i++){
        int a,b;cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    for(int i = 1; i <= n; i++) {
        g += ncr(v[i].size());
        
        check[i] = 1;
        
        for(auto& j: v[i]) {
            if(!check[j]) {
                d += (v[i].size() - 1) * (v[j].size() - 1);
            }
        }
    }
    
    if(d > g * 3) cout<<"D\n";
    else if(d < g * 3) cout<<"G\n";
    else cout<<"DUDUDUNGA\n";
}
