#include <string>
#include <vector>
#include <sstream>
using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    int mi=2e9,ma=-2e9;
    for(int i=0;i<v.size();i++){
        mi=min(mi,stoi(v[i]));
        ma=max(ma,stoi(v[i]));
    }
    return to_string(mi)+" "+to_string(ma);
}