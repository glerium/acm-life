#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
typedef long long ll;
using namespace std;
constexpr ll mod = 998244353;
constexpr int maxn = 1e7+10;
int n;
map<int,int> mp;
bitset<maxn> isprime;
vector<int> primes;
ll tmp[maxn];

ll qpow(ll x,ll y){
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return qpow(x,y-1)*x%mod;
    return qpow(x*x%mod,y/2);
}
ll frac(ll x,ll y) {
    return x * qpow(y, mod-2) % mod;
}
void init() {
    isprime.set();
    isprime[0] = isprime[1] = false;
    rep(i,2,n) {
        if(isprime[i]) {
            primes.push_back(i);
            for(int j=i+i;j<=1e7;j+=i) {
                isprime[j] = false;
            }
        }
    }

    rep(i,1,n) {
        if(i % 2 == 0 && i != 2) tmp[i] = tmp[i/2] * tmp[2] % mod;
        else if(i % 3 == 0 && i != 3) tmp[i] = tmp[i/3] * tmp[3] % mod;
        else if(i % 5 == 0 && i != 5) tmp[i] = tmp[i/5] * tmp[5] % mod;
        else if(i % 7 == 0 && i != 7) tmp[i] = tmp[i/7] * tmp[7] % mod;
        else if(i % 11 == 0 && i != 11) tmp[i] = tmp[i/11] * tmp[11] % mod;
        else if(i % 13 == 0 && i != 13) tmp[i] = tmp[i/13] * tmp[13] % mod;
        else if(i % 17 == 0 && i != 17) tmp[i] = tmp[i/17] * tmp[17] % mod;
        else if(i % 19 == 0 && i != 19) tmp[i] = tmp[i/19] * tmp[19] % mod;
        else tmp[i] = frac(1,i);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    init();
    for(int i=1;i<=n;i++) {
        if(!isprime[i]) continue;
        mp[i] = log2(n) / log2(i);
    }
    // for(int i=2;i<=n;i++) {
    //     if(tmp[i] != frac(i,n)) cout << i << ' ';
    // }
    // tmp[n] = 1;
    ll lcm = 1;
    for(auto [x,y] : mp) {
        lcm = lcm * qpow(x, y) % mod;
    }
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        ans = (ans + lcm * tmp[i] % mod * (n-2*i+1) % mod + mod) % mod;
    }
    cout << ans << endl;
}