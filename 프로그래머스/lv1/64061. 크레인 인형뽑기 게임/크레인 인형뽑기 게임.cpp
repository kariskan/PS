#include <string>
#include <vector>
#include <stack>
using namespace std;
stack<int> st;
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    for (int m : moves) {
        m--;
        int bSize = board[m].size();
        for (int i = 0; i < bSize; i++) {
            if (board[i][m]) {
                if (st.empty() || st.top() != board[i][m]) {
                    st.push(board[i][m]);
                }
                else {
                    st.pop();
                    answer += 2;
                }
                board[i][m] = 0;
                break;
            }
        }
    }
    return answer;
}