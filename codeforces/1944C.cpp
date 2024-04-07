#include <bits/stdc++.h>
using namespace std;
struct Stone {
    int i;
    int x;
    bool operator<(const Stone& rhs)const{
        if(this->x != rhs.x) return this->x > rhs.x;
        return this->i > rhs.i;
    }
};
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin >> a[i];
    priority_queue<Stone> q;
    vector<int> f(n+5);
    for(int i=1;i<=n;i++) {
        if(a[i] > (n + 1) / 2) continue;
        f[a[i]]++;
    }
    for(int i=0;i<=n;i++) {
        if(f[i] != 0)
            q.push({i, f[i]});
    }
    bool first = true;
    set<int> st;
    while(!q.empty()) {
        auto now = q.top(); q.pop();
        if(now.x != f[now.i]) continue;
        if(first)
            st.insert(now.i);
        else {
            f[now.i]--;
            if(f[now.i] > 0)
                q.push({now.i, f[now.i]});
        }
        first = !first;
    }
    for(int i=0;;i++) {
        if(!st.count(i)) {
            cout << i << endl;
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}