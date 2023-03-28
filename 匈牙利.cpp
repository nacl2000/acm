#include <algorithm>//O(n*m)
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
const int inf = 0x3f3f3f3f;
typedef long long ll;
const int max_n = 30;
const ll mod = 998244353;
int used[max_n], nxt[max_n];
vector<int> g[max_n];
void init(int n) {
    memset(nxt, 0, sizeof(nxt));
    for (int i = 1; i <= n; ++i) {
        g[i].clear();
    }
}
bool find(int x) {
    for (int i = 0; i < g[x].size(); ++i) {
        int v = g[x][i];
        if (!used[v]) {
            used[v] = 1;
            if (nxt[v] == 0 || find(nxt[v])) {
                nxt[v] = x;
                return true;
            }
        }
    }
    return false;
}
int match(int n) {
    int ans=0;
    for (int i = 0; i <= n; ++i) {
        memset(used, 0, sizeof(used));
        if (find(i)) {
            ans++;
        }
    }
    return ans;
}
int main(){
    return 0;
}