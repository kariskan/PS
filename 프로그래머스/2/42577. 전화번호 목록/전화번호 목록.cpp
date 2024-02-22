#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
bool compare(string a,string b){
    return a.length()>b.length();
}
bool solution(vector<string> phone) {
    bool answer = true;
    sort(phone.begin(),phone.end(),compare);
    set<string> se;
    for(int i=0;i<phone.size();i++){
        if(se.find(phone[i])!=se.end()){
            return false;
        }
        for(int j=1;j<=phone[i].length();j++){
            se.insert(phone[i].substr(0,j));
        }
    }
    return true;
}