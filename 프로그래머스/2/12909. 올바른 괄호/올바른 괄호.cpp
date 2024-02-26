#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(s[i]==')'){
            if(st.empty()||st.top()!='('){
                return false;
            }
            st.pop();
            continue;
        }
        st.push(s[i]);
    }
    return st.empty();
}