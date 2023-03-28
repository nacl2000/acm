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
using namespace std;
#define mod 1000000007
typedef long long ll;
const int max_n = 5e4 + 10;
const int inf = 0x3f3f3f3f;
//POJ1741
struct edge {
    int to, length;
};
int N, K;
vector<edge> G[max_n];
bool centroid[max_n];
int subtree_size[max_n],ds[max_n];
int ans,cnt;
void init() {
    // memset(centroid,0,sizeof(centroid));
    for (int i = 1; i <= N; ++i) {
        G[i].clear();
    }
    ans = 0;
}
int compute_subtree_size(int v, int p) { //求子树大小
    int c = 1;
    for (int i = 0; i < G[v].size(); ++i) {
        int w = G[v][i].to;
        if (w == p || centroid[w]) {
            continue;
        }
        c += compute_subtree_size(w, v);
    }
    subtree_size[v] = c;
    return c;
}
pair<int, int> search_centroid(int v, int p, int t) { //找重心
    pair<int, int> res = make_pair(inf, -1);
    int s = 1, m = 0;
    for (int i = 0; i < G[v].size(); ++i) {
        int w = G[v][i].to;
        if (w == p || centroid[w]) {
            continue;
        }
        res = min(res, search_centroid(w, v, t));
        m = max(m, subtree_size[w]);
        s += subtree_size[w];
    }
    m = max(m, t - s);
    res = min(res, make_pair(m, v));
    return res;
}
void enumerate_paths(int v, int p, int d) { //所有顶点到重心的距离
    ds[cnt++]=d;
    for (int i = 0; i < G[v].size(); ++i) {
        int w = G[v][i].to;
        if (w == p || centroid[w]) {
            continue;
        }
        enumerate_paths(w, v, d + G[v][i].length);
    }
}
int count_pairs(int l) { //计算对数
    int res = 0;
    //cout<<l<<" "<<cnt<<endl;
    sort(ds+l, ds+cnt);
    int j = cnt-1;
    for (int i = l; i < cnt; ++i) {
        while(j>i){
            if(ds[i]+ds[j]<=K){
                res+=j-i;
                break;
            }else{
                j--;
            }
        }
    }
    return res;
}
void solve_subproblem(int v) {
    compute_subtree_size(v, -1);
    int s = search_centroid(v, -1, subtree_size[v]).second;
    centroid[s] = 1;
    for (int i = 0; i < G[s].size(); ++i) {
        if (centroid[G[s][i].to]) {
            continue;
        }
        solve_subproblem(G[s][i].to);
    }
    cnt=0;
    ds[cnt++]=0;
    for (int i = 0; i < G[s].size(); ++i) {
        if (centroid[G[s][i].to]) {
            continue;
        }
        int l=cnt;
        enumerate_paths(G[s][i].to, s, G[s][i].length);
        ans -= count_pairs(l);
    }
    ans += count_pairs(0);
    centroid[s] = 0;
}
int main() {
    int m;
    ans = 0;
    memset(centroid, 0, sizeof(centroid));
    scanf("%d%d", &N, &m);
    char tmp;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        scanf("%d %d %d %c", &u, &v, &c,&tmp);
        G[u].push_back(edge{v, c});
        G[v].push_back(edge{u, c});
    }
    scanf("%d",&K);
    solve_subproblem(1);
    printf("%d\n", ans);
    return 0;
}