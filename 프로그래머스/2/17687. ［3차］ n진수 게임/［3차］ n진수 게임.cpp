#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string binary(int i,int n){
    if(i==0){
        return "0";
    }
    string res="";
    while(i){
        if(i%n>=10){
            res+=(i%n-10+'A');
        }else{
            res+=(i%n+'0');
        }
        i/=n;
    }
    reverse(res.begin(),res.end());
    return res;
}
string solution(int n, int t, int m, int p) {
    string answer = "";
    int len=p+(t-1)*m;
    string temp="";
    for(int i=0;temp.length()<len;i++){
        temp+=binary(i,n);
    }
    int idx=p-1;
    for(int i=0;i<t;i++){
        answer+=temp[idx];
        idx+=m;
    }
    return answer;
}