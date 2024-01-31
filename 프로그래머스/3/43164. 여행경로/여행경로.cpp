#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
using namespace std;
vector<vector<string>> tickets;
string answer;
int vis[10000],n;
void go(string route){
    if((int)route.length()/3==tickets.size()+1){
        if(answer.empty()||answer>route){
            answer=route;
        }
        return;
    }
    for(int i=0;i<tickets.size();i++){
        if(tickets[i][0]==route.substr(route.size()-3)&&!vis[i]){
            vis[i]=1;
            go(route+tickets[i][1]);
            vis[i]=0;
        }
    }
}
vector<string> solution(vector<vector<string>> tickets) {
    n=tickets.size();
    ::tickets=tickets;
    go("ICN");
    vector<string> ans;
    for(int i=0;i<answer.length();i+=3){
        ans.push_back(answer.substr(i,3));
    }
    return ans;
}