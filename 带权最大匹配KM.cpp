#include <iostream>
#include<stdio.h>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#define ll long long
using namespace std;
#define maxn 605
#define INF 0x3f3f3f3f
//2019南京Spy
ll n, a[maxn],b[maxn],c[maxn],p[maxn];
ll w[maxn][maxn];
ll lx[maxn] , ly[maxn];
ll linker[maxn];
ll slack[maxn];
bool visy[maxn];
ll pre[maxn];
void bfs( ll k ){
    ll x , y = 0 , yy = 0 , delta;
    memset( pre , 0 , sizeof(pre) );
    for( ll i = 1 ; i <= n ; i++ ) slack[i] = INF;
    linker[y] = k;
    while(1){
        x = linker[y]; delta = INF; visy[y] = true;
        for( ll i = 1 ; i <= n ;i++ ){
            if( !visy[i] ){
                if( slack[i] > lx[x] + ly[i] - w[x][i] ){
                    slack[i] = lx[x] + ly[i] - w[x][i];
                    pre[i] = y;
                }
                if( slack[i] < delta ) delta = slack[i] , yy = i ;
            }
        }
        for( ll i = 0 ; i <= n ; i++ ){
            if( visy[i] ) lx[linker[i]] -= delta , ly[i] += delta;
            else slack[i] -= delta;
        }
        y = yy ;
        if( linker[y] == -1 ) break;
    }
    while( y ) linker[y] = linker[pre[y]] , y = pre[y];
}
 
ll KM(){
    memset( lx , 0 ,sizeof(lx) );
    memset( ly , 0 ,sizeof(ly) );
    memset( linker , -1, sizeof(linker) );
    for( ll i = 1 ; i <= n ; i++ ){
        memset( visy , false , sizeof(visy) );
        bfs(i);
    }
    ll res = 0 ;
        for( ll i = 1 ; i <= n ; i++ ){
            if( linker[i] != -1 ){
                res += w[linker[i]][i] ;
            }
        }
        return res;
}
 
int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=1;i<=n;i++) scanf("%lld",&p[i]);
    for(ll i=1;i<=n;i++) scanf("%lld",&b[i]);
    for(ll i=1;i<=n;i++) scanf("%lld",&c[i]);
    for(ll i=1;i<=n;i++)
    {
        for(ll j=1;j<=n;j++)
        {
            ll s=0;
            for(ll k=1;k<=n;k++)
            {
                if(b[i]+c[j]>a[k]) s+=p[k];
            }
            w[i][j]=s;
        }
    }
    
    //printf("%lld\n",km());
    
        printf("%lld\n",KM());
}