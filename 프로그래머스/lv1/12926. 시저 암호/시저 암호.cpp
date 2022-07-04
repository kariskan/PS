#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i=0;i<s.length();i++){
        if(s[i] == ' ')continue;
        if(s[i]>='a'&&s[i]<='z'){
            for(int j=0;j<n;j++){
                if(s[i]=='z')s[i]='a';
                else s[i]++;
            }
        }
        else {
            for(int j=0;j<n;j++){
                if(s[i]=='Z')s[i]='A';
                else s[i]++;
            }
        }
    }
    return s;
}