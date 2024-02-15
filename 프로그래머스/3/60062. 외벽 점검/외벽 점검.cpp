#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer=-1;
    sort(dist.begin(),dist.end());
    int siz=weak.size();
    for(int i=0;i<siz-1;i++){
        weak.push_back(weak[i]+n);
    }
    do{
        for(int i=0;i<siz;i++){
            int start=weak[i];
            int end=weak[i+siz-1];

            for(int j=0;j<dist.size();j++){
                start+=dist[j];

                if(start>=end){
                    if(answer==-1||answer>j+1){
                        answer=j+1;
                        break;
                    }
                }
                for(int k=i;k<=i+siz-1;k++){
                    if(weak[k]>start){
                        start=weak[k];
                        break;
                    }
                }
            }
        }
    }while(next_permutation(dist.begin(),dist.end()));
    return answer;
}