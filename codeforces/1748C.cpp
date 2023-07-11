#include <bits/stdc++.h>
#define int ll
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int t,n;
ll a[maxn];
signed main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        bool zero = false;
        ll s = 0;
        map<int,int> cnt;
        for(int i=1;i<=n;i++) {
            if(a[i]==0) {
                int maxCnt = 0;
                for(auto j : cnt) {
                    if(j.second > maxCnt) {
                        maxCnt = j.second;
                    }
                }
                if(zero) ans += maxCnt;
                else ans += cnt[0];
                cnt.clear();
                zero = true;
            }
            s += a[i];
            cnt[s]++;
        }
        int maxCnt = 0;
        for(auto j : cnt) {
            if(j.second > maxCnt) {
                maxCnt = j.second;
            }
        }
        if(zero) ans += maxCnt;
        else ans += cnt[0];
        cout<<ans<<endl;
    }
    return 0;
}