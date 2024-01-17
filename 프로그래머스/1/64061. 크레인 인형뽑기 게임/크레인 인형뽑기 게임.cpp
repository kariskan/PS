#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> v;
    
    for(int move:moves){
        for(int i=0;i<board.size();i++){
            if(board[i][move-1]!=0){
                v.push_back(board[i][move-1]);
                board[i][move-1]=0;
                if(v.size()>=2&&v[v.size()-1]==v[v.size()-2]){
                    v.pop_back();
                    v.pop_back();
                    answer+=2;
                }
                break;
            }
        }
    }
    
    return answer;
}