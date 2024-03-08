#include <string>
#include <vector>
#include <stack>
using namespace std;

int left[1000000],right[1000000],flag[1000000];
stack<int> st;
string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    for(int i=0;i<n;i++){
        left[i]=i-1;
        right[i]=i+1;
    }
    right[n-1]=-1;
    
    for(string c:cmd){
        if(c[0]=='U'){
            int x=stoi(c.substr(2));
            while(x--){
                k=left[k];
            }
        }else if(c[0]=='D'){
            int x=stoi(c.substr(2));
            while(x--){
                k=right[k];
            }
        }else if(c[0]=='C'){
            flag[k]=1;
            st.push(k);
            if(-1!=left[k]){
                right[left[k]]=right[k];
            }
            if(-1!=right[k]){
                left[right[k]]=left[k];
            }
            if(-1==right[k]){
                k=left[k];
            }else{
                k=right[k];
            }
        }else{
            int recent=st.top();
            st.pop();
            flag[recent]=0;
            if(-1!=left[recent]){
                right[left[recent]]=recent;   
            }
            if(-1!=right[recent]){
                left[right[recent]]=recent;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(flag[i]==0){
            answer+="O";
        }else{
            answer+="X";
        }
    }
    return answer;
}