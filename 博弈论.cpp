#include <bits/stdc++.h>
using namespace std;
bool Bash(int n, int m) {
    // 一堆n个物品，两个人轮流从中取出1~m个，最后取光者胜（不能继续取的人输）。
    if (n % (m + 1)) {
        return true;
    }
    return false;
}
bool Wythoff(int a, int b) {
    //有两堆各若干物品，两个人轮流从任意一堆中至少取出一个或者从两堆中取出同样多的物品，
    //规定每次至少取一个，至多不限，最后取光者胜。
    double r = (sqrt(5) + 1) / 2;
    int d = abs(a - b) * r;
    if (d != min(a, b)) {
        return true;
    }
    return false;
}
bool Fibonacci(int n) {
    //一堆石子有n个，两人轮流取，先取者第一次可以去任意多个，但是不能取完，
    //以后每次取的石子数不能超过上次取子数的2倍。取完者胜。
    int f[10000];
    f[0] = f[1] = 1;
    for (int i = 0; f[i - 1] < n; i++) {
        f[i] = f[i - 1] + f[i - 2];
        if (f[i] == n)
            return true;
    }
    return false;
}
bool Nimm(int n) {
    //  有n堆物品，两人轮流取，每次取某堆中不少于1个，最后取完者胜。
    int arr[10000];
    int res = 0;
    for (int i = 1; i <= n; i++)
        res ^= arr[i];
    if (res)
        return true;
    else
        return false;
}
int main() { return 0; }