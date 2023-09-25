#include <bits/stdc++.h>
using namespace std;
struct Point {
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
};
typedef Point Vector;
Vector operator+(Vector a,Vector b){return Point(a.x+b.x,a.y+b.y);}
Vector operator-(Vector a,Vector b){return Point(a.x-b.x,a.y-b.y);}
Vector operator*(Vector a,double p){return Point(a.x*p,a.y*p);}
Vector operator/(Vector a,double p){return Point(a.x/p,a.y/p);}
Vector Rotate(Vector v, double rad){
    return Vector(v.x*cos(rad)-v.y*sin(rad), v.x*sin(rad)+v.y*cos(rad));
}
double Dot(Vector A, Vector B) {return A.x*B.x+A.y*B.y;}
double Length(Vector A) {return sqrt(Dot(A,A));}
double Angle(Vector A, Vector B) {return acos(Dot(A,B)/Length(A)/Length(B));}
double Cross(Vector a, Vector b) {return a.x*b.y-a.y*b.x;}
Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}

int t,ax,ay,bx,by,cx,cy;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>ax>>ay>>bx>>by>>cx>>cy;
        Point a(ax,ay), b(bx,by), c(cx,cy);
        double rada=Angle(a-b,a-c),
               radb=Angle(b-a,b-c),
               radc=Angle(c-a,c-b);
        Point d(GetLineIntersection(b,Rotate(c-b,radb/3),c,Rotate(b-c,-radc/3))),
              e(GetLineIntersection(a,Rotate(c-a,-rada/3),c,Rotate(a-c,radc/3))),
              f(GetLineIntersection(a,Rotate(b-a,rada/3),b,Rotate(a-b,-radb/3)));
        printf("%.6lf %.6lf %.6lf %.6lf %.6lf %.6lf\n",d.x,d.y,e.x,e.y,f.x,f.y);
    }
    return 0;
}