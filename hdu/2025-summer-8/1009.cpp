#include <bits/stdc++.h>
// #define __int128 long long
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
__int128 input() {
    ll x; cin >> x;
    return x;
}
void print(__int128 x) {
    if(x < 10) {
        putchar('0' + x);
        return;
    }
    print(x / 10);
    putchar(x % 10 + '0');
}
__int128 sum(__int128 x) {
    return x * (x + 1) / 2;
}
__int128 sum2(__int128 x) {
    return x * (x + 1) * (2 * x + 1) / 6;
}
void solve() {
    __int128 n,k;
    n = input(); k = input();
    auto n_ = n;
    // if(k == 1) {
    //     print(n * (n + 1) / 2);
    //     putchar('\n');
    //     return;
    // }
    __int128 ct = 1;
    __int128 ans = 0;
    __int128 s = 1;
    while(n >= k) {
        __int128 b = n / k;
        __int128 c = (n - k * b + b) / b;
        ans += ((ct * 2 * b + (2 * s + b - 1)) * sum(c - 1) + 2 * b * sum2(c - 1) + ct * (2 * s + b - 1) * c) * b / 2;

        n -= c * b;
        s += c * b;
        ct += c;
    }
    ans += (s + n_) * (n_ - s + 1) * ct / 2;

    print(ans);
    putchar('\n');
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = input();
    while(t--) solve();
    return 0;
}