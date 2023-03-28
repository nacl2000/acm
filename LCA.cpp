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
const int max_v=105;
const int max_log_v=20;
vector<int> g[max_v];
int root;
int parent[max_log_v][max_v];
int depth[max_v];
void dfs(int v,int p,int d){
    parent[0][v]=p;
    depth[v]=d;
    for(int i=0;i<g[v].size();++i){
        if(g[v][i]!=p){
            dfs(g[v][i],v,d+1);
        }
    }
}
void init(int V){
    dfs(root,-1,0);
    for(int k=0;k+1<max_log_v;++k){
        for(int v=0;v<V;++v){
            if(parent[k][v]<0){
                parent[k+1][v]=-1;
            }else{
                parent[k+1][v]=parent[k][parent[k][v]];
            }
        }
    }
}
int lca(int u,int v){
    if(depth[u]>depth[v]){
        swap(u,v);
    }
    for(int k=0;k<max_log_v;++k){
        if((depth[u]-depth[v])>>k&1){
            v=parent[k][v];
        }
    }
    if(u==v){
        return u;
    }
    for(int k=max_log_v-1;k>=0;--k){
        if(parent[k][u]!=parent[k][v]){
            u=parent[k][u];
            v=parent[k][v];
        }
    }
    return parent[0][u];
}
int main(){
    return 0;
}