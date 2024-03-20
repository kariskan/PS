#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

string go(string s){
    stack<char> st;
    int cnt=0;
    for(int i=0;i<s.length();i++){
        st.push(s[i]);
        if(st.size()>=3){
            char c1=st.top();
            st.pop();
            char c2=st.top();
            st.pop();
            char c3=st.top();
            st.pop();
            
            if(c1=='0'&&c2=='1'&&c3=='1'){
                cnt++;
                continue;
            }
            st.push(c3);
            st.push(c2);
            st.push(c1);
        }
    }
    string res="";
    while(!st.empty()){
        res+=st.top();
        st.pop();
    }
    reverse(res.begin(),res.end());
    int idx=0;
    for(int i=0;i<(int)res.length();i++){
        if(i<res.length()-2&&res[i]=='1'&&res[i+1]=='1'&&res[i+2]=='1'){
            idx=i;
            break;
        }
        if(res[i]=='0'){
            idx=i+1;
        }
    }
    string dup="";
    for(int i=0;i<cnt;i++){
        dup+="110";
    }
    return res.substr(0,idx)+dup+res.substr(idx);
}

vector<string> solution(vector<string> s) {
    vector<string> answer;
    for(int i=0;i<s.size();i++){
        answer.push_back(go(s[i]));
    }
    return answer;
}