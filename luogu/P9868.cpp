#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=3e3+10;
int n,m;
char a[maxn][maxn],b[maxn][maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n) {
        cin>>(a[i]+1);
        strcpy(b[i]+1,a[i]+1);
        sort(a[i]+1,a[i]+1+m);
        sort(b[i]+1,b[i]+1+m,greater<char>());
    }
    string ans;
    rep(i,1,n) {
        bool ok=true;
        rep(j,1,n) {
            if(i==j) continue;
            if(strcmp(b[j]+1,a[i]+1)<=0) {
                ok=false;
                break;
            }
        }
        ans.push_back(ok?'1':'0');
    }
    cout<<ans<<endl;
    return 0;
}