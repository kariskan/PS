#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string toBinary(long long n){
    string res="";
    while(n){
        res+=(n%2+'0');
        n/=2;
    }
    int cnt=(int)res.length();
    int len=0;
    for(long long i=1;;i*=2){
        if(len+i>=cnt){
            for(int j=0;j<len+i-cnt;j++){
                res+='0';
            }
            reverse(res.begin(),res.end());
            return res;
        }
        len+=i;
    }
}

bool isValid(string s,int ps,int pe,int start,int end){
    if(start>end){
        return true;
    }
    int pm=(ps+pe)/2;
    int m=(start+end)/2;
    if(s[pm]=='0'&&s[m]=='1'){
        return false;
    }
    return isValid(s,start,end,start,m-1)&&isValid(s,start,end,m+1,end);
}

vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    
    for(long long number:numbers){
        string s=toBinary(number);
        answer.push_back(isValid(s,0,s.length()-1,0,s.length()-1));
    }
    
    return answer;
}