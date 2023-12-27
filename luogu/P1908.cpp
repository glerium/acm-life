#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=5e5+10;
int n,a[maxn],b[maxn],f[maxn];
map<int,int> mp;
int ct;
int lowbit(int x){
    return x&(-x);
}
void add(int x){
    while(x<=n) {
        f[x]++;
        x+=lowbit(x);
    }
}
int query(int x){
    int ans=0;
    while(x) {
        ans+=f[x];
        x-=lowbit(x);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) cin>>a[i];
    rep(i,1,n) b[i]=a[i];
    sort(b+1,b+1+n);
    rep(i,1,n) {
        if(!mp.count(b[i])) mp[b[i]]=++ct;
    }
    long long ans=0;
    rep(i,1,n) {
        ans+=i-1-query(mp[a[i]]);
        add(mp[a[i]]);
    }
    cout<<ans<<endl;
    return 0;
}