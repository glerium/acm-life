#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=5e6+10;
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
        ans=(ans+f1[x]);
        x-=lowbit(x);
    }
    return ans;
}
void add2(int x) {
    while(x<=n*16+10) {
        f2[x]++;
        x+=lowbit(x);
    }
}
int query2(int x) {
    int y=x;
    int ans=0;
    while(x) {
        ans=(ans+f2[x]);
        x-=lowbit(x);
    }
    // printf("query2(%d)=%d\n",y,ans);
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n>>k;
        rep(i,1,n) cin>>p[i];
        rep(i,1,k) cin>>q[i];
        rep(i,1,max(k,n*16+10)) {
            f1[i]=f2[i]=0;
            q[i]++;
        }
        ll ans=0;
        rep(i,1,k) {
            ans=(ans+query1(k)-query1(q[i]))%mod;
            add1(q[i]);
        }
        ans=ans*n%mod;
        rep(i,1,n) {
            // ansout=(ansout+(query2(p[i]*2-1)-query2(p[i]/2))*k)%mod;
            // loop through a[i]*(2^j)
            ll ct=k-1;
            ll ima=0;
            for(ll j=p[i]*2;j<=n*16;j*=2) {
                ll tmp=query2(j)-query2(j/2);
                ima=(ima+ct*(ct+1)/2%mod*tmp)%mod;
                ct--;
                if(ct<=0) break;
            }
            // loop through a[i]/(2^j)
            ct=1;
            for(double j=p[i]/2.0;j*2>=1;j/=2) {
                ll tmp=query2(j*2)-query2(j);
                ima=(ima+((k-ct+1)*(k+ct)/2%mod+(ct-1)*k%mod)*tmp%mod)%mod;
                ct++;
                if(ct>k) ct=k;
            }
            add2(p[i]);
            ans=(ans+(1ll*(i-1)*k%mod*k%mod-ima%mod+mod))%mod;
        }
        cout<<ans%mod<<endl;
    }
    return 0;
}