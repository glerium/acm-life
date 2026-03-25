#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> pai;

const int mod  = 998244353, N=1e6;

int vis[1000010], mnp[1000010];

int prime[100010],totp = 0;

ll qp(ll b, ll k, ll res = 1ll){
    while(k) {
        if(k & 1) res = res * b % mod;
        b = b * b % mod;
        k >>= 1;
    }
    return res;
}

vector<int> c[1000005];

void sol() {
    int n;
    cin >> n;
    // vector<int> c[n + 5];
    // unordered_map<int, vector<int>> c;
    vector<int> vec;
    rep(i, 1, n) {
        int x;
        cin >> x;
        while(x != 1) {
          int tt = mnp[x];
          int tmp = 0;
          // cout << x << ' ' << tt << endl;
          while(x % tt == 0) {
            x /= tt, tmp++;
          }
          if(tmp) {
            vec.push_back(tt);
            c[tt].push_back(tmp);
          }
        }
    }
    sort(vec.begin(), vec.end());
    auto pos = unique(vec.begin(), vec.end());
    vec.erase(pos, vec.end());
    for(auto i : vec) {
        sort(c[i].begin(), c[i].end(), greater<int>());
    }
    ll ans = 0;
    ll a[n+5] = {};
    rep(i,1,n) a[i] = 1;
    for(auto i : vec) {
      for(int j=0; j<c[i].size(); j++) {
        a[j+1] *= qp(i, c[i][j]);
        a[j+1] %= mod;
      }
    }
    rep(i,1,n) {
      ans += a[i];
      ans %= mod;
    }
    cout << ans << '\n';

    for(auto i : vec) {
      c[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int i = 2; i <= N; i ++){
        if(!vis[i]) prime[++ totp] = i;
        for(int j = 1; i * j <= N; j ++){
            vis[i * j] = 1;
            if(mnp[i * j] == 0)
              mnp[i * j] = i;
        }
    }
    for(int i = 2; i <= N; i ++){
      if(!vis[i] && mnp[i] == 0) {
        mnp[i] = i;
      }
    }
    //  rep(i, 1, 100) cout << prime[i];
    int T; 
    cin >> T;
    rep(i, 1, T ){
       sol();
    }
}