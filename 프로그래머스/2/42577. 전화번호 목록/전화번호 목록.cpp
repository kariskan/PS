#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
map<string,int> ma;
bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    for(int j=0;j<phone_book.size();j++){
        string phone=phone_book[j];
        string s="";
        for(int i=0;i<phone.length();i++){
            s+=phone[i];
            ma[s]=j;
        }
    }
    for(int i=0;i<phone_book.size();i++){
        if(ma.find(phone_book[i])!=ma.end()&&ma[phone_book[i]]!=i){
            return false;
        }
    }
    return true;
}