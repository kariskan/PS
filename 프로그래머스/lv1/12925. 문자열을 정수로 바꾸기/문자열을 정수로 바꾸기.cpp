#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int bu = 1;
    int i = 0;
    if(s[0]=='-'){
        bu = -1;
        i++;
    }
    if(s[0]=='+')i++;
    int num = 0;
    for(;i < s.length();i++){
        num = num * 10 + (s[i]-'0');
    }
    return num*bu;
}