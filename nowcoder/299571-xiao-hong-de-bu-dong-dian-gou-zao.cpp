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
    int n,k; cin >> n >> k;
    int a[n];
    rep(i,0,n-1) a[i] = i + 1;
    do {
        int ct = 0;
        rep(i,0,n-1) {
            if(a[i] == i + 1)
                ct++;
        }
        if(ct == k) {
            rep(i,0,n-1) cout << a[i] << ' ';
            return;
        }
    } while(next_permutation(a, a+n));
    cout<<-1<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}