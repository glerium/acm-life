#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e7+5;
constexpr ll mod = 998244353;
constexpr ll inf = 1145141919810;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
vector<vector<int>> pfact;
bitset<maxn> isprime = {0};
vector<int> primes;
int v(ll p, ll x) {         // log
    int ret = 0;
    ll now = p;
    while(x / now) {
        ret += x / now;
        now *= p;
    }
    return ret;
}
int w(ll k, ll a, ll b) {   // log
    int ans1 = v(k, a), ans2 = v(k, b);
    if(ans1 != ans2) return min(ans1, ans2);
    else return inf;
}
int f(ll m, ll a, ll b) {
    
}
void solve() {
    int n,m; cin >> n >> m;
    int minx = n;
    while(!isprime[minx] && minx >= 1) minx--;
    rep(i,minx,n-1) {

    }
}
void init() {
    pfact.resize(maxn);
    isprime.set();
    isprime[1] = false;
    rep(i,2,1e7) {
        if(isprime[i]) {
            for(int j=i+i; j<=1e7; j+=i) {
                isprime[j] = false;
            }
            primes.push_back(i);
        }
    }
    cout << primes.size() << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}