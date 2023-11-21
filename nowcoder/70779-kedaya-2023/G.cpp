#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int maxn=1e6+10;
int n,m,k;
string s[maxn],t;
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    rep(i,1,n) cin>>s[i];
    cin>>t;
    int ans=0;
    rep(i,1,n) {
        int ct=0;
        rep(j,0,m-1) ct+=s[i][j]!=t[j];
        ans+=ct<=k;
    }
    cout<<ans;
}