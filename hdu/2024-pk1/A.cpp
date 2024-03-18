#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6+10;
constexpr ll mod = 1e9+7;
int n,dep[maxn],fa[maxn],to[maxn];
bitset<maxn> vis,ok;
vector<int> vs,a[maxn];
ll p[maxn];
void add(int x,int y) {
    to[x] = y;
}

ll qpow(ll x,ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x*qpow(x,y-1)%mod;
    return qpow(x*x%mod, y/2);
}
ll frac(ll x,ll y) {
    return x*qpow(y,mod-2)%mod;
}

void dfs(int x) {
    dep[x] = dep[fa[x]] + 1;
    if(to[x] == fa[x]) return;
    if(!dep[to[x]]) {
        fa[to[x]] = x;
        dfs(to[x]);
    }else if(dep[to[x]] < dep[x]) {
        for(int j=x; ;j=fa[j]) {
            ok[j] = true;
            vs.push_back(j);
            if(j==to[x]) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++) {
        int tmp; cin>>tmp;
        add(i, tmp);
    }
    for(int i=1;i<=n;i++) cin>>p[i];
    // cout<<p[1]*p[2]%mod<<endl<<p[4]*p[5]%mod<<endl;
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        if(dep[i]) continue;
        vs.clear();
        if(to[to[i]] == i) {
            dep[i] = 1;
            dep[to[i]] = 2;
            ok[i] = ok[to[i]] = true;
            vs.push_back(i);
            vs.push_back(to[i]);
        }else{
            dfs(i);
        }
        if(vs.empty()) continue;
        // 统计强联通分量存在的情况
        ll pp = 1;
        for(auto j:vs) {
            ll pnow = (1 - p[j] + mod) % mod;
            pp = pp * pnow % mod;
        }
        ans += pp;

        int ctzero = 0;
        for(auto j:vs) ctzero += p[j]==0;
        if(ctzero >= 2) continue;

        // 环断开，每个点各自都为一个强联通分量
        ll mulp = 1;
        for(auto j:vs) {
            if(p[j] == 0) continue;
            mulp = mulp * (1 + mod - p[j]) % mod;
        }
        for(auto j:vs) {
            if(ctzero) {
                if(p[j] != 0) continue;
                ll pnow = mulp % mod;
                ans = (ans + 1 - pnow + mod) % mod;
            }else{
                ll pnow = ((1 - frac(mulp, (1 - p[j] + mod) % mod)) * (1 - p[j] + mod) + mod) % mod;
                ans = (ans + pnow) % mod;
            }
        }
        // ans ++;
        // ans --;
    }
    for(int i=1;i<=n;i++) {
        if(!ok[i])
            ans = ans + (1 - p[i] + mod) % mod;
    }
    cout << ans << endl;
    return 0;
}