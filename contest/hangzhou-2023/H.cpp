/*
 * Filename: i:\code\cpp\codeforces\gym-104976-hangzhou-2023\H.cpp
 * Path: i:\code\cpp\codeforces\gym-104976-hangzhou-2023
 * Created Date: Thursday, October 3rd 2024, 3:20:49 pm
 * Author: 温泽林
 * 
 * Copyright (c) 2024  
 */

#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e5+10;
constexpr ll mod = 1e9+7;
ll jc[maxn];
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x * qpow(x, y-1) % mod;
    return qpow(x*x%mod, y/2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod-2) % mod;
}
void init() {
    jc[0] = 1;
    for(int i=1;i<=5e5;i++)
        jc[i] = jc[i-1] * i % mod;
}

void solve() {
    int n; cin >> n;
    int a[n+5]={}, b[n+5]={}, w[n+5]={};
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cin >> b[i];
    for(int i=1;i<=n;i++) cin >> w[i];

    ll ans[n+5];
    memset(ans, -1, sizeof(ans));
    for(int i=1;i<=n;i++) {
        if(b[i] == i)
            ans[i] = a[i];
        else if(a[i] < a[b[i]])
            ans[i] = (a[i] + w[i]) % mod;
        else if(a[i] > a[b[i]] + w[b[i]])
            ans[i] = a[i];
    }
    
    bool v[n+5] = {};
    int found = -1;
    function<void(int)> dfs = [&](int x) {
        v[x] = true;
        if(v[b[x]]) {
            found = b[x];
            return;
        }
        dfs(b[x]);
    };
    bool ring[n+5] = {};
    function<void(int)> dfs2 = [&](int x) {
        if(ring[x])
            return;
        ring[x] = true;
        dfs2(b[x]);
    };
    for(int i=1;i<=n;i++) {
        if(v[i]) continue;
        dfs(i);
        dfs2(found);
    }
    cout << ";";
    for(int i=1;i<=n;i++) {
        if(ring[i] && ring[b[i]] && a[i] >= a[b[i]])
            b[i] = -1;
        cout << b[i] << ' ';
    }
    cout << endl;
    int dep[n+5] = {};
    memset(v, 0, sizeof(v));
    function<void(int)> dfs3 = [&](int x) -> void {
        if(v[x]) return;
        v[x] = true;
        if(b[x] != -1) {
            dfs3(b[x]);
            dep[x] = dep[b[x]] + 1;
        }
    };
    for(int i=1;i<=n;i++) {
        if(!dep[i])
            dfs3(i);
    }
    for(int i=1;i<=n;i++) {
        printf("%d: %lld %d\n", i, ans[i], dep[i]);
        if(ans[i] != -1)
            continue;
        ans[i] = (a[i] + frac(w[i], jc[dep[i]])) % mod;
    }
    for(int i=1;i<=n;i++) {
        cout << ans[i] << ' ';
    }
    cout << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    init();
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
