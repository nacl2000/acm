#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm> 
#include <cmath>
#include <set>
#include <queue>
//将不等式全部化成xi – xj >= k的形式，这样建立j->i的边，权值为k的边
//如果不等式组中有xi – xj > k，因为一般题目都是对整形变量的约束，化为xi – xj >= k+1即可
//如果xi – xj = k呢，那么可以变为如下两个：xi – xj >= k, xi – xj <= k,进一步变为xj – xi >= -k，建立两条边即可。
//如果求取的是最大值，那么求取最短路，将不等式全部化成xi – xj <= k的形式, 
//这样建立j->i的边，权值为k的边，如果像上面的两种情况，那么同样地标准化就行了。
using namespace std;
const int inf=0x3f3f3f3f;
struct edge{
    int h,w;
};
typedef pair<int,int> P;
const int max_n=50050;
vector<P> b[max_n];
void add_edge(int u,int v,int w){
    //cout<<u<<" "<<v<<" "<<w<<endl;
    b[u].push_back(make_pair(v,w));
}
bool cmp(struct edge a,struct edge b){
    return a.h<b.h;
}
int n;
bool vis[max_n];
int times[max_n];
int d[max_n];
queue<int> q;
int spfa(int s){
    d[s]=0;
    vis[s]=true;
    q.push(s);
    while(!q.empty()){
        int tmp=q.front();
        times[tmp]++;
        q.pop();
        vis[tmp]=false;
        if(times[tmp]>n){
            return 0;
        }
        for(int i=0;i<b[tmp].size();++i){
            P tp=b[tmp][i];
            if(d[tp.first]<d[tmp]+tp.second&&d[tmp]+tp.second>=0){
                d[tp.first]=d[tmp]+tp.second;
                if(!vis[tp.first]){
                    q.push(tp.first);
                    vis[tp.first]=true;
                }
            }
        }
    }
    return 1;
}
int main(){
    int a,b,c;
    scanf("%d",&n);
    int ma=-1,mi=inf;
    for(int i=0;i<n;++i){
        scanf("%d%d%d",&a,&b,&c);
        ++a;
        ++b;
        add_edge(a-1,b,c);
        ma=max(ma,b);
        mi=min(mi,a);
    }
    for(int i=mi;i<=ma;++i){
        d[i]=-inf;
        add_edge(i-1,i,0);
        add_edge(i,i-1,-1);
    }
    spfa(mi-1);    
    // for(int i=mi-1;i<=ma;++i){
    //     cout<<d[i]<<endl;
    // }
    cout<<d[ma]<<endl;
    return 0;
}   