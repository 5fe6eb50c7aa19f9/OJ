#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct node{
    int a,b;
    string act;
};
bool re[1001][1001];
queue<node> bfs;
int main(){
    int i,j,a,b,n;
    while(scanf("%d %d %d",&a,&b,&n)==3){
        while(!bfs.empty())bfs.pop();
        for(i=0;i<1001;i++){
            for(j=0;j<1001;j++)re[i][j]=1;
        }
        node tmp;
        tmp.a=0,tmp.b=0,tmp.act="";
        bfs.push(tmp);
        while(bfs.front().b!=n){
            if(!re[bfs.front().a][bfs.front().b]){
                bfs.pop();
                continue;
            }
            tmp.a=a;
            tmp.b=bfs.front().b;
            tmp.act=bfs.front().act+"1";
            bfs.push(tmp);

            tmp.a=bfs.front().a;
            tmp.b=b;
            tmp.act=bfs.front().act+"2";
            bfs.push(tmp);

            tmp.a=0;
            tmp.b=bfs.front().b;
            tmp.act=bfs.front().act+"3";
            bfs.push(tmp);

            tmp.a=bfs.front().a;
            tmp.b=0;
            tmp.act=bfs.front().act+"4";
            bfs.push(tmp);

            if(bfs.front().a>=b-bfs.front().b){
                tmp.a=bfs.front().a-b+bfs.front().b;
                tmp.b=b;
            }else{
                tmp.a=0;
                tmp.b=bfs.front().a+bfs.front().b;
            }
            tmp.act=bfs.front().act+"5";
            bfs.push(tmp);

            if(bfs.front().b>=a-bfs.front().a){
                tmp.a=a;
                tmp.b=bfs.front().b-a+bfs.front().a;
            }else{
                tmp.a=bfs.front().a+bfs.front().b;
                tmp.b=0;
            }
            tmp.act=bfs.front().act+"6";
            bfs.push(tmp);

            re[bfs.front().a][bfs.front().b]=0;
            bfs.pop();
        }
        for(i=0;i<bfs.front().act.size();i++){
            switch(bfs.front().act[i]){
                case '1':
                    printf("fill A\n");
                    break;
                case '2':
                    printf("fill B\n");
                    break;
                case '3':
                    printf("empty A\n");
                    break;
                case '4':
                    printf("empty B\n");
                    break;
                case '5':
                    printf("pour A B\n");
                    break;
                case '6':
                    printf("pour B A\n");
                    break;
            }
        }
        printf("success\n");
    }
}
