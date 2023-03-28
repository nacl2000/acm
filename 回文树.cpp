#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int max_n=1e6+100;
struct node{
	int len,fail,son[26],siz;
	node(){
		len=fail=0;
		for(int i=0;i<=25;i++)
			son[i]=0;
	}
};
node prt[max_n]; 
int n,last,len,num;
ll ans=1,k;
char s[max_n];
bool cmp(node x,node y){
	return x.len>y.len;
}
int getfail(int x){
	while(s[n-prt[x].len-1]!=s[n]) x=prt[x].fail;
	return x;
}
void extend(int x){
	int cur=getfail(last);
	if(!prt[cur].son[x]){
		int now=++num;
		prt[now].len=prt[cur].len+2;
		prt[now].fail=prt[getfail(prt[cur].fail)].son[x];
		prt[cur].son[x]=now;
	}
	prt[prt[cur].son[x]].siz++;
	last=prt[cur].son[x];
}
void init(){
    last=num=1,prt[1].len=-1;
	prt[0].fail=prt[1].fail=1;
}
int main(){
	scanf("%s",s);
    int len=strlen(s);
    init();
	for(n=0;n<len;n++) extend(s[n]-'a');
}