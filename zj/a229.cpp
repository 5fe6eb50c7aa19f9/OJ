#include <iostream>
using namespace std;
#include <bits/stdc++.h>

int parM;
void test(string par,int lefT,int righT){
    if(righT==parM){
        printf("%s\n",par.c_str());
        return;
    }else if(lefT==parM){
        test(par+")",lefT,righT+1);
    }else if(lefT>righT){
        test(par+"(",lefT+1,righT);
        test(par+")",lefT,righT+1);
    }else{
        test(par+"(",lefT+1,righT);
    }
}
int main()
{
    while(scanf("%d",&parM)==1){
        string par="(";
        test(par,1,0);
    }
}

