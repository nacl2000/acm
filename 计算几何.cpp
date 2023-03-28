#include<iostream>
#include<cmath>
using namespace std;
double eps=1e-8;
struct vec{
    double x,y;
    vec(double _x=0,double _y=0){
        x=_x;
        y=_y;
    }
};
typedef vec point;
vec operator+ (vec a,vec b) {return vec(a.x+b.y,a.y+b.y);};
vec operator- (vec a,vec b) {return vec(a.x-b.y,a.y-b.y);};
vec operator* (vec a,double p) {return vec(a.x*p,a.y*p);};
vec operator/ (vec a,double p) {return vec(a.x/p,a.y/p);};
int d_cmp(double x){
    if(fabs(x)<=eps){
        return 0;
    }else if(x>0){
        return 1;
    }
    return -1;
}
double vec_len(vec v){
    return sqrt(v.x*v.x+v.y*v.y);
}
double dot(vec a,vec b){
    return a.x*b.x+a.y*b.y;
}
double cross(vec a,vec b){ 
    return a.x*b.y-b.x*a.y;
}
vec normal(vec a){
    double len=vec_len(a);
    return vec(-a.y/len,a.x/len);
}
double p_to_l(point a,point b,point c){
    vec v1=a-b;
    vec v2=c-b;
    return fabs(cross(v1,v2))/vec_len(v2);
}
double p_to_d(point a,point b,point c){
    if(d_cmp(dot(a-b,c-b))<0){
        return vec_len(a-b);
    }else if(d_cmp(dot(a-c,b-c))<0){
        return vec_len(a-c);
    }else{
        return p_to_l(a,b,c);
    }
}
bool d_is_intersect(point a,point b,point c,point d){
    if(d_cmp(cross(b-a,d-c))==0){
        if(d_cmp(cross(c-a,d-a))==0){
            return false;
        }else{
            if(d_cmp(a.x-b.x)==0){
                return d_cmp(max(a.y,b.y)-min(c.y,d.y))>=0
                ||d_cmp(max(c.y,d.y)-min(a.y,b.y))>=0;
            }
            return d_cmp(max(a.x,b.x)-min(c.x,d.x))>=0
            ||d_cmp(max(c.x,d.x)-min(a.x,b.x))>=0;
        }
    }else{
        int f1 = d_cmp(cross(b-a,c-a))*d_cmp(cross(b-a,d-a));
        int f2 = d_cmp(cross(d-c,a-c))*d_cmp(cross(d-c,b-c));
        if(f1<=0&&f2<=0){
            return true;
        }else{
            return false;
        }
    }
}
point intersect_l(point a,point b,point c,point d){
    vec v1=b-a,v2=d-c;
    vec u=c-a;
    return c+v2*(cross(u,v1)/cross(v1,v2));
}
double PolygonArea(point* p,int n)
{
    double area=0;
    for(int i=1;i<n-1;i++)
        area+=cross(p[i]-p[0],p[i+1]-p[0]);
    return area/2;
}
int main(){
    return 0;
}
