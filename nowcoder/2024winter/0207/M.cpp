#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
int t,n;
ll a[maxn];
vector<ll> v[10],v2[10][10];
int getsum(int x) {
    int s=0; while(x) {s+=x%10; x/=10;} return s;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        if(a[i]>=10) {
            v[getsum(a[i])%9].push_back(a[i]);
        }
    }
    ll ans=0;
    for(int i=0;i<=9;i++) {
        for(auto j:v[i]) {
            if(j%4==0) {
                ans+=v[9-i].size();
            }
        }
    }
    for(int i=1;i<=n;i++) {
        v2[getsum(a[i])%9][a[i]%10].push_back(a[i]);
    }
    for(int i=1;i<=n;i++) {
        if(a[i]>=10) continue;
        for(int j=0;j<=9;j++) {
            if((j*10+a[i])%4!=0) continue;
            ans+=v2[9-getsum(a[i])%9][j].size();
        }
    }
    cout<<ans<<endl;
    return 0;
}