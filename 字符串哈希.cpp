#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const int max_n = 100;
const int mod = 1e9 + 7;
const int x=123;
int n,m,pos;
char s[max_n];
ull H[max_n],xp[max_n],hash[max_n];
int ran[max_n];
//hash[i,L]=H[i]-H[i+L]*xp[L];//i为起点长度为L的字符串
int main(){
    scanf("%s",s);
    n=strlen(s);
    H[n]=0;
    for(int i=n-1;i>=0;--i){
        H[i]=H[i+1]*x+(s[i]-'a');
    }    
    xp[0]=1;
    for(int i=1;i<=n;++i){
        xp[i]=xp[i-1]*x;
    }
    return 0;
}