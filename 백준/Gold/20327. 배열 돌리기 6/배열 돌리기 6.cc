#include <iostream>
using namespace std;

int map[129][129];
int n,ro;

void one(int l) {
    int temparr[129][129] = {0,};
    for(int i=1;i<=(1<<n);i+=l){
        for(int j=1;j<=(1<<n);j+=l){
            for(int i1=1;i1<=l;i1++){
                for(int j1=1;j1<=l;j1++){
                    temparr[i1][j1] = map[i1+i-1][j1+j-1];
                }
            }
            for(int i1=1;i1<=l;i1++){
                for(int j1=1;j1<=l;j1++){
                    map[i1+i-1][j1+j-1] = temparr[l-i1+1][j1];
                }
            }
        }
    }
}

void two(int l) {
    int temparr[129][129] = {0,};
    for(int i=1;i<=(1<<n);i+=l){
        for(int j=1;j<=(1<<n);j+=l){
            for(int i1=1;i1<=l;i1++){
                for(int j1=1;j1<=l;j1++){
                    temparr[i1][j1] = map[i1+i-1][j1+j-1];
                }
            }
            for(int i1=1;i1<=l;i1++){
                for(int j1=1;j1<=l;j1++){
                    map[i1+i-1][j1+j-1] = temparr[i1][l-j1+1];
                }
            }
        }
    }
}

void three(int l) {
    int temparr[129][129] = {0,};
    for(int i=1;i<=(1<<n);i+=l){
        for(int j=1;j<=(1<<n);j+=l){
            for(int i1=1;i1<=l;i1++){
                for(int j1=1;j1<=l;j1++){
                    temparr[i1][j1] = map[i1+i-1][j1+j-1];
                }
            }
            for(int i1=1;i1<=l;i1++){
                for(int j1=1;j1<=l;j1++){
                    map[i1+i-1][j1+j-1] = temparr[l-j1+1][i1];
                }
            }
        }
    }
}

void four(int l) {
    int temparr[129][129] = {0,};
    for(int i=1;i<=(1<<n);i+=l){
        for(int j=1;j<=(1<<n);j+=l){
            for(int i1=1;i1<=l;i1++){
                for(int j1=1;j1<=l;j1++){
                    temparr[i1][j1] = map[i1+i-1][j1+j-1];
                }
            }
            for(int i1=1;i1<=l;i1++){
                for(int j1=1;j1<=l;j1++){
                    map[i1+i-1][j1+j-1] = temparr[j1][l-i1+1];
                }
            }
        }
    }
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin>>n>>ro;
    
    for(int i=1;i<=(1<<n);i++){
        for(int j=1;j<=(1<<n);j++){
            cin>>map[i][j];
        }
    }
    
    for(int c=0;c<ro;c++){
        int k,l;
        cin>>k>>l;
        if(k==1){
            one(1<<l);
        }
        else if(k==2) {
            two(1<<l);
        }
        else if(k==3){
            three(1<<l);
        }
        else if(k==4) {
            four(1<<l);
        }
        else if(k==5){
            one(1<<n);
            one(1<<l);
        }
        else if(k==6) {
            two(1<<n);
            two(1<<l);
        }
        else if(k==7){
            three(1<<n);
            four(1<<l);
        }
        else{
            four(1<<n);
            three(1<<l);
        }
    }
    
    for(int i=1;i<=(1<<n);i++){
        for(int j=1;j<=(1<<n);j++){
            cout<<map[i][j]<<' ';
        }
        cout<<'\n';
    }
    cout<<'\n';
}
