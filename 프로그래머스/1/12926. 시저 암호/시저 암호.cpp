#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    for(int i=0;i<s.length();i++){
        if(s[i]==' '){
            continue;
        }
        if(s[i]>='A'&&s[i]<='Z'){
            s[i] = (s[i]-'A'+n)%26+'A';
        }else{
            s[i] = (s[i]-'a'+n)%26+'a';
        }
    }
    return s;
}