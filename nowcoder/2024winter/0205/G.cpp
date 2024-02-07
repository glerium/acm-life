#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr int maxn=5e5+10;
int t,n,q;
ll a[maxn],f[maxn];
int lowbit(int x) {return x&-x;}
void modify(int pos,int x) {
    while(pos<=n) {
        f[pos]+=x;
        pos+=lowbit(pos);
    }
}
ll _query(int x) {
    ll ans=0;
    while(x) {
        ans+=f[x];
        x-=lowbit(x);
    }
    return ans;
}
ll query(int l,int r) {
    return _query(r)-_query(l-1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>t;
    while(t--) {
        cin>>n>>q;
        for(int i=0;i<=n;i++) f[i]=0;
        for(int i=1;i<=n;i++) {
            cin>>a[i];
            modify(i,a[i]);
        }
//         cout<<":"<<_query(n)<<endl;
        while(q--) {
            int op,x,y; cin>>op>>x>>y;
            if(op==1) {
                modify(x,y-a[x]);
                a[x]=y;
            }
            else {
                ll ans=-0x3f3f3f3f3f3f3f3f;
                for(int l=x,r=max(y-5,x+1);r<=y;r++) {
//                     cout<<l<<' '<<r<<endl;
                    ans=max(ans,query(l,r-1)-a[r]);
                }
                cout<<ans<<endl;
            }
        }
    }
}