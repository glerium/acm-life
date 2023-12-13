#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn=2e3+10;
int t,n,k;
ll a[maxn];
pair<int,int> fnd(ll target, int start) {
    int l=start+1, r=n, mid, ans1=0, ans2=0;
    while(l<=r) {
        mid=(l+r)/2;
        if(a[mid]-a[start]>=target) {
            ans1=mid;
            r=mid-1;
        }else l=mid+1;
    }
    l=start+1, r=n;
    while(l<=r) {
        mid=(l+r)/2;
        if(a[mid]-a[start]<target) {
            ans2=mid;
            l=mid+1;
        }else r=mid-1;
    }
    return make_pair(ans1,ans2);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>t;
    while(t--) {
        cin>>n>>k;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        if(k>=3) cout<<0<<endl;
        else if(k==2) {
            ll mi=LLONG_MAX;
            for(int i=1;i<=n;i++) mi=min(mi,a[i]);
            for(int i=1;i<n;i++) mi=min(mi,a[i+1]-a[i]);
            for(int i=1;i<=n;i++) {
                for(int j=1;j<=n;j++) {
                    auto tt=fnd(a[i],j);
                    int mid1=tt.first, mid2=tt.second;
                    if(mid1)
                    for(int k=max(1,mid1-1);k<=min(n,mid1+1);k++) {
                        if(k==j) continue;
                        mi=min(mi,abs(a[i]-(a[k]-a[j])));
                    }
                    if(mid2)
                    for(int k=max(1,mid2-1);k<=min(n,mid2+1);k++) {
                        if(k==j) continue;
                        mi=min(mi,abs(a[i]-(a[k]-a[j])));
                    }
                }
            }
            cout<<mi<<endl;
        }else{
            ll mi=LLONG_MAX;
            for(int i=1;i<=n;i++) mi=min(mi,a[i]);
            for(int i=1;i<n;i++) mi=min(mi,a[i+1]-a[i]);
            cout<<mi<<endl;
        }
    }
    return 0;
}