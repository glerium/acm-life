#include <bits/stdc++.h>
using namespace std;
const double eps=1e-10;
int dcmp(double x) {
    if(abs(x)<eps) return 0;
    return x>0?1:-1;
}
struct Point{
    double x,y;
    Point(double x,double y):x(x),y(y){}
    Point()=default;
    bool operator==(const Point& rhs) {return dcmp(x-rhs.x)==0&&dcmp(y-rhs.y)==0;}
};
typedef Point Vector;
Vector operator+(Point a,Vector b) {return Vector(a.x+b.x,a.y+b.y);}
Vector operator-(Point a,Vector b) {return Vector(a.x-b.x,a.y-b.y);}
double Dot(Vector a, Vector b) {return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b) {return a.x*b.y-a.y*b.x;}
double Length(Vector a) {return sqrt(Dot(a,a));}
bool OnSegment(Point a,Point b,Point p) {
    return dcmp(Cross(p-a,p-b))==0&&dcmp(Dot(p-a,p-b))<0;
}
double Angle(Vector a,Vector b) {
    return acos(Dot(a,b)/Length(a)/Length(b));
}

Point a,b,c,p;
Point read_point() {
    int x,y;
    scanf(" (%d,%d)",&x,&y);
    return Point(x,y);
}
int main() {
    a=read_point();
    b=read_point();
    c=read_point();
    p=read_point();
    if(p==a||p==b||p==c) puts("4");
    else if(OnSegment(a,b,p)||OnSegment(a,c,p)||OnSegment(b,c,p)) puts("3");
    else {
        double anglesum = Angle(p-a,p-b) + Angle(p-a,p-c) + Angle(p-b,p-c);
        double pi = asin(1)*2;
        if(dcmp(anglesum-pi*2)==0) puts("1");
        else puts("2");
    }
    return 0;
}