#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll p = 998244353;
ll n,m;
ll gcd(ll x,ll y){
    return !y?x:gcd(y,x%y);
}
struct Frac{
    ll x,y;
    Frac(int x,int y):x(x),y(y){}
    Frac() = default;
    Frac operator+(const Frac& rhs)const{
        ll nx = x*rhs.y + y*rhs.x;
        ll ny = y*rhs.y;
        ll tt = gcd(nx,ny);
        nx /= tt;
        ny /= tt;
        return Frac(nx,ny);
    }
    Frac operator*(const Frac& rhs)const{
        ll nx = x * rhs.x;
        ll ny = y * rhs.y;
        ll tt=gcd(nx,ny);
        nx/=tt;
        ny/=tt;
        return Frac(nx,ny);
    }
    Frac operator/(const int rhs)const{
        ll nx = x;
        ll ny = y * rhs;
        ll tt=gcd(nx,ny);
        nx/=tt;
        ny/=tt;
        return Frac(nx,ny);
    }
}f[100][100][100];
ll qpow(ll x,ll y){
    if(!y) return 1;
    if(y&1) return x*qpow(x,y-1)%p;
    return qpow(x*x%p,y/2);
}
Frac dp(ll x,ll y,ll z){
    cout<<x<<' '<<y<<' '<<z<<endl;
    if(f[x][y][z].x!=-1) return f[x][y][z];
    if(x<y) return f[x][y][z]=Frac(0,1);
    if(z<=0) return f[x][y][z]=Frac(1,1);
    return f[x][y][z]=dp(x+1,1,z-1)/2 + dp(x-y,y*2,x+z-(x-y))/2;
}
int main() {
    // cin>>n>>m;
    memset(f,-1,sizeof(f));
    for(int i=1;i<=10;i++) {
        for(int j=1;j<=10;j++){
            if(f[i][1][j].x==-1) {
                dp(i,1,j);
            }
            cout<<f[i][1][j].x<<'/'<<f[i][1][j].y<<'\t';
        }
        cout<<endl;
    }
    return 0;
}