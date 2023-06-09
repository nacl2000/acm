#include<bits/stdc++.h>
using namespace std;
int euler_phi(int n){//1-n与n互素的个数
    int m=(int) sqrt(n+0.5);
    int ans=n;
    for(int i=2;i<m;++i){
        if(n%i==0){
            ans=ans/i*(i-1);
            while(n%i==0){
                n/=i;
            }
        }
        if(n>1){
            ans=ans/n*(n-1);
        }
        return ans;
    }
}
void phi_table(int n,int *phi){
    for(int i=2;i<=n;++i){
        phi[i]=0;
    }
    phi[1]=1;
    for(int i=2;i<=n;++i){
        if(!phi[i]){
            for(int j=i;j<=n;j+=i){
                if(!phi[j]){
                    phi[j]=j;
                }
                phi[j]=phi[j]/i*(i-1);
            }
        }
    }
}
int main(){
    return 0;
}