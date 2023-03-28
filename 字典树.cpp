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
#include<sstream>
#include <vector>
using namespace std;
typedef long long ll;
const int max_n = 1e5 + 5;
int ans;
int trie[max_n][30];
bool vis[max_n];
int tot = 0;
void add(string s) {
    int root = 0;
    int len = s.size();
    for (int i = 0; i < len; ++i) {
        int v = s[i] - 'a';
        if (!trie[root][v]) {
            trie[root][v] = ++tot;
        }
        root = trie[root][v];
    }
    if (!vis[root]) {
        ans++;
        vis[root] = 1;
    }
}
string s;
int main() {
    return 0;
}