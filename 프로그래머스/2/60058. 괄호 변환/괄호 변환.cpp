#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
        if(s[i]==')'){
            st.pop();
            if(st.size()<1||st.top()!='('){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

string go(string s){
    if(s.empty()){
        return "";
    }
    int leftCnt=0,rightCnt=0;
    string u="",v="";
    for(int i=0;i<s.length();i++){
        u+=s[i];
        if(s[i]=='('){
            leftCnt++;
        }else{
            rightCnt++;
        }
        if(leftCnt==rightCnt){
            if(i<s.length()-1){
                v=s.substr(i+1);
            }
            break;
        }
    }
    if(isValid(u)){
        return u+go(v);
    }
    string t="("+go(v)+")";
    u.erase(u.begin());
    u.pop_back();
    for(int i=0;i<u.length();i++){
        if(u[i]=='('){
            u[i]=')';
        }else{
            u[i]='(';
        }
    }
    return t+u;
}

string solution(string p) {
    return go(p);
}