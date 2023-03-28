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
const int max_n = 2e5 + 10;
typedef vector<int> vec;
typedef vector<vec> mat;
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); ++i) {
        for (int k = 0; k < B.size(); ++k) {
            if (A[i][k]) {
                for (int j = 0; j < B[0].size(); ++j) {
                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
                }
            }
        }
    }
    return C;
}
mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); ++i) {
        B[i][i] = 1;
    }
    while (n > 0) {
        if (n & 1) {
            B = mul(B, A);
        }
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int main() { 
    //没要取模记得删掉
    return 0; 
}