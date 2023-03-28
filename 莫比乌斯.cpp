//洛谷P2522 [HAOI2011]Problem b
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 5e4+10;
ll mu[max_n];
ll sum[max_n];
void get_mu() {
    mu[1] = 1;
    static bool vis[max_n];
    static ll prime[max_n], p_sz, d;
    for (int i=2;i<max_n;i++)
    {
        if (!vis[i]) {
            prime[p_sz++] = i;
            mu[i] = -1;
        }
        for (ll j = 0; j < p_sz && (d = i * prime[j]) < max_n; ++j) {
            vis[d] = 1;
            if (i % prime[j] == 0) {
                mu[d] = 0;
                break;
            }
            else mu[d] = -mu[i];
        }
    }
    for(int i=1;i<max_n;++i){
        sum[i]=mu[i]+sum[i-1];
    }
}
ll solve(ll n, ll m, ll k){
    if(n>m){
        swap(n,m);
    }
    ll res=0;
    for(ll l=1,r;l<=n/k;l=r+1){//整除分块
        r=min(n/k/(n/(k*l)),m/k/(m/(k*l)));
        r=min(r,n/k);
        res+=(sum[r]-sum[l-1])*(n/(k*l))*(m/(k*l));
    }
    return res;
}
int main(){
    ll a,b,c,d,k;
    int t;
    get_mu();
    cin>>t;
    while(t--){
        scanf("%lld%lld%lld%lld%lld",&a,&b,&c,&d,&k);
        printf("%lld\n",solve(b,d,k)-solve(b,c-1,k)-solve(a-1,d,k)+solve(a-1,c-1,k));
    }
    return 0;
}