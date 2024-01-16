#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

map<pair<string, string>, int> record;
map<string, int> inGift, outGift;
map<string, int> nxt;

pair<string, string> parse(string s) {
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss, temp, ' ')) {
        v.push_back(temp);
    }
    return {v[0], v[1]};
}

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    for(string gift:gifts) {
        auto i = parse(gift);
        inGift[i.second]++;
        outGift[i.first]++;
        record[{i.first,i.second}]++;
    }
    
    for(int i=0;i<friends.size();i++) {
        for(int j=i+1;j<friends.size();j++) {
            string f1 = friends[i];
            string f2 = friends[j];
            if (f1==f2){
                continue;
            }
            if (record.find({f1,f2})!=record.end() || record.find({f2,f1})!=record.end()){
                if (record.find({f2,f1})==record.end()) {
                    nxt[f1]++;
                    continue;
                } else if (record.find({f1,f2})==record.end()) {
                    nxt[f2]++;
                    continue;
                } else if (record[{f1,f2}]>record[{f2,f1}]) {
                    nxt[f1]++;
                    continue;
                } else if(record[{f1,f2}]<record[{f2,f1}]) {
                    nxt[f2]++;
                    continue;
                }
            }
            int f1GiftExp = outGift[f1]-inGift[f1];
            int f2GiftExp = outGift[f2]-inGift[f2];
            if(f1GiftExp>f2GiftExp){
                nxt[f1]++;
            }else if(f1GiftExp<f2GiftExp) {
                nxt[f2]++;
            }
            if (f1GiftExp==f2GiftExp){
                continue;
            }
        }
    }
    
    for(auto&i:nxt){
        printf("%s %d\n", i.first.c_str(), i.second);
        answer=max(answer,i.second);
    }
    return answer;
}