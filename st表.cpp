#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
int n,m;
const int N = 1e5+10;
int st[N][25],Log[N],st2[N][25];//2^20就过一百万了，完全够用 
void init(){
	Log[1] = 0;//预处理log函数 
	for(int i = 2;i <= n+1;i++) Log[i] = Log[i/2]+1;
	for(int j = 1; (1<<j) <= n;j++){	//涉及到位运算多加括号! 
		for(int i = 1;i + (1<<(j-1)) <= n;i++){
			st[i][j] = max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}
int ask(int l,int r){
	int k = Log[r-l+1];
	int mx = max(st[l][k],st[r-(1<<k)+1][k]);
	//printf("%d %d\n",k,mx);
	return mx;
}
int main(){
	return 0;
}
