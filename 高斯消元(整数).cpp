#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string.h>
using namespace std;
const int max_n = 50;
int a[max_n][max_n]; //增广矩阵
int x[max_n];        //解集
bool free_x[max_n];  //标记是否是不确定的变元
int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
inline int lcm(int a, int b) {
    return a / gcd(a, b) * b; //先除后乘防溢出
}
// 高斯消元法解方程组(Gauss-Jordan elimination).(-2表示有浮点数解，但无整数解，
//-1表示无解，0表示唯一解，大于0表示无穷解，并返回自由变元的个数)
//有equ个方程，var个变元。增广矩阵行数为equ,分别为0到equ-1,列数为var+1,分别为0到var.
int Gauss(int equ, int var) {
    int i, j, k;
    int max_r; // 当前这列绝对值最大的行.
    int col;   //当前处理的列
    int ta, tb;
    int LCM;
    int temp;
    int free_x_num;
    int free_index;
    for (int i = 0; i <= var; i++) {
        x[i] = 0;
        free_x[i] = true;
    }
    col = 0;
    for (k = 0; k < equ && col < var; k++, col++) {
        max_r = k;
        for (i = k + 1; i < equ; i++) {
            if (abs(a[i][col]) > abs(a[max_r][col]))
                max_r = i;
        }
        if (max_r != k) { // 与第k行交换.
            for (j = k; j < var + 1; j++)
                swap(a[k][j], a[max_r][j]);
        }
        if (a[k][col] == 0) {
            k--;
            continue;
        }
        for (i = k + 1; i < equ; i++) {
            if (a[i][col] != 0) {
                LCM = lcm(abs(a[i][col]), abs(a[k][col]));
                ta = LCM / abs(a[i][col]);
                tb = LCM / abs(a[k][col]);
                if (a[i][col] * a[k][col] < 0)
                    tb = -tb; //异号的情况是相加
                for (j = col; j < var + 1; j++) {
                    a[i][j] = a[i][j] * ta - a[k][j] * tb;
                }
            }
        }
    }
    for (i = k; i < equ; i++) {
        if (a[i][col] != 0)
            return -1;
    }
    if (k < var) {
        return var - k;
    }
    for (i = var - 1; i >= 0; i--) {
        temp = a[i][var];
        for (j = i + 1; j < var; j++) {
            if (a[i][j] != 0)
                temp -= a[i][j] * x[j];
        }
        if (temp % a[i][i] != 0)
            return -2; // 说明有浮点数解，但无整数解.
        x[i] = temp / a[i][i];
    }
    return 0;
}
int main(void) {
    //    freopen("in.txt", "r", stdin);
    //    freopen("out.txt","w",stdout);
    int i, j;
    int equ, var;
    while (scanf("%d %d", &equ, &var) != EOF) {
        memset(a, 0, sizeof(a));
        for (i = 0; i < equ; i++) {
            for (j = 0; j < var + 1; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        int free_num = Gauss(equ, var);
        if (free_num == -1)
            printf("无解!\n");
        else if (free_num == -2)
            printf("有浮点数解，无整数解!\n");
        else if (free_num > 0) {
            printf("无穷多解! 自由变元个数为%d\n", free_num);
            for (i = 0; i < var; i++) {
                if (free_x[i])
                    printf("x%d 是不确定的\n", i + 1);
                else
                    printf("x%d: %d\n", i + 1, x[i]);
            }
        } else {
            for (i = 0; i < var; i++) {
                printf("x%d: %d\n", i + 1, x[i]);
            }
        }
        printf("\n");
    }
    return 0;
}