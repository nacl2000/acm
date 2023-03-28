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
const int max_v=10010;
const int inf=1e8+10;
struct edge{
    int to,cost;
};
typedef pair<int,int> P;
vector<edge> g[max_v];
void add_edge(int u,int v,int c){
	g[u].push_back(edge{v,c});
}
int d[max_v];
int V;
void dij(int s){
    fill(d,d+V+1,inf);
    d[s]=0;
    priority_queue<P,vector<P>,greater<P> >q;
    q.push(P(0,s));
    while(!q.empty()){
        P p=q.top();
        q.pop();
        if(d[p.second]<p.first){
            continue;
        }
        for(int i=0;i<g[p.second].size();++i){
            edge e=g[p.second][i];
            if(d[e.to]>d[p.second]+e.cost){
                d[e.to]=d[p.second]+e.cost;
                q.push(P(d[e.to],e.to));
            }
        }
    }
}
struct node{
    int num,cost;
    friend bool operator<(const node &x,const node &y){
        return x.cost+d[x.num]>y.cost+d[y.num];
    }
};
vector<edge> G[max_v];
void add_edge2(int u,int v,int c){
	G[u].push_back(edge{v,c});
}
int A_sat(int s,int f,int k){
    if(d[s]>1e8){
        return inf;
    }
    int cnt=0;
    int res=d[s];
    priority_queue<node> q;
    q.push(node{s,0});
    while(!q.empty()){
        node u=q.top();
        //cout<<u.num<<" "<<u.cost<<endl;
        q.pop();
        if(d[u.num]<=1e8&&u.num!=f){
            res=u.cost+d[u.num];
            cnt++;
            //cout<<cnt<<endl;
            if(cnt==k){
                return res;
            }
        }
        for(int i=0;i<G[u.num].size();++i){
            q.push(node{G[u.num][i].to,G[u.num][i].cost+u.cost});
        }
    }
    return inf;
}
int main(){    
    int n,m;
    int s,f,k,t;
    while(~scanf("%d%d",&n,&m)){
        V=n;
        scanf("%d%d%d%d",&s,&f,&k,&t);
        for(int i=0;i<m;++i){
            int u,v,w;
            scanf("%d%d%d",&u,&v,&w);
            add_edge(v,u,w);
            add_edge2(u,v,w);
        }
        dij(f);
        int ans=A_sat(s,f,k);
    }          
    return 0;
}
