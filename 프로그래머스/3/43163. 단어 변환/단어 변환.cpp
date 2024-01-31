#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;
map<string,int> vis;
map<string,vector<string>> v;
bool valid(string s1, string s2){
    for(int i=1;i<s1.length()-1;i++){
        if(s1.substr(0,i)+s1.substr(i+1)==s2.substr(0,i)+s2.substr(i+1)){
            return true;
        }
    }
    if(s1.substr(1)==s2.substr(1)||s1.substr(0,s1.length()-1)==s2.substr(0,s2.length()-1)){
        return true;
    }
    return false;
}
int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    words.push_back(begin);
    for(int i=0;i<words.size();i++){
        for(int j=0;j<words.size();j++){
            if(i==j){
                continue;
            }
            if(valid(words[i],words[j])){
                v[words[i]].push_back(words[j]);
                v[words[j]].push_back(words[i]);
            }
        }
    }
    queue<string> q;
    q.push(begin);
    vis[begin]=0;
    while(!q.empty()){
        string now=q.front();
        q.pop();
        
        if(now==target){
            return vis[now];
        }
        
        for(auto&i:v[now]){
            if(vis.find(i)==vis.end()){
                vis[i]=vis[now]+1;
                q.push(i);
            }
        }
    }
    return 0;
}