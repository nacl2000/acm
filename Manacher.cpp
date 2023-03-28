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
#define inf 0x3f3f3f3f
#define mod 10007
const int max_n=1e5+100;
char s[max_n];
int cnt[max_n*3];
int l;
void Manacher(char s[],int len) {//原字符串和串长
    l = 0;
    char String[max_n*3];
    String[l++] = '$'; // 0下标存储为其他字符,防止越界
    String[l++] = '#';
    for (int i = 0; i < len; i++) {
        String[l++] = s[i];
        String[l++] = '#';
    }
    //printf("%s\n",String);
    String[l] = 0; // 空字符
    int MaxR = 0;
    int flag = 0;
    for (int i = 0; i < l; i++) {
        cnt[i] = MaxR > i ? min(cnt[2 * flag - i], MaxR - i) : 1;//2*flag-i是i点关于flag的对称点
        while (String[i + cnt[i]] == String[i - cnt[i]])
            cnt[i]++;
        if (i + cnt[i] > MaxR) {
            MaxR = i + cnt[i];
            flag = i;
        }
    }
}
int main(){
    int n,q;
    scanf("%d%d",&n,&q);
    scanf("%s",s);
    Manacher(s,n);
    for(int i=0;i<l;++i){
        printf("%d ",cnt[i]);
    }
    printf("\n");
    return 0;
}
