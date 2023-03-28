//济南2020 A
#include <bits/stdc++.h>
using namespace std;
const int max_n=205;
typedef long long ll;
const ll mod=998244353;
int equ,var;
int x[max_n][max_n];
int free_x[max_n];
int free_num;
int Gauss(int a[max_n][max_n]){
    int max_r,col,k;
    free_num=0;
    for(k=0,col=0;k<equ&&col<var;k++,col++){
        max_r=k;
        for(int i=k+1;i<equ;++i){
            if(abs(a[i][col])>abs(a[max_r][col])){
                max_r=i;
            }
        }
        if(a[max_r][col]==0){
            k--;
            free_x[free_num++]=col;
            continue;
        }
        if(max_r!=k){
            for(int j=col;j<var+1;++j){
                swap(a[k][j],a[max_r][j]);
            }
        }
        for(int i=k+1;i<equ;++i){
            if(a[i][col]!=0){
                for(int j=col;j<var+1;++j){
                    a[i][j]^=a[k][j];
                }
            }
        }
    }
    for(int i=k;i<equ;++i){
        if(a[i][col]!=0){
            return -1;
        }
    }
    if(k<var){
        return var-k;
    }
    return 0;
}
int a[max_n][max_n],b[max_n][max_n],c[max_n][max_n];
ll binaryPow(ll a, ll b, ll m){
	if(b == 0)
		return 1;
	else if(b % 2 == 1)
		return a * binaryPow(a, b - 1, m) % m;
	else{
		ll num = binaryPow(a, b/2, m) % m;	//优化 
		return num * num % m;
    }
}
int main(){
    int n;
    cin>>n;
    equ=n;
    var=n;
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>c[i][j];
        }
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            cin>>b[i][j];
        }
    }
    ll ans=1;
    for(int j=0;j<n;++j){
        for(int k=0;k<n;++k){
            for(int z=0;z<n;++z){
                a[k][z]=c[k][z];
            }
        }
        for(int i=0;i<n;++i){
            if(b[i][j]==1){
                a[i][i]^=1;
            }
        }
        // for(int k=0;k<n;++k){
        //     for(int z=0;z<n;++z){
        //         cout<<a[k][z]<<" ";
        //     }
        //     cout<<'\n';
        // }
        //cout<<Gauss(a)<<'\n';
        ans*=binaryPow(2,Gauss(a),mod);
        ans%=mod;
    }
    cout<<ans<<'\n';
    return 0;
}
