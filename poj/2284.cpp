#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;

struct Point{
    double x,y;
    Point(double x,double y):x(x),y(y){}
    Point()=default;
};
typedef Point Vector;

const double eps=1e-6;
int dcmp(double x) {return fabs(x)<eps?0:(x<0?-1:1);}
Vector operator+(const Vector& a,const Vector& b) {return Vector(a.x+b.x,a.y+b.y);}
Vector operator-(const Vector& a,const Vector& b) {return Vector(a.x-b.x,a.y-b.y);}
Vector operator*(const Vector& a,double p) {return Vector(a.x*p,a.y*p);}
bool operator<(const Vector& a,const Vector& b){return dcmp(a.x-b.x)==0?a.y<b.y:a.x<b.x;}
bool operator==(const Point& a,const Point& b) {return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
double Dot(Vector a,Vector b) {return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b) {return a.x*b.y-a.y*b.x;}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {       // 两线段交点，注意输入格式
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}
bool SegmentProperIntersection(Point a1,Point a2,Point b1,Point b2){    // 两线段规范相交
    double c1=Cross(a2-a1,b1-a1), c2=Cross(a2-a1,b2-a1),
           c3=Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
    return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(Point p, Point a1, Point a2) {                           // 点与线段规范相交
    return dcmp(Cross(a1-p,a2-p))==0 && dcmp(Dot(a1-p,a2-p))<0;
}

int _=50,n,ct;
Point p[50007],pt[100007];

int main() {
    ios::sync_with_stdio(false);
    rep(t,1,_) {
        cin>>n;
        if(!n) break;
        rep(i,1,n) cin>>p[i].x>>p[i].y, pt[i]=p[i];
        n--;                // 原始输入中的点有重复，实际点数是n-1
        int v=n,e=n,f;      // 点数、边数、面数
        ct=n;
        rep(i,1,n) {
            rep(j,1,i-1) {
                if(SegmentProperIntersection(p[i], p[i+1], p[j], p[j+1])) {
                    pt[++ct] = GetLineIntersection(p[i],p[i+1]-p[i],p[j],p[j+1]-p[j]);
                }
            }
        }
        sort(pt+1,pt+1+ct);
        v=unique(pt+1,pt+1+ct)-pt-1;
        rep(i,1,n){
            rep(j,1,v){
                if(OnSegment(pt[j],p[i],p[i+1])) e++;
            }
        }
        f=e-v+2;
        printf("Case %d: There are %d pieces.\n",t,f);
    }
    return 0;
}