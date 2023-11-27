#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e5+10;
int t,n,a[maxn];
long long f[maxn];
vector<int> v[maxn];
void process(int idx) {
    const int x=a[idx];
    int s=sqrt(x);
    rep(i,1,s) {
        if(x%i==0) {
            v[i].push_back(idx);
            if(i*i!=x) v[x/i].push_back(idx);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        int m=0;
        rep(i,1,n) m=max(m,a[i]);
        sort(a+1,a+1+n);
        rep(i,1,m) v[i].clear();
        rep(i,1,m) f[i]=0;
        rep(i,1,n) process(i);
        long long ans=0;
        for(int i=m;i>=1;i--) {
            for(int j=0;j<v[i].size();j++) {
                int ct1=j, ct2=n-v[i][j];
                f[i]+=1ll*ct1*ct2;
            }
            for(int j=(i<<1);j<=m;j+=i) f[i]-=f[j];
            ans+=1ll*f[i]*i;
            // printf("f[%d]=%d\n",i,f[i]);
        }
        cout<<ans<<endl;
    }
    return 0;
}