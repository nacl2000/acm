#include <cstdio>
#include <iostream>//O(sqrt(n)*m)
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
const int max_n = 3e3 + 5;
const int inf = 0x3f3f3f3f;
vector<int> g[max_n];
int dis,mx[max_n], my[max_n], dx[max_n], dy[max_n];
bool vis[max_n]; 
void add_edge(int u, int v) {
	g[u].push_back(v);
}
bool bfs(int n) {
	queue<int> q;
	memset(dx, -1, sizeof(dx));
	memset(dy, -1, sizeof(dy));
	//找出未匹配的点 (左边)
	for (int i = 1; i <= n; i++) {
		if (mx[i] == -1) q.push(i), dx[i] = 0;
	}	
	dis = inf; //初始令增广路为无穷 
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (dx[u] > dis) break; //代表还有比dis更长的增广路 留待下次bfs扩展
		for (int j = 0; j<g[u].size(); ++j) {
			int v = g[u][j]; 
			if (dy[v] == -1) { //代表还未遍历过 
				dy[v] = dx[u] + 1; //给予层次
				if (my[v] == -1) {
					dis = dy[v]; //找到增广路 
				} else {
					//如果已经匹配了 就把匹配好的点（左边）放入队列进行扩展 
					dx[my[v]] = dy[v] + 1;
					q.push(my[v]);
				}
			}
		} 
	}
	return dis != inf; //等于INF就未找到增广路 
}
bool dfs(int u) {
	for (int j = 0; j<g[u].size(); ++j) {
		int v = g[u][j];
		if (vis[v] || dy[v] != dx[u] + 1) continue; //如果未访问且是u的下层次点 
		vis[v] = true; 
		if (my[v] != -1 && dy[v] == dis) continue; //如果这个点已经匹配 且找到的增广路已经大于dis 
		if (my[v] == -1 || dfs(my[v])) {
			my[v] = u; mx[u] = v;
			return true;
		}
	}
	return false;
} 
int getMax(int n) {
	int ans = 0;
	memset(mx, -1, sizeof(mx));
	memset(my, -1, sizeof(my));
	while (bfs(n)) { //查找是否有增广路 
		memset(vis, false, sizeof(vis)); //对于找到的一条增广路径查询 
		for (int i = 1; i <= n; i++) {
			if (mx[i] == -1 && dfs(i)) ans++; //如果未匹配才去dfs 
		} 		
	}
    for(int i=1;i<=n;++i){
        g[i].clear();
    }
	return ans;
}
int main(){
	return 0;
}
