#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
constexpr ll base=233;
constexpr ll mod=998244853;
constexpr int maxn=1e5+10;
int n,m;
ll hs1[maxn],hs2[maxn],ht1[maxn],ht2[maxn],b[maxn];
string s,t;
vector<int> ok1,ok2;
void init_base() {
    b[0]=1;
    for(int i=1;i<=n;i++) b[i]=b[i-1]*base%mod;
}
void init_hash(ll *hs, ll *ht, const string& s) {
    hs[0]=0;
    for(int i=1;i<s.size();i++)
        hs[i]=(hs[i-1]*base%mod+s[i])%mod;
    string t(s.rbegin(), --s.rend());
    t=' '+t;
    ht[0]=0;
    for(int i=1;i<t.size();i++)
        ht[i]=(ht[i-1]*base%mod+t[i])%mod;
}
ll hsh(ll *hs,int l,int r){
    return (hs[r]-hs[l-1]*b[r-l+1]%mod+mod)%mod;
}
bool check(ll *hs1, ll *ht1, ll *ht2, int x, int n, int m) {
    // cout<<x<<' '<<hsh(hs1,1,x)<<' '<<hsh(ht2,1,x)<<' '<<hsh(ht1,n-x+1,n)<<endl;
    if(hsh(hs1,1,x)==hsh(ht2,1,x)&&
       hsh(hs1,1,x)==hsh(ht1,n-x+1,n)) return true;
    else return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m>>s>>t;
    s=' '+s;
    t=' '+t;
    init_base();
    init_hash(hs1,ht1,s);
    init_hash(hs2,ht2,t);
    for(int i=1;i<=min(n,m)-1;i++) {
        if(check(hs1,ht1,ht2,i,n,m)) {
            ok1.push_back(i);
        }
        if(check(hs2,ht2,ht1,i,m,n)) {
            ok2.push_back(i);
        }
    }
    int ans=-1;
    for(int l:ok1) {
        auto tmp=lower_bound(ok2.rbegin(),ok2.rend(),min(n,m)-l,greater<int>());
        if(tmp!=ok2.rend()) ans=max(ans,(*tmp+l)*2);
    }
    cout<<ans<<endl;
    return 0;
}