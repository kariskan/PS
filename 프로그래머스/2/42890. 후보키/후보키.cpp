#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<string>> relation;
vector<vector<int>> v;
bool valid(vector<int> now){
    set<string> se;
    for(int i=0;i<relation.size();i++){
        string sum="";
        for(int j=0;j<now.size();j++){
            sum+=relation[i][now[j]];
        }
        if(se.find(sum)!=se.end()){
            return false;
        }
        se.insert(sum);
    }
    v.push_back(now);
    return true;
}
void go(int idx, vector<int> now){
    if(!now.empty()&&valid(now)){
        return;
    }
    if(idx>=relation[0].size()){
        return;
    }
    now.push_back(idx);
    go(idx+1,now);
    now.pop_back();
    go(idx+1,now);
}

bool bit(int i, int j){
    int first=0,second=0;
    for(int k=0;k<v[i].size();k++){
        first += (1<<v[i][k]);
    }
    for(int k=0;k<v[j].size();k++){
        second += (1<<v[j][k]);
    }
    return (first & second) == first;
}

bool compare(vector<int>& v1, vector<int>&v2){
    return v1.size()<v2.size();
}

int solution(vector<vector<string>> relation) {
    ::relation=relation;
    go(0,{});
    sort(v.begin(),v.end(),compare);
    for(int i=0;i<v.size();i++){
        for(int j=i+1;j<v.size();j++){
            if(bit(i,j)){
                v.erase(v.begin()+j);
                j--;
            }
        }
    }
    return v.size();
}