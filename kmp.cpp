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
const int max_n=101010;
const int max_m=100010;
const int mod=10007;
char p[max_m],s[max_n];
int prefix_table[max_m];
void prefix(int n){
    int j,k;
    j=0;
    k=-1;
    prefix_table[0]=-1;
    while(j<n){
        if(k==-1||p[j]==p[k]){
            prefix_table[++j]=++k;
        }else{
            k=prefix_table[k];
        }
    }
}
void kmp(int n,int m){
    int i=0,j=0;
    while(i<n){
        if(s[i]==p[j]||j==-1){
            ++i;
            ++j;
        }else{
            j=prefix_table[j];
        }
        if(j==m){
            j=prefix_table[j];
        }
    }
}
int main(){
    return 0;
}