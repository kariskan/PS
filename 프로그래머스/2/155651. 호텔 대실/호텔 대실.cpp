#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<string>> book_time) {
    vector<pair<int, int>> book;
    for(int i=0;i<book_time.size();i++){
        int start=stoi(book_time[i][0].substr(0,2))*60+stoi(book_time[i][0].substr(3));
        int end=stoi(book_time[i][1].substr(0,2))*60+stoi(book_time[i][1].substr(3))+10;
        book.push_back({start,end});
    }
    sort(book.begin(), book.end());
    vector<int> reser;
    for(int i=0;i<book.size();i++){
        if(reser.empty()){
            reser.push_back(i);
            continue;
        }
        bool flag=false;
        for(int j=0;j<reser.size();j++){
            if(book[reser[j]].second<=book[i].first){
                book[reser[j]]=book[i];
                flag=true;
                break;
            }
        }
        if(!flag){
            reser.push_back(i);
        }
    }
    return reser.size();
}