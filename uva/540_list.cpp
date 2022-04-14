#include <iostream>
#include <cstdio>
using namespace std;
struct Queue{
    int num;
    Queue* next;
};
Queue tmp[300000];
int used;
int team[1000000];
Queue* qfront[1000];
Queue* qrear[1000];
Queue* pfront;
Queue* prear;
int main(){
    int c=0,t,i,j,k,num;
    char quest[100];
    while(scanf("%d",&t)==1&&t){
        c++;
        used=0;
        printf("Scenario #%d\n",c);
        for(i=0;i<t;i++){
            qfront[i]=qrear[i]=0;
            scanf("%d",&k);
            for(j=0;j<k;j++){
                scanf("%d",&num);
                team[num]=i;
            }
        }
        pfront=prear=0;
        while(scanf("%s",quest)){
            if(quest[0]=='S'){
                break;
            }
            if(quest[0]=='E'){
                scanf("%d",&num);
                if(!qfront[team[num]]){
                    tmp[used].num=team[num];
                    tmp[used].next=0;
                    if(!pfront){
                        pfront=prear=&tmp[used++];
                    }else{
                        prear->next=&tmp[used++];
                        prear=prear->next;
                    }
                    tmp[used].num=num;
                    tmp[used].next=0;
                    qfront[team[num]]=qrear[team[num]]=&tmp[used++];
                }else{
                    tmp[used].num=num;
                    tmp[used].next=0;
                    qrear[team[num]]->next=&tmp[used++];
                    qrear[team[num]]=qrear[team[num]]->next;
                }
            }else{
                num=qfront[pfront->num]->num;
                qfront[pfront->num]=qfront[pfront->num]->next;
                if(!qfront[pfront->num]){
                    pfront=pfront->next;
                }
                printf("%d\n",num);
            }
        }
        printf("\n");
    }
}
