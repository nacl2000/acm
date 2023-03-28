#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
void extgcd(ll a, ll b, ll &d, ll &x, ll &y)
{
    if (!b)
    {
        d = a;
        x = 1;
        y = 0;
    }
    else
    {
        extgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}
int main()
{
return 0;
}