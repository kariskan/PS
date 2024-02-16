#include <string>
#include <vector>

using namespace std;

double getRad(int h,int m,int s,int type){
    if(type==0){ //시침
        return (h%12)*30+(double)m/2+(double)s/120;
    }else if(type==1){ //분침
        return m*6+(double)s/10;
    }else{ //초침
        return s*6;
    }
}
int getTime(int h,int m,int s){
    return h*3600+m*60+s;
}
int solution(int h1, int m1, int s1, int h2, int m2, int s2) {
    int answer = 0;
    double preH=getRad(h1,m1,s1,0);
    double preM=getRad(h1,m1,s1,1);
    double preS=getRad(h1,m1,s1,2);

    int start=getTime(h1,m1,s1);
    int end=getTime(h2,m2,s2);

    if(start==0||start==43200){
        answer++;
    }

    for(int i=start+1;i<=end;i++){
        double nowH=getRad(i/3600,(i%3600)/60,i%60,0);
        double nowM=getRad(i/3600,(i%3600)/60,i%60,1);
        double nowS=getRad(i/3600,(i%3600)/60,i%60,2);

        if((preS<preH&&nowS>=nowH)||(preS==354&&preH>354)){
            answer++;
        }
        if((preS<preM&&nowS>=nowM)||(preS==354&&preM>354)){
            answer++;
        }
        if(nowH==nowM){
            answer--;
        }

        preH=nowH;
        preM=nowM;
        preS=nowS;
    }
    return answer;
}

int main(){
    solution(11,59,30,12,0,0);
}