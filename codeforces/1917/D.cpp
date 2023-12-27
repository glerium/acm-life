#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=2e5+10;
constexpr ll mod=998244353;
int _,n,k,p[maxn],q[maxn];
int f1[maxn],f2[maxn];
constexpr int lowbit(int x) {return x&-x;}
void add1(int x) {
    while(x<=k) {
        f1[x]++;
        x+=lowbit(x);
    }
}
int query1(int x) {
    ll ans=0;
    while(x) {
        ans=(ans+f1[x])%mod;
        x-=lowbit(x);
    }
    return ans;
}
void add2(int x) {
    while(x<=n) {
        f2[x]++;
        x+=lowbit(x);
    }
}
int query2(int x) {
    ll ans=0;
    while(x) {
        ans=(ans+f2[x])%mod;
        x-=lowbit(x);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n>>k;
        rep(i,1,n) cin>>p[i];
        rep(i,1,k) cin>>q[i];
        rep(i,1,n) f1[i]=0;
        rep(i,1,k) f2[i]=0;
        ll ansin=0;
        rep(i,1,k) {
            ansin=(ansin+query1(k)-query1(q[i]))%mod;
            add1(q[i]);
        }
        ansin=ansin*n%mod;
        rep(i,1,n) {
            // loop through a[i]*(2^j)

            // loop through a[i]/(2^j)

            add2(p[i]);
        }
    }
    return 0;
}