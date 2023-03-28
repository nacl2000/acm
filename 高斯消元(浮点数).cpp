#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
const int N = 1010;
const double EPS=1e-12;
int m,n;
double a[N][N],x[N];
int Gauss(int m,int n){
    int col=0, k=0;//col为列号,k为行号
    for (;k<m&&col<n;++k,++col){
        int r = k;
        for (int i=k+1;i<m;++i)
            if(fabs(a[i][col])>fabs(a[r][col]))r=i;
        if (fabs(a[r][col])<EPS){k--;continue;}//列全为0
        if (r!=k)for(int i=col;i<=n;++i)
            swap(a[k][i],a[r][i]);
        for (int i=k+1;i<m;++i)//消元
            if(fabs(a[i][col])>EPS){
            double t = a[i][col]/a[k][col];
            for (int j=col;j<=n;j++)a[i][j]-=a[k][j]*t;
            a[i][col] = 0;
        }
    }
    for(int i=k ;i<m ;++i)//无解
        if (fabs(a[i][n])>EPS) return -1;
    if (k < n) return n - k;  //自由元个数
    for (int i =n-1; i>=0; i--){//回带求解
        double temp = a[i][n];
        for (int j=i+1; j<n; ++j)
            temp -= x[j] * a[i][j];
        x[i] = (temp / a[i][i]);
    }
    return 0;
}
int main(){
    int n,m;
    while(cin>>n>>m){
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                cin>>a[i][j];
            }
        }
        cout<<Gauss(n,m-1)<<endl;
        for(int i=0;i<m-1;++i){
            cout<<x[i]<<endl;
        }
    }
    return 0;
}
