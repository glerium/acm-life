#include <bits/stdc++.h>
using namespace std;

constexpr double eps=1e-10;
int dcmp(double x){
    if(abs(x)<eps) return 0;
    return x<0?-1:1;
}
struct Point{
    double x,y;
    Point(double x,double y):x(x),y(y){};
    Point()=default;
    Point operator+(const Point& rhs)const{return Point(x+rhs.x,y+rhs.y);}
    Point operator-(const Point& rhs)const{return Point(x-rhs.x,y-rhs.y);}
    Point operator*(const double k)const{return Point(x*k,y*k);}
    Point operator/(const double k)const{return Point(x/k,y/k);}
    bool operator==(const Point& rhs)const{return dcmp(x-rhs.x)==0&&dcmp(y-rhs.y)==0;}
};
ostream& operator<<(ostream& os, Point p){
    os<<"("<<p.x<<','<<p.y<<")";
    return os;
}
typedef Point Vector;
double Dot(Vector a,Vector b){return a.x*b.x+a.y*b.y;}
double Cross(Vector a,Vector b){return a.x*b.y-a.y*b.x;}
double Length(Vector a){return sqrt(Dot(a,a));}
double DistanceToSegment(Point p,Point a,Point b) {
    if(a==b) return Length(p-a);
    Vector v1=b-a,v2=p-a,v3=p-b;
    if(dcmp(Dot(v1,v2)<0)) return Length(v2);
    else if(dcmp(Dot(v1,v3))>0) return Length(v3);
    else return abs(Cross(v1,v2))/Length(v1);
}

constexpr int maxn=507;
int _,n,m,ct;
Point a[maxn],b[maxn];
double t[maxn],Max=-1,Min=1e10;

void UpdateAns(Point p,Point a,Point b){
    Min=min(Min,DistanceToSegment(p,a,b));
    Max=max(Max,Length(p-a));
    Max=max(Max,Length(p-b));
}

int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    for(int T=1;T<=_;T++) {
        cin>>n>>m;
        double lena=0,lenb=0;
        ct=0;
        Max=-1,Min=1e10;
        for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y;
        for(int i=1;i<=m;i++) cin>>b[i].x>>b[i].y;
        for(int i=1;i<=n-1;i++) lena+=Length(a[i+1]-a[i]);
        for(int i=1;i<=m-1;i++) lenb+=Length(b[i+1]-b[i]);
        const double sa=lena,sb=lenb;
        {
            double ta=0,tb=0;
            for(int i=1;i<=n-1;i++) t[++ct]=(ta+=Length(a[i+1]-a[i])/sa);
            for(int i=1;i<=m-1;i++) t[++ct]=(tb+=Length(b[i+1]-b[i])/sb);
        }
        t[++ct]=1;
        sort(t+1,t+1+ct);
        ct=unique(t+1,t+1+ct)-t-1;
        Point lasta=a[1],lastb=b[1];
        int linea=1,lineb=1;      // 1 .. n-1: count of lines
        for(int i=1;i<=ct;i++) {
            const double deltat = t[i]-t[i-1];
            double la=Length(a[linea+1]-a[linea]),
                   lb=Length(b[lineb+1]-b[lineb]);
            Vector deltaA = (a[linea+1]-a[linea])/la*sa*deltat,
                   deltaB = (b[lineb+1]-b[lineb])/lb*sb*deltat;
            Point nowa=lasta+deltaA, nowb=lastb+deltaB;
            Point lastM=lastb-lasta,nowM=nowb-nowa;
            UpdateAns(Point(),lastM,nowM);
            lasta=nowa,lastb=nowb;
            if(nowa==a[linea+1]) linea++;
            if(nowb==b[lineb+1]) lineb++;
        }
        printf("Case %d: %.0lf\n",T,Max-Min);
    }
    return 0;
}