#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int max_n = 3e4 + 10;
const int mod = 1e9 + 7;
char s[max_n];
int lcp[max_n],lcs[max_n];
int y[max_n],x[max_n],c[max_n],sa[max_n],ran1[max_n],ran2[max_n];
int n,m;
void get_SA()
{
    memset(c,0,sizeof(c));
    memset(sa,0,sizeof(sa));
    memset(y,0,sizeof(y));
    memset(x,0,sizeof(x));
	for (int i=1;i<=n;++i) ++c[x[i]=s[i]];
	//c数组是桶 
	//x[i]是第i个元素的第一关键字 
    for (int i=2;i<=m;++i) c[i]+=c[i-1]; 
    //做c的前缀和，我们就可以得出每个关键字最多是在第几名 
    for (int i=n;i>=1;--i) sa[c[x[i]]--]=i; 
    for (int k=1;k<=n;k<<=1)
    {
        int num=0;
        for (int i=n-k+1;i<=n;++i) y[++num]=i;
        //y[i]表示第二关键字排名为i的数，第一关键字的位置 
		//第n-k+1到第n位是没有第二关键字的 所以排名在最前面 
        for (int i=1;i<=n;++i) if (sa[i]>k) y[++num]=sa[i]-k;
        //排名为i的数 在数组中是否在第k位以后
		//如果满足(sa[i]>k) 那么它可以作为别人的第二关键字，就把它的第一关键字的位置添加进y就行了
		//所以i枚举的是第二关键字的排名，第二关键字靠前的先入队 
        for (int i=1;i<=m;++i) c[i]=0;
        //初始化c桶 
        for (int i=1;i<=n;++i) ++c[x[i]];
        //因为上一次循环已经算出了这次的第一关键字 所以直接加就行了 
        for (int i=2;i<=m;++i) c[i]+=c[i-1];//第一关键字排名为1~i的数有多少个 
        for (int i=n;i>=1;--i) sa[c[x[y[i]]]--]=y[i],y[i]=0;
        //因为y的顺序是按照第二关键字的顺序来排的 
        //第二关键字靠后的，在同一个第一关键字桶中排名越靠后 
        //基数排序 
        swap(x,y);
		//这里不用想太多，因为要生成新的x时要用到旧的，就把旧的复制下来，没别的意思 
        x[sa[1]]=1;num=1;
        for (int i=2;i<=n;++i)
            x[sa[i]]=(y[sa[i]]==y[sa[i-1]] && y[sa[i]+k]==y[sa[i-1]+k]) ? num : ++num;
        //因为sa[i]已经排好序了，所以可以按排名枚举，生成下一次的第一关键字 
        if (num==n) break;
        m=num;
        //这里就不用那个122了，因为都有新的编号了 
    }
}
void get_height(int height[],int ran[])
{
    int k=0;
    for (int i=1;i<=n;++i) ran[sa[i]]=i;
    for (int i=1;i<=n;++i)  
    {
        if (ran[i]==1) continue;//第一名height为0 
        if (k) --k;//h[i]>=h[i-1]+1;
        int j=sa[ran[i]-1];
        while (j+k<=n && i+k<=n && s[i+k]==s[j+k]) ++k;
        height[ran[i]]=k;//h[i]=height[ran[i]];
    }
}
const int N = 3e4 + 10;
int lcp_st[N][20], lcs_st[N][20], Log[N]; // 2^20就过一百万了，完全够用
void init(int st[][20]) {
    for (int j = 1; (1 << j) <= n; j++) { //涉及到位运算多加括号!
        for (int i = 1; i + (1 << (j - 1)) <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int ask(int l, int r, int st[][20]) {
    if (l > r) {
        swap(l, r);
    }
    r--;
    int k = Log[r - l + 1];
    int mx = min(st[l][k], st[r - (1 << k) + 1][k]);
    // printf("%d %d\n",k,mx);
    return mx;
}
ll p[max_n], f[max_n];
int main() {
    int t;
    Log[1] = 0; //预处理log函数
    for (int i = 2; i <max_n; i++)
        Log[i] = Log[i / 2] + 1;
    cin >> t;
    while (t--) {
        memset(p,0,sizeof(p));
        memset(f,0,sizeof(f));
        scanf("%s",s+1);
        n = strlen(s+1);
        m='z'+1;
        get_SA();
        get_height(lcp,ran1);
        for (int i = 1; i <= n; ++i) {
            if(i==n){
                lcp_st[i][0]=0;
                continue;
            }
            lcp_st[i][0] = lcp[i + 1];
        }
        init(lcp_st);
        for(int i=1,j=n;i<j;){
            swap(s[i++],s[j--]);
        }
        m='z'+1;
        get_SA();
        get_height(lcs,ran2);
        for (int i = 1; i <= n; ++i) {
            if(i==n){
                lcs_st[i][0]=0;
                continue;
            }
            lcs_st[i][0] = lcs[i + 1];
        }
        init(lcs_st);
        ll ans = 0;
        for (int len = 1; len <= n/2; len++) {
            for (int i = 1; i + len <= n; i+=len) {
                int a = ask(ran1[i], ran1[i + len], lcp_st);
                a = min(a, len);
                int b = ask(ran2[n-i+1], ran2[n-i - len+1], lcs_st);
                b = min(b, len);
                int tmp = a + b - len - 1;
                if (tmp >= 0) {
                    p[i - b + 1]++;
                    p[i - b + 2 + tmp]--;
                    f[i + len + a - 1 - tmp]++;
                    f[i + len + a ]--;
                }
            }
        }
        for (int i = 2; i <= n; ++i) {
            f[i] += f[i - 1];
            p[i] += p[i - 1];
        }
        for (int i = 2; i <= n-2; ++i) {
            ans+=f[i]*p[i+1];
            //cout<<i+1<<" "<<f[i]<<" "<<p[i+1]<<'\n';
        }
        cout << ans << '\n';
    }
    return 0;
}
