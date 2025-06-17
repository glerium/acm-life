#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n; cin >> n;
    vector<int> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    vector<int> smx(n+5), pmn(n+5);
    smx[n] = n, pmn[1] = 1;
    for(int i=n-1;i>=1;i--) {
        smx[i] = smx[i+1];
        if(a[i] > a[smx[i]]) {
            smx[i] = i;
        }
    }
    rep(i,2,n) {
        pmn[i] = pmn[i-1];
        if(a[i] < a[pmn[i]]) {
            pmn[i] = i;
        }
    }
    auto calc = [&]() {
        int x = 1, y = 1, ct = 0, score = 0;
        while(ct < n) {
            if(a[x] < b[y]) {
                y++;
            } else {
                x++;
                score++;
            }
            ct++;
        }
        return score;
    };
    int l = calc(), r = n, mid, ans = l;
    while(l <= r) {
        int mid = l + r >> 1;
        swap(a[pmn[mid]], a[smx[mid+1]]);
        // cout << mid << ' ' << pmn[mid] << ' ' << smx[mid+1] << endl;
        if(calc() >= mid) {
            l = mid + 1;
            ans = mid;
        } else {
            r = mid - 1;
        }
        swap(a[pmn[mid]], a[smx[mid+1]]);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
