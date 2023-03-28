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
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int mod = 1e9 + 7;
const int max_n = 2e5 + 10;
typedef  long long ll;
const int N = 1e5 + 5;
int inv[N];
void inverse(int n, ll mod) {
    inv[1] = 1;
    for (int i=2; i<=n; ++i) {
        inv[i] = (ll) (mod - mod / i) * inv[mod%i] % mod;
    }
}
ll binaryPow(ll a,ll p,ll mod)
{
    ll t=1,tt=a%mod;
    while(p)
    {
        if(p&1)t=t*tt%mod;
        tt=tt*tt%mod;
        p>>=1;
    }
    return t;
}
ll getInv(ll a,ll mod)
{
    return binaryPow(a,mod-2,mod);
}
int main() {
    return 0;
}