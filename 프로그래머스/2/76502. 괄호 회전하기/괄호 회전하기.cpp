#include <string>
#include <vector>
#include <stack>
using namespace std;

bool isValid(string s){
    stack<char> st;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
        if(s[i]==']'||s[i]==')'||s[i]=='}'){
            st.pop();
            if(st.empty()||(s[i]==']'&&st.top()!='[')||(s[i]==')'&&st.top()!='(')||s[i]=='}'&&st.top()!='{'){
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int solution(string s) {
    int answer = 0;
    for(int i=0;i<s.length();i++){
        string newS=s.substr(i)+s.substr(0,i);
        if(isValid(newS)){
            answer++;
        }
    }
    return answer;
}