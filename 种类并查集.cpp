#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
using namespace std;
#define mod 1000000007
typedef long long ll;
const int max_n=5e4+10;//poj1182
int par[max_n],ran[max_n];
void init(int n){
	for(int i=1;i<=n;++i){
		par[i]=i;
        ran[i]=0;
	}
}
int find(int x){
	if(par[x]==x){
		return x;
	}else{
		int px=find(par[x]);
        ran[x]=(ran[par[x]]+ran[x])%3;//父亲到根的距离加上儿子到父亲的距离
		par[x]=px;
	}
	return par[x];
}
int main(){
    int n,k;
    int op,x,y;
    scanf("%d%d",&n,&k);
    init(n);
    int ans=0;
    for(int i=0;i<k;++i){
        scanf("%d%d%d",&op,&x,&y);
        if(x<1||x>n||y<1||y>n){
            ans++;
            continue;
        }
        int fx=find(x);
        int fy=find(y); 
        if(op==1){
            if(fx==fy&&ran[x]!=ran[y]){
                ans++;
                continue;
            }
            par[fx]=fy;
            ran[fx]=(ran[y]-ran[x]+3)%3;
        }else{
            //cout<<ran[x]<<" "<<ran[y]<<endl;
            if((fx==fy&&(ran[y]-ran[x]+3)%3!=1)||x==y){
                ans++;
                continue;
            }
            par[fx]=fy;
            ran[fx]=(ran[y]-ran[x]+2)%3;
        }
        //cout<<i<<endl;
    }
    printf("%d\n",ans);
    return 0;
}
