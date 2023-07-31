#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,k,a[maxn],ct[5][maxn];
bool check(int x) {
    for(int l=1,r=x;r<=n;l++,r++) {
        if( ct[1][r]-ct[1][l-1]>=1&&
            ct[2][r]-ct[2][l-1]>=1&&
            ct[3][r]-ct[3][l-1]>=1&&
            ct[4][r]-ct[4][l-1]>=k
        ) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=4;j++) {
            if(a[i]==j) ct[j][i]=ct[j][i-1]+1;
            else ct[j][i]=ct[j][i-1];
        }
    }
    int l=1,r=n,mid,ans;
    while(l<=r) {
        mid=l+r>>1;
        if(check(mid)) {
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}