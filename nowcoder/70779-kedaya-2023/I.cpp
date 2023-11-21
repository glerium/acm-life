#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=100;
int n;
int main() {
    cin>>n;
    rep(i,1,n) {
        ll l1,r1,l2,r2; cin>>l1>>r1>>l2>>r2;
        if(l1+r1>l2+r2) puts("Nitori Win");
        else if(l1+r1<l2+r2) puts("Takane Win");
        else puts("Draw");
    }
}