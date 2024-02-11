#include <string>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
vector<string> ban,user;
int answer=0;
set<string> se;
bool check2(string banned,string origin){
    for(int i=0;i<banned.length();i++){
        if(banned[i]=='*'){
            continue;
        }
        if(banned[i]!=origin[i]){
            return false;
        }
    }
    return true;
}
bool check(vector<string> selected){
    for(int i=0;i<selected.size();i++){
        if(!check2(ban[i],selected[i])){
            return false;
        }
    }
    sort(selected.begin(),selected.end());
    string res="";
    for(int i=0;i<selected.size();i++){
        res+=selected[i];
    }
    if(se.find(res)!=se.end()){
        return false;
    }
    se.insert(res);
    return true;
}
int vis[8];
void go(vector<string> selected, int idx){
    if(idx>=user.size()||selected.size()==ban.size()){
        if(check(selected)){
            answer++;
        }
        return;
    }
    for(int i=0;i<user.size();i++){
        if(user[i].length()==ban[idx].length()&&!vis[i]){
            selected.push_back(user[i]);
            vis[i]=1;
            go(selected,idx+1);
            selected.pop_back();
            vis[i]=0;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    ban=banned_id;
    user=user_id;
    go({},0);
    return answer;
}