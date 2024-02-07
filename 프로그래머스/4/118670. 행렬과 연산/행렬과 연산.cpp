#include <string>
#include <vector>
#include <deque>
using namespace std;
vector<vector<int>> solution(vector<vector<int>> rc, vector<string> operations) {
    vector<vector<int>> answer(rc.size());
    int n=rc.size(),m=rc[0].size();

    deque<deque<int>> d(n);
    deque<int> l,r;
    int shiftCnt=0;
    for(int i=0;i<n;i++){
        deque<int> temp;
        for(int j=0;j<m;j++){
            if(j==0){
                l.push_back(rc[i][j]);
            }else if(j==m-1){
                r.push_back(rc[i][j]);
            }else{
                d[i].push_back(rc[i][j]);
            }
        }
    }

    for(string op:operations){
        if(op=="Rotate"){
            d[(n-shiftCnt)%n].push_front(l.front());
            l.pop_front();

            r.push_front(d[(n-shiftCnt)%n].back());
            d[(n-shiftCnt)%n].pop_back();

            d[n-1-shiftCnt].push_back(r.back());
            r.pop_back();

            l.push_back(d[n-1-shiftCnt].front());
            d[n-1-shiftCnt].pop_front();
        }else{
            shiftCnt=(shiftCnt+1)%n;

            l.push_front(l.back());
            l.pop_back();

            r.push_front(r.back());
            r.pop_back();
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(j==0){
                answer[i].push_back(l[i]);
            }else if(j==m-1){
                answer[i].push_back(r[i]);
            }else{
                answer[i].push_back(d[(n-shiftCnt+i)%n][j-1]);
            }
        }
    }
    return answer;
}