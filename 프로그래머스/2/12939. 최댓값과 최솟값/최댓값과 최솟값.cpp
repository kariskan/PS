#include <string>
#include <vector>
#include <sstream>
#include <climits>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    long long mi=LLONG_MAX,ma=LLONG_MIN;
    for(int i=0;i<v.size();i++){
        mi=min(mi,stoll(v[i]));
        ma=max(ma,stoll(v[i]));
    }
    return to_string(mi)+" "+to_string(ma);
}