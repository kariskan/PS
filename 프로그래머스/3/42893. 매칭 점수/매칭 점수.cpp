#include <string>
#include <vector>
#include <map>
using namespace std;

int baseScore[20],linkCnt[20];
vector<int> inDegree[20];
map<string,int> pageIndex;
string toLowerString(string s){
    string res="";
    for(int i=0;i<s.length();i++){
        if(s[i]>='A'&&s[i]<='Z'){
            res+=s[i]-'A'+'a';
        }else{
            res+=s[i];
        }
    }
    return res;
}

int solution(string word, vector<string> pages) {
    int n=pages.size(),answer=0;
    double ma=0;

    word=toLowerString(word);
    string pageUrlMeta="<meta property=\"og:url\" content=\"";
    string outUrlMeta="<a href=\"";
    for(int i=0;i<pages.size();i++){
        for(int j=0;j<=pages[i].length()-pageUrlMeta.length();j++){
            if(pages[i].substr(j,pageUrlMeta.length())==pageUrlMeta){
                int idx=j+pageUrlMeta.length();
                while(idx<pages[i].length()&&pages[i][idx]!='"'){
                    idx++;
                }
                string pageUrl=pages[i].substr(j+pageUrlMeta.length(),idx-j-pageUrlMeta.length());
                pageIndex[pageUrl]=i;
                break;
            }
        }
    }
    for(int i=0;i<pages.size();i++){
        for(int j=0;j<=pages[i].length()-outUrlMeta.length();j++){
            if(pages[i].substr(j,outUrlMeta.length())==outUrlMeta){
                int idx=j+outUrlMeta.length();
                while(idx<pages[i].length()&&pages[i][idx]!='"'){
                    idx++;
                }
                string outUrl=pages[i].substr(j+outUrlMeta.length(),idx-j-outUrlMeta.length());
                linkCnt[i]++;
                if(pageIndex.find(outUrl)!=pageIndex.end()){
                    inDegree[pageIndex[outUrl]].push_back(i);
                }
            }
        }
    }
    for(int i=0;i<pages.size();i++){
        string t="";
        for(int j=0;j<pages[i].length();j++){
            if(!(pages[i][j]>='a'&&pages[i][j]<='z')&&!(pages[i][j]>='A'&&pages[i][j]<='Z')){
                if(toLowerString(t)==word){
                    baseScore[i]++;
                }
                t="";
                continue;
            }
            t+=pages[i][j];
        }
        if(toLowerString(t)==word){
            baseScore[i]++;
        }
    }
    for(int i=0;i<pages.size();i++){
        double linkScore=0;
        for(int j=0;j<inDegree[i].size();j++){
            printf("%d %d %d %lf\n", i,inDegree[i][j],linkCnt[inDegree[i][j]], (double)baseScore[inDegree[i][j]]/linkCnt[inDegree[i][j]]);
            linkScore+=(double)baseScore[inDegree[i][j]]/linkCnt[inDegree[i][j]];
        }
        if(linkScore+baseScore[i]>ma){
            ma=linkScore+baseScore[i];
            answer=i;
        }
    }
    return answer;
}