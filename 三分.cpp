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
const int max_n = 1e5+10;
double eps=1e-8;
ll cal(ll x){
    
}
 
ll ts(ll l,ll r){
    while(l < r) {
		ll m1 = l + (r - l)/3;
		ll m2 = r - (r - l)/3;
		if(cal(m1) < cal(m2)) r = m2 - 1;
		else l = m1 + 1;
	}
    return cal(l);
}
int main(){
    return 0;
}