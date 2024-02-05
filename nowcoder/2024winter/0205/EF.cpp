#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
constexpr int maxn=2e5+10;
int t,n,c[maxn];
vector<int> cs[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>c[i];
        rep(i,1,n) cs[i].clear();
        rep(i,1,n) cs[c[i]].push_back(i);
        int now=n,minc=n;
        rep(i,1,n) {
            if(cs[i].size())
                minc=min(minc,*(cs[i].rbegin()));
        }
        int ans=0;
        while(now) {
            // cout<<":"<<minc<<endl;
            ans++;
            set<int> aff;
            for(int i=minc;i<=now;i++) {
                aff.insert(c[i]);
            }
            now=minc-1;
            for(int i:aff) {
                auto res=lower_bound(cs[i].rbegin(), cs[i].rend(), now, greater<int>());
                if(res!=cs[i].rend()) minc=min(minc, *res);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}