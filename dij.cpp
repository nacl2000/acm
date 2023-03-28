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
const int max_v=1000;
const int inf=0x3f3f3f3f;
struct edge{
    int to,cost;
};
typedef pair<int,int> P;
vector<edge> g[max_v];
void add_edge(int u,int v,int c){
	g[u].push_back(edge{v,c});
	g[v].push_back(edge{u,c});
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
int main(){              
    return 0;
}
