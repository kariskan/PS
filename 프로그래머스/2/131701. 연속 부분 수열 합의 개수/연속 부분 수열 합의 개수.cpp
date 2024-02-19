#include <string>
#include <vector>
#include <set>
using namespace std;
int sum[2002];
set<int> se;
int solution(vector<int> elements) {
    int siz=elements.size();
    for(int i=0;i<siz-1;i++){
        elements.push_back(elements[i]);
    }
    for(int i=1;i<=elements.size();i++){
        sum[i]=sum[i-1]+elements[i-1];
    }
    for(int i=elements.size()/2;i<elements.size();i++){
        for(int j=i-siz;j<i;j++){
            se.insert(sum[i]-sum[j]);
        }
    }
    return se.size();
}