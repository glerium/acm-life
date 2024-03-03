#include <bits/stdc++.h>
#define int long long
using namespace std;
constexpr int maxn=2e5+10;
int n,m,s,w[maxn],v[maxn],l[maxn],r[maxn],sum[maxn],sumct[maxn];
int calc(int x) {
    for(int i=1;i<=n;i++) {
        sum[i]=sum[i-1]+(w[i]>=x?v[i]:0);
        sumct[i]=sumct[i-1]+(w[i]>=x);
    }
    int ans = 0;
    for(int i=1;i<=m;i++) {
        int ct = sumct[r[i]]-sumct[l[i]-1],
            ss = sum[r[i]]-sum[l[i]-1];
        ans += ct * ss;
    }
    return ans;
}
bool check1(int x) {    //  less than s
    return calc(x) <= s;
}
bool check2(int x) {    // greater than s
    return calc(x) >= s;
}
signed main() {
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int i=1;i<=m;i++) cin>>l[i]>>r[i];
    // cout<<calc(4)<<endl;
    int l=0, r=1e12, mid, ans1, ans2;
    while(l<=r) {       // calc <= s: max(calc)
        mid = (l+r)/2;
        if(check1(mid)) {
            ans1 = mid;
            r = mid-1;
        }else l = mid+1;
    }
    l=0, r=1e12;
    while(l<=r) {
        mid = (l+r)/2;
        if(check2(mid)) {
            ans2 = mid;
            l = mid+1;
        }else r = mid-1;
    }
    // printf("%lld %lld %lld %lld\n", ans1, calc(ans1), ans2, calc(ans2));
    cout<<min(abs(calc(ans1)-s), abs(calc(ans2)-s))<<endl;
    return 0;
}