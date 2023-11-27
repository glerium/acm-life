#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=6e5+10;
int t,n,l[maxn],r[maxn],f[maxn];
char s[maxn];
int dfs(int x) {
    if(!l[x]&&!r[x]) return f[x]=0;
    if(l[x]) f[x]=min(f[x],dfs(l[x])+(s[x]!='L'));
    if(r[x]) f[x]=min(f[x],dfs(r[x])+(s[x]!='R'));
    return f[x];
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>(s+1);
        rep(i,1,n) cin>>l[i]>>r[i];
        rep(i,1,n) f[i]=0x3f3f3f3f;
        cout<<dfs(1)<<endl;        
    }
    return 0;
}