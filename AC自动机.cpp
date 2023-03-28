#include <queue>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int max_n =  2*1e6+9;
const int max_m=2e6+10;
int trie[max_n][26]; //字典树
int cntword[max_n];  //记录该单词出现次数
int fail[max_n];     //失败时的回溯指针
int cnt = 0;
char str[max_m];
void insertWords(char s[]){
    int root = 0;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        int next = s[i] - 'a';
        if(!trie[root][next]){
            trie[root][next] = ++cnt;
            memset(trie[cnt],0,sizeof(trie[cnt]));
        }
        root = trie[root][next];
    }
    cntword[root]++;      //当前节点单词数+1
}
void getFail(){
    queue <int>q;
    for(int i=0;i<26;i++){      //将第二层所有出现了的字母扔进队列
        if(trie[0][i]){
            fail[trie[0][i]] = 0;
            q.push(trie[0][i]);
        }
    }
//fail[now]    ->当前节点now的失败指针指向的地方
//tire[now][i] -> 下一个字母为i+'a'的节点的下标为tire[now][i]
    while(!q.empty()){
        int now = q.front();
        q.pop();
        for(int i=0;i<26;i++){      //查询26个字母
            if(trie[now][i]){
                //如果有这个子节点为字母i+'a',则
//让这个节点的失败指针指向(((他父亲节点)的失败指针所指向的那个节点)的下一个节点)
                //有点绕,为了方便理解特意加了括号
                fail[trie[now][i]] = trie[fail[now]][i];
                q.push(trie[now][i]);
            }
            else//否则就让当前节点的这个子节点
                //指向当前节点fail指针的这个子节点
                trie[now][i] = trie[fail[now]][i];
        }
    }
}
int query(char s[]){
    int now = 0,ans = 0;
    int len=strlen(s);
    for(int i=0;i<len;i++){    //遍历文本串
        now = trie[now][s[i]-'a'];  //从s[i]点开始寻找
        for(int j=now;j && cntword[j]!=-1;j=fail[j]){
            //一直向下寻找,直到匹配失败(失败指针指向根或者当前节点已找过).
            ans += cntword[j];
            cntword[j] = -1;    //将遍历国后的节点标记,防止重复计算
        }
    }
    return ans;
}
void init(){
    fail[0]=0;
    memset(trie[0],0,sizeof(trie[0]));
    memset(cntword,0,sizeof(cntword));
    cnt=0;
}
int main() {
    return 0;
}