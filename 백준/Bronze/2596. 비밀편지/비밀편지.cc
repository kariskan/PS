#include <iostream>
using namespace std;

string t[8] = {"000000","001111","010011","011100","100110","101001","110101","111010"};

int main() {
    int n;
    string s;
    cin>>n>>s;
    int idx = 1;
    string ans = "";
    for(int i=0;i<s.length();i+=6){
        string temp = s.substr(i, 6);
        int flag = -1;
        for(int j=0;j<8;j++){
            int diff = 0;
            for(int k=0;k<6;k++){
                if(temp[k] != t[j][k]) {
                    diff++;
                }
            }
            if(diff <= 1) {
                flag = j;
                break;
            }
        }
        if(flag==-1){
            cout<<idx;
            return 0;
        }
        ans += flag + 'A';
        idx++;
    }
    
    cout << ans;
}
