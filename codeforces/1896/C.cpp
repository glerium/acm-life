#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int t,n,x,a[maxn],b[maxn];
int main() {
    cin>>t;
    while(t--) {
        cin>>n>>x;
        rep(i,1,n) cin>>a[i];
        rep(i,1,n) cin>>b[i];
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        int mi=0;
        rep(i,1,n) mi+=a[i]>b[i];
        int target=0;
        while(a[target]<=b[1]) target++;
        int mx=0;
        {
            int i=target,j;
            for(i=target,j=1;i<=n;i++,j++) mx+=a[i]>b[j];
            for(i=1;i<target;i++,j++) mx+=a[i]>b[j];
        }
        if(mi<=x&&x<=mx) {
            puts("YES");
            int l=0,r=target
        }else{
            puts("NO");
        }
    }
}