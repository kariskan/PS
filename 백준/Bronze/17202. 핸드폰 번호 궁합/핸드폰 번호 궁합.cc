#include <iostream>
using namespace std;

int main() {
    string s1, s2;
    cin>>s1>>s2;
    
    string t = "";
    for(int i=0;i<s1.length();i++){
        t += s1[i];
        t += s2[i];
    }
    
    while(t.length() != 2) {
        string temp = "";
        for(int i=0;i<t.length() - 1;i++){
            temp += (((t[i]-'0') + (t[i+1]-'0'))%10+'0');
        }
        t = temp;
    }
    cout << t;
}
