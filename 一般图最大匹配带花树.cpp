#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<vector>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
const int maxn=505;
int father[maxn],vst[maxn],match[maxn],pre[maxn],Type[maxn];
vector<int>edges[maxn];
queue<int>Q;
void AddEdge(int x,int y) {
	edges[x].push_back(y);
}
int n;
int LCA(int x,int y) {
	static int times=0;
	times++;
	x=father[x],y=father[y]; //已知环位置
	while(vst[x]!=times) {
		if(x) {
			vst[x]=times;
			x=father[pre[match[x]]];
		}
		swap(x,y);
	}
	return x;
}
void blossom(int x,int y,int lca) {
	while(father[x]!=lca) {
		pre[x]=y;
		y=match[x];
		if(Type[y]==1) {
			Type[y]=0;
			Q.push(y);
		}
		father[x]=father[y]=father[lca];
		x=pre[y];
	}
}

int Augument(int s) {
	for(int i=1; i<=n; i++)father[i]=i;
	memset(Type,-1,sizeof(Type));
	Q=queue<int>();
	Type[s]=0;
	Q.push(s); //仅入队o型点
	while(!Q.empty()) {
		int Now=Q.front();
		Q.pop();
		for(int i=0;i<edges[Now].size();++i) {
			int Next=edges[Now][i];
			if(Type[Next]==-1) {
				pre[Next]=Now;
				Type[Next]=1; //标记为i型点
				if(!match[Next]) {
					for(int to=Next,from=Now; to; from=pre[to]) {
						match[to]=from;
						swap(match[from],to);
					}
					return true;
				}
				Type[match[Next]]=0;
				Q.push(match[Next]);
			} else if(Type[Next]==0&&father[Now]!=father[Next]) {
				int lca=LCA(Now,Next);
				blossom(Now,Next,lca);
				blossom(Next,Now,lca);
			}
		}
	}
	return false;
}
int main() {
	return 0;
}