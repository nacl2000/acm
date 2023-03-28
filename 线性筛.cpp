#include<bits/stdc++.h>
using namespace std;
const int max_n=1e5+10;
int vis[max_n];
int pn = 0;
vector<int> prime;
void isprime(){
    for(int i = 2;i < max_n;i++){
        if(!vis[i]){
            prime.push_back(i);
        }
        for(int j = 0;j < prime.size() && i*prime[j] < max_n;j++){
            vis[i*prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}
int main(){
    
    return 0;
}