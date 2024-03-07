#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
using namespace std;

vector<string> t[4]={
    {"-","cpp","java","python"},
    {"-","backend","frontend"},
    {"-","junior","senior"},
    {"-","chicken","pizza"}
};
vector<vector<string>> infos;
map<string,vector<int>> ma;

vector<string> parse(string s){
    vector<string> v;
    string temp;
    stringstream ss(s);
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    return v;
}
pair<string,int> parse2(string s){
    string v="";
    string temp;
    stringstream ss(s);
    while(getline(ss,temp,' ')){
        if(temp=="and"){
            continue;
        }
        if(temp[0]>='0'&&temp[0]<='9'){
            return {v,stoi(temp)};
        }
        v+=temp;
    }
}
string join(vector<string> k){
    string res="";
    for(int i=0;i<k.size();i++){
        res+=k[i];
    }
    return res;
}
void go(int idx,vector<string> now){
    if(idx>=4){
        for(int i=0;i<infos.size();i++){
            int flag=true;
            for(int j=0;j<now.size();j++){
                if(now[j]=="-"){
                    continue;
                }
                if(now[j]!=infos[i][j]){
                    flag=false;
                    break;
                }
            }
            if(flag){
                ma[join(now)].push_back(stoi(infos[i].back()));
            }
        }
        return;
    }
    for(int i=0;i<t[idx].size();i++){
        now.push_back(t[idx][i]);
        go(idx+1,now);
        now.pop_back();
    }
}
vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    for(int i=0;i<info.size();i++){
        infos.push_back(parse(info[i]));
    }
    go(0,{});
    for(auto&i:ma){
        sort(i.second.begin(),i.second.end());
    }
    for(string q:query){
        pair<string,int> p=parse2(q);
        int siz=ma[p.first].size();
        int left=0,right=siz-1;
        int temp=-1;
        while(left<=right){
            int mid=(left+right)/2;
            
            if(ma[p.first][mid]>=p.second){
                temp=mid;
                right=mid-1;
            }else{
                left=mid+1;
            }
        }
        if(temp==-1){
            answer.push_back(0);
        }else{
            answer.push_back(siz-temp);
        }
    }
    return answer;
}