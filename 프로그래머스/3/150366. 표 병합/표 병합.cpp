#include <string>
#include <vector>
#include <sstream>
#include <queue>
using namespace std;
int p[3000];
string map[3000];

int Find(int x){
    if (p[x]==x){
        return x;
    }
    return p[x]=Find(p[x]);
}
void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(map[a]==""&&map[b]!=""){
        p[a]=b;
    }else{
        p[b]=a;
    }
}
vector<string> parse(string s){
    stringstream ss(s);
    vector<string> v;
    string temp;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    return v;
}

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(int i=0;i<3000;i++){
        p[i]=i;
    }
    for(string command:commands){
        vector<string> v=parse(command);
        if(v[0]=="UPDATE"){
            if(v.size()==4){
                int r=stoi(v[1]),c=stoi(v[2]);
                int parent=Find(r*50+c);
                map[parent]=v[3];
            }else{
                for(int i=0;i<3000;i++){
                    int parent=Find(i);
                    if(map[parent]==v[1]){
                        map[parent]=v[2];
                    }
                }
            }
        }else if(v[0]=="MERGE"){
            if(Find(stoi(v[1])*50+stoi(v[2]))==Find(stoi(v[3])*50+stoi(v[4]))){
                continue;
            }
            int r=stoi(v[1]),c=stoi(v[2]);
            int parent=Find(r*50+c);
            Union(parent,stoi(v[3])*50+stoi(v[4]));
        }else if(v[0]=="UNMERGE"){
            int r=stoi(v[1]),c=stoi(v[2]);
            int parent=Find(r*50+c);
            string value=map[parent];
            queue<int> q;
            for(int i=0;i<3000;i++){
                if(parent==Find(i)){
                    q.push(i);
                    map[i]="";
                }
            }
            map[r*50+c]=value;
            while(!q.empty()){
                p[q.front()]=q.front();
                q.pop();
            }
        }else if(v[0]=="PRINT"){
            int r=stoi(v[1]),c=stoi(v[2]);
            int parent=Find(r*50+c);
            if(map[parent]==""){
                answer.push_back("EMPTY");
            }else{
                answer.push_back(map[parent]);
            }
        }
    }
    
    return answer;
}