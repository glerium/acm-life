#include <bits/stdc++.h>
using namespace std;
int fib[100];
int t, n, x, y;
struct Point {
    Point(int x,int y) :x(x),y(y) {}
    Point() = default;
    int x,y;
    bool operator<=(const Point& rhs)const{
        return x<=rhs.x&&y<=rhs.y;
    }
    Point operator+(const Point& rhs) {
        Point p(x+rhs.x, y+rhs.y);
        return p;
    }
    Point operator-(const Point& rhs) {
        Point p(x-rhs.x, y-rhs.y);
        return p;
    }
    bool operator!=(const Point& rhs) {
        return x!=rhs.x||y!=rhs.y;
    }
};
struct Rect {
    Rect(Point p1, Point p2) : p1(p1),p2(p2) {}
    Rect() = default;
    Point p1,p2;
    bool have(const Point& p)const{
        return p1<=p && p<=p2;
    }
    int sho(bool &heng) {
        if(p2.x-p1.x+1 > p2.y-p1.y+1){
            heng = false;
            return p2.y-p1.y+1;
        } else {
            heng = true;
            return p2.x-p1.x+1;
        }
    }
};
int main() {
    fib[0]=fib[1]=1;
    for(int i=2;i<50;i++) fib[i]=fib[i-1]+fib[i-2];
    cin>>t;
    while(t--){
        cin>>n>>x>>y;
        Point p(x,y);
        Rect rec(Point(1,1),Point(fib[n],fib[n+1]));
        while(rec.p1 != rec.p2) {
            // printf("::%d %d %d %d\n",rec.p1.x,rec.p1.y,rec.p2.x,rec.p2.y);
            bool heng;
            int sho = rec.sho(heng);
            Rect nw1,nw2;
            if(heng) {
                nw1=Rect(rec.p1, rec.p2-Point(0,sho));
                nw2=Rect(rec.p1+Point(0,sho), rec.p2);
            }else{
                nw1=Rect(rec.p1, rec.p2-Point(sho,0));
                nw2=Rect(rec.p1+Point(sho,0), rec.p2);
            }
            if(nw1.have(p))
                rec = nw1;
            else if(nw2.have(p))
                rec = nw2;
            else {
                cout << "NO" << endl;
                goto end;
            }
        }
        cout << "YES" << endl;
end:    ;
    }
    return 0;
}