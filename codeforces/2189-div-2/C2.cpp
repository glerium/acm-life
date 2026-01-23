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
    int v = 0;
    vector<int> a(n+5);
    a[n] = 1;
    v ^= 1;
    rep(i,2,n-1) {
        a[i] = i ^ 1;
        v ^= (i ^ 1);
    }
    rep(i,1,n) v ^= i;
    a[1] = v;
    bool ok = false;
    map<int,int> mp;
    rep(i,2,n) mp[a[i]]++;
    if(mp.count(a[1] ^ 1)) {
        ok = true;
    }
    rep(i,2,n-1) {
        mp[a[i]]--;
        if(!mp.count(a[1] ^ i) || !mp.count(a[i] ^ 1)) continue;
        if(mp[a[1] ^ i] >= 1 && mp[a[i] ^ 1] >= 1) {
            swap(a[1], a[i]);
            ok = true;
            break;
        }
        mp[a[i]]++;
    }
    if(!ok) {
        cout << -1 << endl;
    } else {
        rep(i,1,n) cout << a[i] << ' ';
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}