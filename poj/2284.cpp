#include <bits/stdc++.h>
using namespace std;

struct Point{
    double x,y;
    Point(double x,double y):x(x),y(y){}
};
typedef Point Vector;

Vector operator+(const Vector& a,const Vector& b) {return Vector(a.x+b.x,a.y+b.y);}
Vector operator-(const Vector& a,const Vector& b) {return Vector(a.x-b.x,a.y-b.y);}
Vector operator*(const Vector& a,double p) {return Vector(a.x*p,a.y*p);}
const double eps=1e-10;
int dcmp(double x) {return fabs(x)<eps?0:(x<0?-1:1);}
bool operator==(const Point& a,const Point& b) {return dcmp(a.x-b.x)==0&&dcmp(a.y-b.y)==0;}
double Dot(Vector a,Vector b) {return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b) {return a.x*b.y-a.y*b.x;}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u=P-Q;
    double t=Cross(w,u)/Cross(v,w);
    return P+v*t;
}

bool OnSegment(Point p, Point a1, Point a2) {
    return dcmp(Cross(a1-p,a2-p))==0 && dcmp(Dot(a1-p,a2-p))<0;
}

int t=25,n;
Point p[507];

int main() {
    ios::sync_with_stdio(false);
    while(t--) {
        cin>>n;
        int v=0,e=0,f=0;

    }
}