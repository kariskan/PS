#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<string>> relation;
int answer;
vector<int> q;
bool valid(vector<int> v){
    if(v.empty()){
        return false;
    }
    set<string> t;
    for(int i=0;i<relation.size();i++){
        string s="";
        for(int j=0;j<v.size();j++){
            s+=relation[i][v[j]];
        }
        if(t.find(s)!=t.end()){
            return false;
        }
        t.insert(s);
    }
    return true;
}
void go(vector<int> v,int idx){
    if(valid(v)){
        int sum=0;
        for(int i=0;i<v.size();i++){
            sum+=(1<<v[i]);
        }
        q.push_back(sum);
        answer++;
    }
    if(idx==relation[0].size()){
        return;
    }
    go(v,idx+1);
    v.push_back(idx);
    go(v,idx+1);
}

int solution(vector<vector<string>> relation) {
    ::relation=relation;
    go({},0);
    
    sort(q.begin(),q.end());
    q.erase(unique(q.begin(),q.end()),q.end());
    for(int i=0;i<q.size();i++){
        for(int j=i+1;j<q.size();j++){
            if((q[i]&q[j])==q[i]){
                q.erase(q.begin()+j);
                j--;
            }
        }
    }
    return q.size();
}