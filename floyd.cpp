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
const int max_n = 510;
int V,d[max_n][max_n];
void floyd(){
    for(int k=0;k<V;++k){
        for(int i=0;i<V;++i){
            for(int j=0;j<V;++j){
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
}
int main(){
    return 0;
}