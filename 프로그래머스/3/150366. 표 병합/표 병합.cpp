#include <string>
#include <vector>
#include <sstream>
using namespace std;
vector<string> parse(string c){
    stringstream ss(c);
    string temp;
    vector<string> v;
    while(getline(ss,temp,' ')){
        v.push_back(temp);
    }
    return v;
}
int p[2501],n=50;
string value[2501];
int Find(int x){
    if(x==p[x]){
        return x;
    }
    return p[x]=Find(p[x]);
}
void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a==b){
        return;
    }
    if(value[a]==""&&value[b]!=""){
        p[a]=b;
    }else{
        p[b]=a;
    }
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(int i=1;i<=2500;i++){
        p[i]=i;
    }
    for(string c:commands){
        vector<string> v=parse(c);
        if(v[0]=="UPDATE"&&v.size()==4){
            int parent=Find((stoi(v[1])-1)*50+stoi(v[2]));
            value[parent]=v[3];
        }else if(v[0]=="UPDATE"){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=n;j++){
                    int parent=Find((i-1)*50+j);
                    if(value[parent]==v[1]){
                        value[parent]=v[2];
                    }
                }
            }
        }else if(v[0]=="MERGE"){
            int p1=(stoi(v[1])-1)*50+stoi(v[2]);
            int p2=(stoi(v[3])-1)*50+stoi(v[4]);
            Union(p1,p2);
        }else if(v[0]=="UNMERGE"){
            int pos=(stoi(v[1])-1)*n+stoi(v[2]);
            int parent=Find(pos);
            string preValue=value[parent];
            vector<int> q;
            for(int i=1;i<=50;i++){
                for(int j=1;j<=50;j++){
                    if(Find((i-1)*50+j)==parent){
                        q.push_back((i-1)*50+j);
                    }
                }
            }
            while(!q.empty()){
                int x=q.back();
                p[x]=x;
                value[x]="";
                q.pop_back();
            }
            if(preValue!=""){
                value[pos]=preValue;
            }
        }else{
            string val=value[Find((stoi(v[1])-1)*n+stoi(v[2]))];
            answer.push_back(val==""?"EMPTY":val);
        }
    }
    return answer;
}