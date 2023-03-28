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
const int max_e = 1000100;
const int max_v = 1000100;
const int inf = 0x3f3f3f3f;
struct edge {
    int u, v,cost;
};
vector<edge> es;
int V, E;
int par[max_v];
void init(int n) {
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
    }
}
int find(int x) {
    if (par[x] == x) {
        return x;
    } else {
        int px = find(par[x]);
        par[x] = px;
    }
    return par[x];
}
void unite(int x, int y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
        par[px] = py;
    }
}
bool same(int x, int y) { return find(x) == find(y); }
bool comp(const edge& e1,const edge& e2){
	return e1.cost<e2.cost;
}
int kruskal() {
    sort(es.begin(),es.end(),comp);
    init(V);
    int res = 0;
    for (int i = 0; i < es.size(); ++i) {
        edge e = es[i];
        if (!same(e.u, e.v)) {
            unite(e.u,e.v);
			res+=e.cost;
        }
    }
    return res;
}
int main() {
    return 0;
}