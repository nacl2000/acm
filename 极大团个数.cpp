#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <string>
#include <vector>
#define inf 0x3f3f3f3f
#define mod 10007
using namespace std;
typedef long long ll;
const int max_n=150;
bool mp[max_n][max_n];
int some[max_n][max_n];
int none[max_n][max_n];
int ans;
int n,m;
int all[max_n][max_n];//all为已确定的极大团顶点的集合，some为未处理顶点集（初始状态是全部顶点），
//none为不取的(已搜过的)顶点集。
void dfs(int d,int an,int so,int no){
    //some中的点与all中每个点都有边
    if(!so&&!no){
        ans++;
        return;
    }
    if(ans>1000){
        return;
    }
    int u=some[d][1];
    for(int i=1;i<=so;++i){
        //cout<<i<<endl;
        int v=some[d][i];
        if(mp[u][v]){
            continue;
        }
        int ts=0,tn=0;
        for(int j=1;j<=an;++j){
            all[d+1][j]=all[d][j];
        }
        all[d+1][an+1]=v;
        for(int j=1;j<=so;++j){
            if(mp[v][some[d][j]]){
                some[d+1][++ts]=some[d][j];
            }
        }
        for(int j=1;j<=no;++j){
            if(mp[v][none[d][j]]){//包含none[d][j]的极大团已经算过了
                none[d+1][++tn]=none[d][j];
            }
        }
        dfs(d+1,an+1,ts,tn);
        some[d][i]=0;
        none[d][++no]=v;
    }
}
int main(){
    while(~scanf("%d%d",&n,&m)){
        ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                mp[i][j]=0;
            }
        }
        for(int i=0;i<m;++i){
            int u,v;
            scanf("%d%d",&u,&v);
            mp[u][v]=mp[v][u]=1;
        }
        for(int i=1;i<=n;++i){
            some[0][i]=i;
        }
        dfs(0,0,n,0);
        if(ans>1000){
            printf("Too many maximal sets of friends.\n");
        }else{
            printf("%d\n",ans);
        }
    }
    return 0;
}