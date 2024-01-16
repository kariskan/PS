#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    for(int i=0;i<s.length();i++){
        for(int j=0;j<index;j++){
            s[i]++;
            if(s[i]>'z'){
                s[i]='a';
            }
            if(skip.find(s[i])!=string::npos){
                j--;
            }
        }
    }
    
    return s;
}