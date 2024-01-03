#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int _,a,b;
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>a>>b;
        if(b%a!=0) cout<<1ll*a*b/gcd(a,b)<<endl;
        else cout<<1ll*b*b/a<<endl;
    }
    return 0;
}