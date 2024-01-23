#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;
vector<vector<int>> parse(string s){
    s=s.substr(1,s.length()-2);

    string tt="";
    vector<string> v;
    for(int i=0;i<s.length();i++){
        if(s[i]=='}'){
            tt+=s[i];
            v.push_back(tt);
            tt="";
            i++;
            continue;
        }
        tt+=s[i];
    }
    vector<vector<int>> res;
    string temp;
    for(int i=0;i<v.size();i++){
        v[i]=v[i].substr(1,v[i].length()-2);
        stringstream ss(v[i]);
        vector<int> t;
        while(getline(ss,temp,',')){
            t.push_back(stoi(temp));
        }
        res.push_back(t);
    }
    return res;
}

bool compare(vector<int>&v1,vector<int>&v2){
    return v1.size()<v2.size();
}

vector<int> solution(string s) {
    vector<int> answer;
    vector<vector<int>> res=parse(s);
    sort(res.begin(),res.end(),compare);
    int vis[100001]={0,};
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            if(!vis[res[i][j]]){
                vis[res[i][j]]=1;
                answer.push_back(res[i][j]);
            }
        }
    }
    return answer;
}