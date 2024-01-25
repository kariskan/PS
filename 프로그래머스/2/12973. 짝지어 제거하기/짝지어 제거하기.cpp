#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;
    for(int i=0;i<s.length();i++){
        if(!st.empty()&&st.top()==s[i]){
            st.pop();
            continue;
        }
        st.push(s[i]);
    }
    return st.empty();
}