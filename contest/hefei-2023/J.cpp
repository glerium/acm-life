#include <bits/stdc++.h>

using namespace std;

#define rep(i, o, p) for(ll i = o; i <= p; i ++ )

const int M = 1e6 + 10, N = 3e5 + 10;

#define ll long long 

ll n, m;

const ll INF = 1e16;

ll u[M], v[M], w[M];

vector < pair<ll, ll> > ed[N];

ll d1[N], d2[N];

void dij1(ll s){
    rep(i, 1, n) d1[i] = INF;
    d1[s] = 0;
    priority_queue <pair<ll, ll> > q;
    q.push(make_pair(0, s));
    while(!q.empty()){
        pair<ll, ll> now = q.top(); q.pop();
        ll d = - now.first, u = now.second;
        if(d != d1[u]) continue;
        rep(i, 0, ed[u].size() - 1){
            ll w = ed[u][i].first, v = ed[u][i].second;
            if(max(d1[u], w) < d1[v]){
                d1[v] = max(d1[u], w);
                q.push(make_pair(- d1[v], v));
            }
        }
    } 
}

void dij2(ll s){
    rep(i, 1, n) d2[i] = INF;
    d2[s] = 0;
    priority_queue <pair<ll, ll> > q;
    q.push(make_pair(0, s));
    while(!q.empty()){
        pair<ll, ll> now = q.top(); q.pop();
        ll d = - now.first, u = now.second;
        if(d != d2[u]) continue;
        rep(i, 0, ed[u].size() - 1){
            ll w = ed[u][i].first, v = ed[u][i].second;
            if(max(d2[u], w) < d2[v]){
                d2[v] = max(d2[u], w);
                q.push(make_pair(- d2[v], v));
            }
        }
    } 
}

void solve() {
   cin >> n >> m;
   rep(i, 1, m) {
        cin >> u[i] >> v[i] >> w[i];
        ed[u[i]].push_back(make_pair(w[i], v[i]));
        ed[v[i]].push_back(make_pair(w[i], u[i]));
   }
   dij1(1);
//    rep(i, 1, n) cout << d1[i] << " ";
//    cout << '\n';
   dij2(n);
//     rep(i, 1, n) cout << d2[i] << " ";
//    cout << '\n';
   ll ans = INF;
   rep(i, 1, m){
        int a = max(d1[u[i]], d2[v[i]]);
        int b = max(d2[u[i]], d1[v[i]]);
        
        if(min(a, b) <= w[i]) ans = min(ans, w[i] + min(a, b));
  //      cout << u[i] << " " << v[i] << " " << w[i] << " " << a <<  " " << b << " "<< ans <<'\n';
   }
   cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}