#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n=5e4+10;
const int inf=0x3f3f3f3f;
//牛客A National Pandemic
vector<int> g[max_n];
void add_edge(int u,int v){
	g[u].push_back(v);
}
int d[max_n],fa[max_n],son[max_n],id[max_n],cnt,tot[max_n],top[max_n];
struct node
{
	int l, r;
	ll sum;
} b[max_n<<2];
ll lazy[max_n << 2];
void build(int left, int right, int i)
{
	b[i].l = left;
	b[i].r = right;
	lazy[i] = 0;
	b[i].sum = 0;
    if(left==right){
        return;
    }
	int mid = ((left + right) >> 1);
	build(left, mid, i << 1);
	build(mid + 1, right, (i<<1)+1);
	return;
}
void pushdown(int i)
{
	if (lazy[i])
	{
		b[i << 1].sum += lazy[i]*(b[i << 1].r - b[i << 1].l+1);
		lazy[i << 1] += lazy[i];
		b[(i<<1)+1].sum += lazy[i]*(b[(i<<1)|1].r - b[(i<<1)|1].l+1);
		lazy[(i<<1)+1] += lazy[i];
		lazy[i] = 0;
	}
}
void pushup(int i){
	b[i].sum=b[i<<1].sum+b[(i<<1)|1].sum;
}
void add(int left, int right, int i)
{
	if (b[i].r < left || b[i].l > right)
	{
		return;
	}
	if (b[i].l >= left && b[i].r <= right)
	{
		b[i].sum += (b[i].r-b[i].l+1)*1ll*2;
		lazy[i] += 2;
		return;
	}
	pushdown(i);
	int mid = ((b[i].l + b[i].r) >> 1);
	if (right <= mid)
	{
		add(left, right,  i << 1);
	}
	else if (left > mid)
	{
		add(left, right,(i<<1)+1);
	}
	else
	{
		add(left, mid, i << 1);
		add(mid + 1, right, (i<<1)+1);
	}
	pushup(i);
}
ll query(int left, int right, int i)
{
	int mid;
	if (b[i].l >= left && b[i].r <= right)
	{
		return b[i].sum;
	}
	mid = ((b[i].l + b[i].r) >> 1);
	pushdown(i);
	if (right <= mid)
	{
		return query(left, right, i << 1);
	}
	else if (left > mid)
	{
		return query(left, right, (i<<1)+1);
	}
	else
	{
		return query(left, mid, i<<1) + query(mid + 1, right, (i<<1)+1);
	}
}
void dfs1(int u,int dep){
	d[u]=dep;
	tot[u]=1;
	int ma=-1;
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		fa[v]=u;
		dfs1(v,dep+1);
		tot[u]+=tot[v];
		if(tot[v]>ma){
			ma=tot[v];
			son[u]=v;
		}
	}
}
void dfs2(int u,int pre){
	id[u]=++cnt;
	top[u]=pre;
	if(!son[u]){
		return;
	}
	dfs2(son[u],pre);
	for(int i=0;i<g[u].size();++i){
		int v=g[u][i];
		if(v!=fa[u]&&v!=son[u]){
			dfs2(v,v);
		}
	}
}
ll find(int x,int y){
	ll res=0;
	while(top[x]!=top[y]){
		if(d[x]<d[y]){
			swap(x,y);
		}
		res=(res+query(id[top[x]],id[x],1));
		x=fa[top[x]];
	}
	if(d[x]>d[y]){
		swap(x,y);
	}
	res=(res+query(id[x],id[y],1));
	return res;
}
void add1(int x,int y){
	while(top[x]!=top[y]){
		if(d[x]<d[y]){
			swap(x,y);
		}
		add(id[top[x]],id[x],1);
		x=fa[top[x]];
	}
	if(d[x]>d[y]){
		swap(x,y);
	}
	add(id[x],id[y],1);
}
ll ans[max_n];
int n;
void init(){
	cnt=0;
	memset(son,0,sizeof(son));
	memset(ans,0,sizeof(ans));
}
int main(){
	int t;
	int m;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		init();
		for(int i=1;i<n;++i){
			int u,v;
			scanf("%d%d",&u,&v);
			add_edge(u,v);
		}
		dfs1(1,1);
		dfs2(1,1);
		build(1,n,1);
		//cout<<cnt<<endl;
		int ch;
		int x,y,w;
		ll tmp=0;
		ll num=0;
		for(int i=0;i<m;++i){
			scanf("%d",&ch);
			if(ch==1){
				scanf("%d%d",&x,&w);
				add1(x,1);
				tmp+=w-d[x];
				num++;
			}else if(ch==2){
				scanf("%d",&x);
				ll res=tmp-num*d[x]+find(1,x);
				if(res>0){
					ans[x]=-res;
				}
			}else{
				scanf("%d",&x);
				ll res=tmp-num*d[x]+find(1,x)+ans[x];
				printf("%lld\n",res);
			}
		}
		for(int i=1;i<=n;++i){
			g[i].clear();
		}
	}
	return 0;
}