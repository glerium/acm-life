#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
constexpr int mod=10007;
int n,m,num[maxn],col[maxn];
struct Block{
    int i;
    int v;
};
struct SubColor{
    int n;
    vector<Block> b;
    int si;
    int sv;
};
map<int,SubColor> mp;
int subcolorfor(int color,int i) {
    if(i&1) return color;
    else return color+1e5+10;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n) cin>>num[i];
    rep(i,1,n) cin>>col[i];
    rep(i,1,n) num[i]%=10007;
    rep(i,1,n) {
        int subcolor = subcolorfor(col[i], i);
        if(!mp.count(subcolor)) {
            mp[subcolor]=SubColor();
            mp[subcolor].b.push_back({0,0});
        }
        mp[subcolor].b.push_back({i,num[i]});
    }
    ll ans=0;
    for(auto i:mp) {
        auto subcolor=i.second;
        subcolor.n = subcolor.b.size()-1;
        // cout<<subcolor.n<<endl;
        for(int j=1;j<=subcolor.n;j++) {
            subcolor.si+=subcolor.b[j].i;
            subcolor.sv+=subcolor.b[j].v;
        }
        for(int j=1;j<=subcolor.n;j++) {
            ans=(ans+subcolor.b[j].i*subcolor.b[j].v%mod*(subcolor.n-1))%mod;
            ans=(ans+subcolor.b[j].i*(subcolor.sv-subcolor.b[j].v)%mod)%mod;
        }
    }
    cout<<ans<<endl;
    return 0;
}