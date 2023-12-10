#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e5+10;
constexpr int noans=1e9;
int t,n,a[maxn];
int check_asc() {
    int i=1;
    for(i=1;i<n;i++) {
        if(a[i]>a[i+1]) {
            break;
        }
    }
    if(i==n) return 0;
    if(a[n]>a[1]) return noans;
    int ii=i;
    i++;
    for(;i<n;i++) {
        if(a[i]>a[i+1]) return noans;
    }
    if(i!=n) return noans;
    return n-ii;
}
int check_desc() {
    int i=1;
    for(i=1;i<n;i++) {
        if(a[i]<a[i+1]) break;
    }
    if(i==n) return 0;
    if(a[n]<a[1]) return noans;
    int ii=i;
    i++;
    for(;i<n;i++) {
        if(a[i]<a[i+1]) return noans;
    }
    if(i!=n) return noans;
    return n-ii;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        int ans=1e9,aa=check_asc(),bb=check_desc()+1;
        ans=min(aa,bb);
        for(int l=1,r=n;l<r;l++,r--) swap(a[l],a[r]);
        ans=min(ans,min(check_asc()+1,check_desc()+2));
        if(ans!=int(1e9)) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
    return 0;
}