#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string go(string s){
    if(s.length()<=3){
        return s;
    }
    stack<char> q;
    int cnt=0;
    for(int i=0;i<s.length();i++){
        q.push(s[i]);
        if(q.size()>=3){
            char a1=q.top();
            q.pop();
            char a2=q.top();
            q.pop();
            char a3=q.top();
            q.pop();

            if(a1=='0'&&a2=='1'&&a3=='1'){
                cnt++;
            }else {
                q.push(a3);
                q.push(a2);
                q.push(a1);
            }
        }
    }
    string res="";
    while(!q.empty()){
        res+=q.top();
        q.pop();
    }
    reverse(res.begin(),res.end());
    string p="";
    for(int i=0;i<cnt;i++){
        p+="110";
    }
    if(res.empty()){
        return p;
    }
    if(res.length()==1){
        if(res[0]=='0'){
            return res+p;
        }else{
            return p+res;
        }
    }else{
        for(int i=0;i<res.length()-1;i++){
            if(res.substr(i,2)=="11"){
                return res.substr(0,i)+p+res.substr(i);
            }
        }
        if(res[res.length()-1]=='1'){
            return res.substr(0,res.length()-1)+p+res.substr(res.length()-1);
        }
        return res+p;
    }
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(int i=0;i<s.size();i++){
        answer.push_back(go(s[i]));
    }
    return answer;
}