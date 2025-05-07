#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
template<class T, class... Args> 
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
void solve() {
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    auto pal = Vec<int>(n+5, n+5, -1);
    function<bool(int,int)> check = [&](int l, int r) -> bool {
        if(pal[l][r] != -1)
            return pal[l][r];
        if(l == r) return pal[l][r] = true;
        else if(l + 1 == r) return pal[l][r] = (s[l] == s[r]);
        else if(s[l] != s[r]) return pal[l][r] = false;
        else return pal[l][r] = check(l+1, r-1);
    };
    vector<ll> f(n+5), sm(n+5);
    rep(i,1,n) {
        rep(j,i,n) {
            f[i] += check(i,j);
        }
    }
    for(int i=n;i>=1;i--) {
        sm[i] = sm[i+1] + f[i];
    }
    ll ans = 0;
    for(int a=1;a<=n;a++) {
        for(int b=a;b<=n;b++) {
            if(!pal[a][b]) continue;
            ans += sm[b+1];
        }
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}