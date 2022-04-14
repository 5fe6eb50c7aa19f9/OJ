#include <cstdio>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct sp{
    int i;
    double p;
    bool operator()(sp& a,sp& b){
        return a.p>b.p;
    }
};
double x[200],y[200];
double dist[200];
priority_queue<sp,vector<sp>,sp> heap;
int main(){
    int t=0,n,i,j;
    double tmp;
    while(scanf("%d",&n)&&n){
        for(i=0;i<n;i++){
            scanf("%lf %lf",x+i,y+i);
            dist[i]=-1;
        }
        heap.push(sp{0,0});
        while(!heap.empty()){
            i=heap.top().i;
            tmp=heap.top().p;
            heap.pop();
            if(dist[i]==-1){
                dist[i]=tmp;
                for(j=0;j<n;j++){
                    heap.push(sp{j,max(dist[i],(x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]))});
                }
            }
        }
        printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++t,sqrt(dist[1]));
    }
}
