#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn = 2e5+10;
struct Dis{
    int i;
    int dis;
    bool operator<(const Dis& rhs)const{
        return dis < rhs.dis;
    }
};
void solve() {
    int n,m,k; cin >> n >> m >> k;
    string s; cin >> s; s = ' ' + s;
    vector<int> coord;
    for(int i=1;i<=n;i++) {
        if(s[i] == '0')
            coord.push_back(i);
    }
    for(int i=1;i<=n;i++) {
        vector<Dis> dis;
        for(auto j : coord) {
            dis.push_back({j, abs(i-j)});
        }
        sort(dis.begin(), dis.end());
        for(int j=0;j<min((int)dis.size(), m); j++) {
            s[dis[j].i] = '1';
        }
        vector<int> ddis;
        for(int j=1;j<=n;j++) {
            if(s[j] == '1') {
                ddis.push_back(abs(i-j));
            }
        }
        sort(ddis.begin(), ddis.end());
        long long ans = 0;
        for(int j=0;j<k;j++)
            ans += ddis[j];
        for(int j=0;j<min((int)dis.size(), m); j++) {
            s[dis[j].i] = '0';
        }
        cout << ans;
        if(i != n) cout << ' ';
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}