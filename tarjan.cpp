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
const int max_n=1e5+10;
const int inf=0x3f3f3f3f;
int dfn[max_n],low[max_n],scc[max_n],cnt,sum;
vector<int> g[max_n];
void init(){
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(scc,0,sizeof(scc));
    cnt=sum=0;
}
stack<int> st;
void add_edge(int from,int to){
    g[from].push_back(to);
}
void tarjan(int root){
    if(dfn[root]){
        return;
    }
    dfn[root]=low[root]=++cnt;
    st.push(root);
    for(int i=0;i<g[root].size();++i){
        int v=g[root][i];
        if(!dfn[v]){
            tarjan(v);
            low[root]=min(low[root],low[v]);
        }else if(!scc[v]){
            low[root]=min(low[root],dfn[v]);
        }
    }
    if(low[root]==dfn[root]){
        sum++;
        for(;;){
            int x=st.top();
            st.pop();
            scc[x]=sum;
            if(x==root){
                break;
            }
        }
    }
}
int main(){
    return 0;
}