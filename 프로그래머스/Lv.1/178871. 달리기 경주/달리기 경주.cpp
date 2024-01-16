#include <string>
#include <vector>
#include <map>
using namespace std;

map<string, int> pos;

vector<string> solution(vector<string> players, vector<string> callings) {
    for(int i=0;i<players.size();i++){
        pos[players[i]]=i;
    }
    for(string& call:callings){
        int position = pos[call];
        string p1 = players[position]; //now
        string p2 = players[position-1];
        
        swap(pos[p1], pos[p2]);
        swap(players[position], players[position-1]);
    }
    
    return players;
}