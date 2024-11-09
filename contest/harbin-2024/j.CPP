#include <bits/stdc++.h>
#define endl '\n'

#define rep(i, o, p) for(int i = o; i <= p; i ++ )

using namespace std;
typedef long long ll;
constexpr int maxn = 1e5+10;

const ll INF = 1e16;

void sol(){
    int n, m; 
    cin >> n >> m;
    vector <ll> a(n + 5), pos(m + 5), c(m + 5), t(n + 5);
    map <ll, ll> mp, list;
    vector<ll> tmp(n + 5);
    set <ll> s;
    rep(i, 1, n) {
        cin >> a[i];
        t[i] = a[i];
    }
    rep(i, 1, m) {
        cin >> pos[i] >> c[i];
        mp[pos[i]] = c[i]; // pos x has y
        if(tmp[c[i]]) list[tmp[c[i]]] = pos[i];
        else s.insert(pos[i]);
        tmp[c[i]] = pos[i];
    }

    rep(i, 1, n) {
        s.insert(INF + i);
        mp[INF + i] = i;
    }

    long long ans = 0;
    rep(i, 1, m){
        while(*s.begin() < pos[i])  {
            ll a = *s.begin();
            s.erase(s.begin());
            if(list[a])
                s.insert(list[a]);
        }
        ll l = pos[i] - pos[i - 1];
        ll cnt = 0;
        auto it = *s.begin();
        bool flag = 1;
        while(1){
            //cout << 73;
           if(t[mp[it]] >= l ) {
      //      cout << mp[it] << endl;
         //   cout << "73";
            t[mp[it]] -= l;
            // if(!t[mp[it]]) {
            //     s.erase(it);
            //     if(list[it]) {
            //         s.insert(list[it]);
            //     }
            // }
            t[c[i]] = a[c[i]];
            if(list[pos[i]]) s.insert(list[pos[i]]);
            cnt += l;
             break;
           }
           else {
          //  cout << 2;
            l -= t[mp[it]];
            cnt += t[mp[it]];
            t[mp[it]] = 0;
            s.erase(it);
            if(s.size()) it = *s.begin();
            else {
                flag = 0;
                break;
            }
           }
        }
        ans += cnt;
        if(flag == 0) break;
    }
    //cout << ans << t[1] << t[2] << endl;
    rep(i, 1, n) ans += t[i]; 
    cout << ans << '\n'; 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) sol();
    return 0;
}
/*
2
3 1
3 3 3
8 1
2 2
5 2
1 2
2 1
*/