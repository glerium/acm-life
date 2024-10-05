#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+10;
ll n,m,a[maxn];
ll gcd(ll x,ll y) {
    return !y?x:gcd(y,x%y);
}
pair<ll,ll> exgcd(ll a,ll b){
    if(!b) return {1,0};
    ll u,v;
    tie(u,v) = exgcd(b,a%b);
    return {v, u-(a/b)*v};
}
int main() {
    cin>>n>>m;
    ll sum=0;
    for(int i=1,tt;i<=n;i++) {
        cin>>tt;
        sum=(sum+tt)%m;
    }
    ll t=gcd(gcd(n,n*(n+1)/2),m);
    cout<<(sum%t)<<endl;
    
    ll a=gcd(n,n*(n+1)/2),b=m;
    __int128 k=exgcd(a,b).first*((sum%t-sum+m)%m)/gcd(a,b);
    __int128 s,d; 
    auto tmp=exgcd(n,n*(n+1)/2);
    s=tmp.first;
    d=tmp.second;
    s*=k, d*=k;
    s=(s%m+m)%m;
    d=(d%m+m)%m;
    long long ss=s,dd=d;
    cout<<ss<<' '<<dd<<endl;
    return 0;
}