#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr double eps=1e-9;
int n;
struct Point {
    double x,y,z;
    Point()=default;
    Point(double x,double y,double z):x(x),y(y),z(z){}
    double len();
    Point operator+(const Point& rhs)const{return Point(x+rhs.x,y+rhs.y,z+rhs.z);}
    Point operator-(const Point& rhs)const{return Point(x-rhs.x,y-rhs.y,z-rhs.z);}
    Point operator/(const double k)const{return Point(x/k,y/k,z/k);}
}a[60];
using Vector=Point;
double Dot(Point a,Point b){
    return a.x*b.x+a.y*b.y+a.z*b.z;
}
double Point::len() {return sqrt(Dot(*this,*this));}
Vector Cross(Point a,Point b){
    return Vector(a.y*b.z-a.z*b.y, a.z*b.x-b.z*a.x, a.x*b.y-a.y*b.x);
}
int dcmp(double x){
    if(abs(x)<eps) return 0;
    return x<0?-1:1;
}
double DistanceToPlane(Point p, Point p0, Vector n) {
    return Dot(p-p0, n);
}
int main() {
    cin>>n;
    rep(i,1,n) cin>>a[i].x>>a[i].y>>a[i].z;
    double ans=INFINITY;
    if(n<=3) {
        cout<<0<<endl;
        return 0;
    }
    rep(i,1,n) {
        rep(j,i+1,n) {
            rep(k,1,n) {
                rep(l,k+1,n) {
                    Vector vec=Cross(a[i]-a[j],a[k]-a[l]);
                    if(dcmp(vec.len())==0) continue;
                    Vector nn=vec/vec.len();
                    double minn=INFINITY, maxx=-INFINITY;
                    rep(p,1,n) {
                        double dis=DistanceToPlane(a[p],a[1],nn);
                        minn=min(minn,dis);
                        maxx=max(maxx,dis);
                    }
                    ans=min(ans,maxx-minn);
                }
            }
        }
    }
    if(ans==INFINITY) ans=0;
    cout<<fixed<<setprecision(12)<<ans<<endl;
    return 0;
}