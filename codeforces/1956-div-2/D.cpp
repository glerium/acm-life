#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5];
    for(int i=0;i<n;i++) cin>>a[i];
    int best, bestp = -1;
    for(int i=0;i<(1<<n);i++) {
        int ans = 0;
        for(int j=0;j<n;) {
            if(!(i&(1<<j))) {
                ans += a[j];
                j++;
            }
            else {
                int start = j;
                while(j < n && (i&(1<<j))) j++;
                ans += (j - start) * (j - start);
            }
        }
        if(ans > bestp) {
            bestp = ans;
            best = i;
        }
    }
    vector<array<int,2>> ans;
    auto operate = [&](int l, int r) {
        set<int> st;
        for(int i=l;i<=r;i++) st.insert(a[i]);
        int mex = 0;
        while(st.count(mex)) mex++;
        for(int i=l;i<=r;i++) a[i] = mex;
    };
    auto haszero = [&](int l, int r) -> bool {
        for(int i=l;i<=r;i++) if(a[i] == 0) return true;
        return false;
    };
    function<void(int,int)> transform = [&](int l, int r) {
        // cout << l << ' ' << r << endl;
        if(l == r) {
            ans.push_back({l, r});
            operate(l, r);
            if(a[l] == 0) {
                ans.push_back({l, r});
                operate(l, r);
            }
            return;
        }
        ans.push_back({l, r});
        if(haszero(l, r)) ans.push_back({l, r}), operate(l, r);
        operate(l, r);
        for(int i=r-1;i>=l;i--) transform(l, i);
        ans.push_back({l, r});
        operate(l, r);
    };
    // transform(0, 1);
    // return;
    for(int i=0;i<n;i++) {
        if(best&(1<<i)) {
            int start = i;
            while(i < n && (best&(1<<i))) i++;
            transform(start, i-1);
        }
    }
    cout << bestp << ' ' << ans.size() << endl;
    for(auto [x,y] : ans) cout << x+1 << ' ' << y+1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--) solve();
    return 0;
}
