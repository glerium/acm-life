#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int n;
int f[maxn][maxn];      // 0:equal, 1:less, 2:greater
char s[maxn];
int dp(int x, int y) {
    if(f[x][y]!=-1) return f[x][y];
    if(x==y) return 0;
    if(y-x==1) {
        if(s[x]==s[y]) return f[x][y]=0;
        else if(s[x]>s[y]) return f[x][y]=1;
        else return f[x][y]=2;
    }
    if(s[x]==s[y]) return f[x][y]=dp(x+1,y-1);
    else if(s[x]<s[y]) return f[x][y]=2;
    else return f[x][y]=1;
}
int main() {
    cin>>s+1;
    n=strlen(s+1);
    int ans=0;
    memset(f,-1,sizeof(f));
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            ans += dp(i,j)==1;
            // printf("%d %d %d\n",i,j,dp(i,j));
        }
    }
    cout<<ans<<endl;
}