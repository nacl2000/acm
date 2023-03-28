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
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
ll mul(ll a,ll b,ll p)
{
    ll ans=0;
    for(; b; b>>=1)
    {
        if(b&1)
            ans=(ans+a)%p;
        a=a*2%p;
    }
    return ans;
}
ll binaryPow(ll a, ll b, ll m){
	if(b == 0)
		return 1;
	else if(b % 2 == 1)
		return a * binaryPow(a, b - 1, m) % m;
	else{
		ll num = binaryPow(a, b/2, m) % m;	//优化 
		return num * num % m;
    }
}
int main(){
    return 0;
}