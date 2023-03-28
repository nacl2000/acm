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
using namespace std;
#define mod 1000000007
const int inf=0x3f3f3f3f;
typedef long long ll;
const int max_n=1e6+10;
ll fac[max_n]; // 阶乘
//南京区域赛2019 B
void init() { 
    fac[0] = fac[1] = 1;
    for(ll i = 2; i < max_n; i++)
        fac[i] = fac[i - 1] * i % mod;
}
ll getInv(int b) {
    if(b == 1) return 1;
    return (mod-mod/b) * getInv(mod%b) % mod;
}
ll C(ll a, ll b) {
    return fac[a] * getInv(fac[b]) % mod * getInv(fac[a - b]) % mod;
}
int main(){
    init();
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n==1||m==1){
            cout<<2<<endl;
            continue;
        }
        cout<<4*C(n+m-2,n-1)%mod<<endl;
    }
    return 0;
}
