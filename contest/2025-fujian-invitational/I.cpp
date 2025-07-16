#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    s = " 1" + s + "0";
    vector<int> d(n+5);
    vector<pair<int,int>> ans;
    set<pair<int,int>> st;
    auto add = [&](int x, int y) {
        if(st.count({x,y}))
            return;
        ans.emplace_back(x, y);
        d[x]++; d[y]++;
        st.insert({x,y});
        st.insert({y,x});
    };

    if(s[n-1] != '0') {
        cout << -1 << endl;
        return;
    }
    
    int ctzero = 0;
    while(s[n - ctzero] == '0') ctzero++;
    ctzero--;
    rep(i,1,ctzero) add(1, n - i + 1);
    n -= ctzero;

    int mxd = d[1] + 1;

    if(s[n] == '1') {
        cout << -1 << endl;
        return;
    }
    rep(i,1,n) {
        int start = i;
        if(s[i] == '1') {
            while(i+1 <= n && s[i+1] == '0') i++;
        } else {
            cout << -1 << endl;
            return;
        }
        int k = i - start + 1;
        // start + 1 ... k
        if(k == 1) {
            mxd = 0;
            if(i != 1) {
                add(i, i - 1);
                add(i, i + 1);
            }
            continue;
        }
        if(i != 1) {
            add(i, i-1);
        }
        int s1 = start, s2 = start + 1;
        priority_queue<pair<int,int>> que;
        rep(j, start, i) {
            if(j == start)
                add(start, i);
            else
                add(j - 1, j);
        }
        rep(j, start, i) {      // zuihou shi ling 
            if(k == s1 || k == s2) {
                if(k - 3 < 0) {
                    cout << -1 << endl;
                    return;
                } else if(k - 3 > 0) {
                    que.emplace(min(mxd, k - 3), j);
                }
            }
            else {
                if(k - 2 < 0) {
                    cout << -1 << endl;
                    return;
                } else if(k - 2 > 0) {
                    que.emplace(min(mxd, k - 2), j);
                }
            }
        }
        while(!que.empty() && que.size() >= 2) {
            auto t1 = que.top(); que.pop();
            auto t2 = que.top(); que.pop();
            add(t1.second, t2.second);
            if(t1.first > 1)
                que.push({t1.first - 1, t1.second});
            if(t2.first > 1)
                que.push({t2.first - 1, t2.second});
        }
        rep(j, start, i) {
            mxd = min(mxd, d[j]);
        }
    }

    cout << ans.size() << endl;
    for(auto [x, y] : ans) {
        cout << x << ' ' << y << endl;
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}