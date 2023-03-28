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
int par[100005];
int ran[100005];
void init(int n){
	for(int i=0;i<n;++i){
		par[i]=i;
		ran[i]=0;
	}
}
int find(int x){
	if(par[x]==x){
		return x;
	}else{
		int px=find(par[x]);
		par[x]=px;
	}
	return par[x];
}
void unite(int x,int y){
	int px=find(x);
	int py=find(y);
	if(px==py){
		return;
	}
	par[px]=py;
}
bool same(int x,int y){
	return find(x)==find(y);
}
int main(){           
    return 0;
}
