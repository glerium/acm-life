#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e6+10;
int n;
string s[maxn],s2[maxn];
struct Trie{
    int nex[maxn][26], cnt, w[maxn];
    void insert(const string& s) {
        int p=0;
        for(auto i:s) {
            int c=i-'a';
            if(!nex[p][c]) nex[p][c]=++cnt;
            p=nex[p][c];
            w[p]++;
        }
    }
    ll find(const string& s) {
        int p=0;
        ll ans=0;
        for(auto i:s) {
            int c=i-'a';
            if(!nex[p][c]) return ans;
            p=nex[p][c];
            ans+=w[p];
        }
        return ans;
    }
}t,r;
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) cin>>s[i];
    rep(i,1,n) s2[i]=string(s[i].crbegin(),s[i].crend());
    rep(i,1,n) {
        t.insert(s[i]);
        r.insert(s2[i]);
    }
    ll ans=0;
    rep(i,1,n) ans+=s[i].size()*n*2;
    rep(i,1,n) {
        ans-=r.find(s[i]);
        ans-=t.find(s2[i]);
    }
    cout<<ans<<endl;
    return 0;
}