#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
int t,n;
ll a[maxn],b[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++) cin>>b[i];
        multiset<ll> rem, sel;
        for(int i=1;i<=n;i++) rem.insert(a[i]);
        ll ans = *(--rem.end());
        int ansc = 1;
        sel.insert(*(--rem.end()));
        rem.erase(--rem.end());
        for(int i=2;i<=n;i++) {
            auto it = rem.find(a[b[i-1]]);
            if(it!=rem.end()) {
                rem.erase(it);
            }else{
                auto itt = sel.find(a[b[i-1]]);
                sel.erase(itt);
                sel.insert(*(--rem.end()));
                rem.erase(--rem.end());
            }
            if(rem.empty()) {
                break;
            }
            sel.insert(*(--rem.end()));
            rem.erase(--rem.end());
            if(ans < i**sel.begin()) {
                ans = i**sel.begin();
                ansc = i;
            }
            if(rem.empty()) {
                break;
            }
        }
        cout << ans << ' ' << ansc << endl;
    }
    return 0;
}