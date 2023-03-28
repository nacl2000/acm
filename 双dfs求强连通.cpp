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
const int max_v=150;
int V;
vector<int> g[max_v];
vector<int> rg[max_v];
vector<int> vs;
bool used[max_v];
int cmp[max_v];
void add_edge(int from,int to){
    g[from].push_back(to);
    rg[to].push_back(from);
}
void dfs(int v){
    used[v]=true;
    for(int i=0;i<g[v].size();++i){
        if(!used[g[v][i]]){
            dfs(g[v][i]);
        }
    }
    vs.push_back(v);
}
void rdfs(int v,int k){
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rg[v].size();++i){
        if(!used[rg[v][i]]){
            rdfs(rg[v][i],k);
        }
    }
}
int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=1;v<=V;++v){
        if(!used[v]){
            dfs(v);
        }
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;--i){
        if(!used[vs[i]]){
            rdfs(vs[i],k++);
        }
    }
    return k;
}
int a[150],b[150];
int main(){
    return 0;
}