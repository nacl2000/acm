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
#define max_v 505
#define mod 10007
using namespace std;
typedef long long ll;
typedef pair<int,int> P;//first保存最短距离，second保存顶点编号
struct edge {
    int to,cap,cost,rev;
};
int V;//顶点数
vector<edge> g[max_v];
int h[max_v];
int dist[max_v];
int prevv[max_v],preve[max_v];
void add_edge(int from,int to,int cap,int cost){
    g[from].push_back((edge){to,cap,cost,g[to].size()});
    g[to].push_back((edge){from,0,-cost,g[from].size()-1});
}
//s到t流量为f
int min_cost_flow(int s,int t,int f){
    int res=0;
    fill(h,h+V,0);
    while(f>0){
        priority_queue<P,vector<P>,greater<P> > q;
        fill(dist,dist+V,inf);
        dist[s]=0;
        q.push(P(0,s));
        while(!q.empty()){
            P p=q.top();
            q.pop();
            int v=p.second;
            if(dist[v]<p.first){
                continue;
            }
            for(int i=0;i<g[v].size();++i){
                edge &e=g[v][i];
                if(e.cap>0&&dist[e.to]>dist[v]+e.cost+h[v]-h[e.to]){
                    dist[e.to]=dist[v]+e.cost+h[v]-h[e.to];
                    prevv[e.to]=v;
                    preve[e.to]=i;
                    q.push(P(dist[e.to],e.to));
                }
            }
        }
        if(dist[t]==inf){
            return -1;
        }
        for(int v=0;v<V;++v){
            h[v]+=dist[v];
        }
        int d=f;
        for(int v=t;v!=s;v=prevv[v]){
            d=min(d,g[prevv[v]][preve[v]].cap);
        }
        f-=d;
        res+=d*h[t];
        for(int v=t;v!=s;v=prevv[v]){
            edge &e=g[prevv[v]][preve[v]];
            e.cap-=d;
            g[v][e.rev].cap+=d;
        }
    }
    return res;
}
int main(){
    return 0;
}