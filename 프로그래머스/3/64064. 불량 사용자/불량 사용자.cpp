#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> user,ban;
int answer;

bool isValid(vector<string> selected){
    int n=selected.size();
    
    for(int i=0;i<n;i++){
        if(selected[i].length()!=ban[i].length()){
            return false;
        }
        int len=selected[i].length();
        for(int j=0;j<len;j++){
            if(ban[i][j]=='*'){
                continue;
            }
            if(selected[i][j]!=ban[i][j]){
                return false;
            }
        }
    }
    return true;
}

void dfs(vector<string> selected, int idx){
    if(selected.size()==ban.size()){
        sort(selected.begin(),selected.end());
        do{
            if(isValid(selected)){
                answer++;
                break;
            }
        }while(next_permutation(selected.begin(),selected.end()));
        return;
    }
    if(idx>=user.size()){
        return;
    }
    dfs(selected,idx+1);
    selected.push_back(user[idx]);
    dfs(selected,idx+1);
}

int solution(vector<string> user_id, vector<string> banned_id) {
    user=user_id;
    ban=banned_id;
    dfs({},0);
    return answer;
}