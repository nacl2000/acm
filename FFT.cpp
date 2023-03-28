#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn = 2e6 + 5;
const int MAX = 5e5 + 5;
#define PI acos(-1.0)

struct Complex {
    double x, y;

    Complex(double _x = 0.0, double _y = 0.0) {
        x = _x;
        y = _y;
    }

    Complex operator+(const Complex &b) const {
        return Complex(x + b.x, y + b.y);
    }

    Complex operator-(const Complex &b) const {
        return Complex(x - b.x, y - b.y);
    }

    Complex operator*(const Complex &b) const {
        return Complex(x * b.x - y * b.y, x * b.y + y * b.x);
    }
};

int n, num[maxn], vis[maxn], len = 1 << 20;
void FFT(Complex *a,int inv,int len)
{
    for(int i=0,j=0;i<len;i++){

        if(j>i)swap(a[i],a[j]);//翻转位置
        int k=len;
        while(j&(k>>=1))j&=~k;
        j|=k;
    }
    for(int i=2;i<=len;i<<=1)//i表示合并到哪一层
    {
        Complex wn(cos(-inv*2*PI/i),sin(-inv*2*PI/i));
        for(int j=0;j<len;j+=i){//j表示枚举合并区间
            Complex w(1,0);
            for(int k=j;k<j+i/2;k++,w=w*wn){//枚举区间的下标
                Complex l=a[k],r=w*a[k+i/2];
                a[k]=l+r;a[k+i/2]=l-r;
            }
        }
    }
    if(inv==-1){
        for(int i=0;i<len;i++)
            a[i].x/=len;
    }
    return ;
}
Complex a[maxn], b[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &num[i]);
        a[num[i]].x = 1;//标记有这个数
        b[MAX - num[i]].x = 1;//构建-i,但是数组不能为负数，用MAX-i代替来构建多项式
    }
    FFT(a, 1, len);
    FFT(b, 1, len);
    for (int i = 0; i < len; i++) {
        a[i] = a[i] * b[i];//乘起来
    }
    FFT(a, -1, len);
    for (int i = 0; i <= MAX*2; i++) {
        int x = int(a[i].x + 0.5);//四舍五入
        if (x > 0)vis[abs(MAX - i)] = 1;//可行
    }//得到的数组vis[i]表示差值i是否存在
    for (int i = n; i <= MAX; i++) {
        int flag = true;
        for (int j = i; j <= MAX; j += i)//i的倍数
        {
            if (vis[j] == true) {
                flag = false;
                break;
            }
        }
        if (flag == true) {//说明并没有找到是他们差值的约数
            printf("%d", i);
            break;
        }
    }
    return 0;
}