#include <bits/stdc++.h>
#define int long long
using namespace std;
stringstream ss;
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
struct Frac{
    int x,y;
    Frac(int x,int y):x(x),y(y){}
    Frac yf() {
        int tt=gcd(x,y);
        x/=tt, y/=tt;
        return *this;
    }
    Frac operator+(const Frac& rhs)const{
        Frac ret(x*rhs.y+y*rhs.x, y*rhs.y);
        ret.yf();
        return ret;
    }
    Frac operator-(const Frac& rhs)const{
        return *this+(-rhs);
    }
    Frac operator-()const{
        return Frac(-x,y).yf();
    }
};
signed main() {
    string str; cin>>str; ss<<str;
    Frac ans(0,1);
    int x,y;
    char ch,ch2;
    if(str[0]=='-') {
        ss>>ch>>x>>ch>>y;
        ans=-Frac(x,y);
    }else{
        ss>>x>>ch>>y;
        ans=Frac(x,y);
    }
    while(!ss.eof()) {
        ss>>ch>>x>>ch2>>y;
        Frac tmp(x,y);
        if(ch=='+') ans=ans+tmp;
        else ans=ans-tmp;
    }
    if(ans.x>0&&ans.y<0) ans.x=-ans.x, ans.y=-ans.y;
    else if(ans.x<0&&ans.y<0) ans.x=-ans.x, ans.y=-ans.y;
    if(ans.y==1) cout<<ans.x<<endl;
    else cout<<ans.x<<'/'<<ans.y<<endl;
    return 0;
}