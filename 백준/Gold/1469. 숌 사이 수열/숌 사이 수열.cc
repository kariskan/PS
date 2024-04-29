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
    vector<int> v,seq;

    cin>>n;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
        seq.push_back(i);
    }
    vector<int> ans;
    do{
        vector<int> temp(n*2, 17);
        int idx=0;
        bool flag = true;
        for(int s:seq){
            while(idx<n*2&&temp[idx]!=17){
                idx++;
            }
            temp[idx]=v[s];
            if(temp[idx+v[s]+1]!=17){
                flag = false;
                break;
            }
            if(idx+v[s]+1>=2*n){
                flag=false;
                break;
            }
            temp[idx+v[s]+1]=v[s];
        }
        if(flag){
            if(ans.empty()){
                ans=temp;
                continue;
            }
            for(int i=0;i<n*2;i++){
                if(ans[i]<temp[i]){
                    break;
                }
                if(ans[i]>temp[i]){
                    ans=temp;
                    break;
                }
            }
        }
    }while(next_permutation(seq.begin(), seq.end()));
    if(ans.empty()){
        cout<<-1;
        return 0;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<' ';
    }
}