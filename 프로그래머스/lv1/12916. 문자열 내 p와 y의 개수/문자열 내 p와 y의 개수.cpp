#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pc = 0, yc = 0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='p'||s[i]=='P')pc++;
        if(s[i]=='y'||s[i]=='Y')yc++;
    }

    return pc == yc;
}