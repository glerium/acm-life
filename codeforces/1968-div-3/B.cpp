#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m; cin >> n >> m;
    string a,b; cin >> a >> b;
    int i=0, j=0;
    while(i < n && j < m) {
        while(j < m && b[j] != a[i]) j++;
        if(j < m) i++;
        else break;
        j++;
    }
    cout << i << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
