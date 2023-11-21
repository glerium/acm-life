#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int maxn=1e6+10;
int n,m,ct[maxn][30];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m>>s;
    rep(i,0,n-1) {
        rep(j,0,25) {
            ct[i][j]=ct[i-1][j]+(j+'a'==s[i]);
        }
    }
    rep(i,1,m) {
        int l,r; cin>>l>>r;
        l--, r--;
        int mx=-114514;
        rep(j,0,25) {
            mx=max(mx,ct[r][j]-ct[l-1][j]);
        }
        cout<<r-l+1-mx<<endl;
    }
    return 0;
}