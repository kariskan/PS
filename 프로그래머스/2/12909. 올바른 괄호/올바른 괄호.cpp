#include<string>
#include <iostream>
#include <stack>
using namespace std;

bool solution(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
        if(s[i]==')'){
            st.pop();
            if(st.empty()||st.top()!='('){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}