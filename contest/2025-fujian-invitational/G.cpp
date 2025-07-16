#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;

const int N = 1e5 + 10; 

ll a[N]; 


vector< pair<int, int> > q;

ll c[N], S[N];

int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    rep(i, 1, n){
        cin >> a[i] ;
    }
    ll k;
    cin >> k;
    // if(n == 1) {
    //     rep(i, 1, n) { 
    //         int s, t;
    //         cin >> s >> t;
    //         cout << k << '\n';
    //     }
    //     return 0;
    // }
    // int cnt = 1;
    // for(int i = 2; i <= n; ){ 
    //     while(a[i] >= a[i - 1] && i <= n) i ++;
    //  // [cnt, i - 1]
    //     q.push_back({cnt, i - 1});
    //     cnt = i;
    //     i ++;
    // }
    int start = 1;
    for(int i=1;i<=n;i++) {
        if(a[i] >= a[i-1]) continue;
        q.push_back({start, i - 1});
        start = i;
    }
    q.push_back({start, n});
    // for(auto x : q) cout << x.first << x.second << '\n';
    rep(i, 0, q.size() - 1){
        c[i] = (a[q[i].second] - a[q[i].first]);
        S[i] = S[i - 1] + c[i];
    }
    rep(i, 1, m) {
        ll s, t; 
        cin >> s >> t;
        int l = 0, r = q.size() - 1;
        int ans1 = 0; 
        while(l <= r) {
            int mid = (l + r) / 2;
            if(q[mid].first <= s) {
                l = mid + 1;
                ans1 = mid;
            }
            else r = mid - 1;
        }
        l = 0, r = q.size() - 1;
        int ans2 = 0; 
        while(l <= r) {
            int mid = (l + r) / 2;
            if(q[mid].second >= t) {
                r = mid - 1;
                ans2 = mid;
            }
            else l = mid + 1;
        }
        ll ans = 0;
        if(ans1 == ans2) {
            cout << (ll) a[t] - a[s] + k << '\n';
        }
        else{
            if(q[ans1].second >= s)  ans += a[q[ans1].second] - a[s]; 
            if(q[ans2].first <= t) ans += a[t] - a[q[ans2].first];
            ans += S[ans2 - 1] - S[ans1]; 
            cout << ans + k << '\n';
        }
    }
  
    return 0;
}

/*
6 2
1 2 3 4 5 6
2
2 4
3 6
*/