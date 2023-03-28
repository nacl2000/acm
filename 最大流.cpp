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
#define max_v 500
#define mod 10007
using namespace std;
typedef long long ll;
struct edge{
    int to,cap,rev;
};
vector<edge> g[max_v];
int level[max_v];
int iter[max_v];
void add_edge(int from,int to,int cap){
    g[from].push_back((edge){to,cap,g[to].size()});
    g[to].push_back((edge){from,0,g[from].size()-1});
}
void bfs(int s){
    memset(level,-1,sizeof(level));
    queue<int> q;
    level[s]=0;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int i=0;i<g[v].size();++i){
            edge &e=g[v][i];
            if(e.cap>0&&level[e.to]<0){
                level[e.to]=level[v]+1;
                q.push(e.to);
            }
        }
    }
}
int dfs(int v,int t,int f){
    if(v==t){
        return f;
    }
    for(int &i=iter[v];i<g[v].size();++i){
        edge &e=g[v][i];
        if(e.cap>0&&level[v]<level[e.to]){
            int d=dfs(e.to,t,min(f,e.cap));
            if(d>0){
                e.cap-=d;
                g[e.to][e.rev].cap+=d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s,int t){
    int flow=0;
    for(;;){
        bfs(s);
        if(level[t]<0){
            return flow;
        }
        memset(iter,0,sizeof(iter));
        int f;
        while((f=dfs(s,t,inf))>0){
            flow+=f;
        }
    }
}
int main(){
    return 0;
}