#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string toBinary(int n){
    string res="";
    while(n){
        res+=(n%2+'0');
        n/=2;
    }
    reverse(res.begin(),res.end());
    return res;
}
int solution(int n) {
    int answer = 0;
    string a=toBinary(n);
    int cnt=0;
    for(int i=0;i<a.length();i++){
        if(a[i]=='1'){
            cnt++;
        }
    }
    while(++n){
        string temp=toBinary(n);
        int tempCnt=0;
        for(int i=0;i<temp.length();i++){
            if(temp[i]=='1'){
                tempCnt++;
            }
        }
        if(cnt==tempCnt){
            return n;
        }
    }
    return answer;
}