#include<bits/stdc++.h>//最小球覆盖(模拟退火) 2018南京D - Country Meow 
using namespace std;
typedef long long ll;
const int max_n = 1e5 + 100;
const int mod = 1e9 + 7;
struct point{
    double x,y,z;
    point(double _x=0,double _y=0,double _z=0){
        x=_x;
        y=_y;
        z=_z;
    }
};
double dis(point a,point b){
    return sqrt(pow(a.x-b.x,2)+pow(a.y-b.y,2)+pow(a.z-b.z,2));
}
vector<point> v;
int n;
const double start_t=10000;
double T=10000;
const double p=0.98;
double eps=1e-6;
int main(){
    scanf("%d",&n);
    double x,y,z;
    v.push_back(point());
    for(int i=0;i<n;++i){
        scanf("%lf%lf%lf",&x,&y,&z);
        v.push_back(point(x,y,z));
    }
    point ans_p(0,0,0);
    double ma=1e9;
    int s;
    while(T>eps){
        s=1;
        for(int i=1;i<=n;++i){
            if(dis(ans_p,v[i])>dis(ans_p,v[s])){
                s=i;
            }
        }
        ma=min(ma,dis(ans_p,v[s]));
        ans_p.x+=(v[s].x-ans_p.x)*T/start_t;
        ans_p.y+=(v[s].y-ans_p.y)*T/start_t;
        ans_p.z+=(v[s].z-ans_p.z)*T/start_t;
        T*=p;
    }
    printf("%.8lf\n",ma);
    return 0;
}