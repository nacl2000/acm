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
int n,m;
int mp[max_n][max_n];
int vis[max_n],cnt[max_n],ans[max_n];
int res;
bool dfs(int pos,int num){
    for(int i=pos+1;i<=n;++i){
        if(num+cnt[i]<=res){
            return false;
        }
        int j=0;
        for(j=0;j<num;++j){
            if(!mp[vis[j]][i]){
                break;
            }
        }
        if(j==num){
            vis[num]=i;
            if(dfs(i,num+1)){
                return true;
            }
        }
    }
    if(num>res){
        for(int i=0;i<num;++i){
            ans[i]=vis[i];
        }
        res=num;
        return true;
    }
    return false;
}
void maxClique(){
    for(int i=n;i>0;--i){
        vis[0]=i;
        dfs(i,1);
        cnt[i]=res;
    }
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        res=0;
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(i==j){
                    mp[i][j]=0;
                    continue;
                }
                mp[i][j]=1;
            }
        }
        int u,v;
        for(int i=0;i<m;++i){
            scanf("%d%d",&u,&v);
            mp[u][v]=mp[v][u]=0;
        }
        maxClique();
        printf("%d\n",res);//最大团的个数
        for(int i=0;i<res;i++)//最大团中的顶点
            printf("%d ",ans[i]);
        printf("\n");
    }
    return 0;
}