#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int max_n = 100005;
struct node
{
	int l, r;
	ll sum;
} b[max_n<<2];
int lazy[max_n << 2];
void build(int left, int right, int i)
{
	b[i].l = left;
	b[i].r = right;
	lazy[i] = 0;
    if(left==right){
        b[i].sum = 0;
        return;
    }
	int mid = ((left + right) >> 1);
	build(left, mid, i << 1);
	build(mid + 1, right, (i<<1)+1);
    b[i].sum=b[i<<1].sum+b[(i<<1)+1].sum;
	return;
}
void pushdown(int i)
{
	if (lazy[i])
	{
		b[i << 1].sum = b[i << 1].r - b[i << 1].l + 1;
		lazy[i << 1] += lazy[i];
		b[(i<<1)+1].sum = b[(i<<1)|1].r - b[(i<<1)+1].l + 1;
		lazy[(i<<1)+1] += lazy[i];
		lazy[i] = 0;
	}
}
void pushup(int i){
	b[i].sum=b[i<<1].sum+b[(i<<1)|1].sum;
}
void add(int left, int right, int num, int i)
{
	if (b[i].r < left || b[i].l > right)
	{
		return;
	}
	if (b[i].l >= left && b[i].r <= right)
	{
		b[i].sum = b[i].r-b[i].l+1;
		lazy[i] = num;
		return;
	}
	pushdown(i);
	int mid = ((b[i].l + b[i].r) >> 1);
	if (right <= mid)
	{
		add(left, right, num, i << 1);
	}
	else if (left > mid)
	{
		add(left, right, num, (i<<1)+1);
	}
	else
	{
		add(left, mid, num, i << 1);
		add(mid + 1, right, num, (i<<1)+1);
	}
	pushup(i);
}
int query(int left, int right, int i)
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
int main()
{
	return 0;
}