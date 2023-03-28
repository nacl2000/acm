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
//POJ2104 区间求第K大
using namespace std;
const int max_n = 1e5+10;
typedef long long ll;
struct node{
    int ls,rs,sum;
    node(){
        ls=rs=sum=0;
    }
};
node b[max_n*40];
int root[max_n*40];
int cnt;
int a[max_n];
vector<int> v;
int get_id(int x){
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}
void update(int l,int r,int &x,int y,int pos){
    b[++cnt]=b[y];
    b[cnt].sum++;
    x=cnt;
    if(l==r){
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid){
        update(l,mid,b[x].ls,b[y].ls,pos);
    }else{
        update(mid+1,r,b[x].rs,b[y].rs,pos);
    }
}
int query(int l,int r,int r1,int r2,int k){
    if(l==r){
        return v[l-1];
    }
    int s=b[b[r2].ls].sum-b[b[r1].ls].sum;
    int mid=(l+r)/2;
    if(s>=k){
        return query(l,mid,b[r1].ls,b[r2].ls,k);
    }else{
        return query(mid+1,r,b[r1].rs,b[r2].rs,k-s);
    }
}
int main(){
    int tmp,n,m;
    cnt=0;
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        scanf("%d",&a[i]);
        v.push_back(a[i]);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    //cout<<v.size()<<endl;
    for(int i=1;i<=n;++i){
        update(1,n,root[i],root[i-1],get_id(a[i]));
    }
    for(int i=0;i<m;++i){
        int l,r,k;
        scanf("%d%d%d",&l,&r,&k);
        printf("%d\n",query(1,n,root[l-1],root[r],k));
    }
    return 0;
}