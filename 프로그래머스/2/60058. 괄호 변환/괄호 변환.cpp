#include <string>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
pair<string,string> balance(string p){
    int lc=0,rc=0;
    for(int i=0;i<p.length();i++){
        if(p[i]==')'){
            rc++;
        }else{
            lc++;
        }
        if(lc==rc){
            return {p.substr(0,lc+rc),p.substr(lc+rc)};
        }
    }
}
bool valid(string p){
    stack<char> st;
    for(int i=0;i<p.length();i++){
        if(p[i]==')'){
            if(st.empty()||st.top()!='('){
                return false;
            }
            st.pop();
            continue;
        }
        st.push(p[i]);
    }
    return st.empty();
}
string go(string p){
    if(p.empty()){
        return p;
    }
    pair<string,string> b=balance(p);
    if(valid(b.first)){
        return b.first+go(b.second);
    }
    string temp="("+go(b.second)+")";
    b.first.pop_back();
    b.first.erase(b.first.begin());
    for(int i=0;i<b.first.length();i++){
        if(b.first[i]==')'){
            b.first[i]='(';
        }else{
            b.first[i]=')';
        }
    }
    return temp+b.first;
}
string solution(string p) {
    return go(p);
}