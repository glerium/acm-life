#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    multiset<int, greater<int>> lst;
    multiset<int> rst;
    rep(i,1,n) {
        int x; cin >> x;
        if(rst.size() >= lst.size())
            lst.insert(x);
        else
            rst.insert(x);
        if(lst.empty() || rst.empty()) {
            cout << x << endl;
            continue;
        }
        if(*lst.begin() > *rst.begin()) {
            int tmp1 = *lst.begin(), tmp2 = *rst.begin();
            lst.erase(lst.find(tmp1));
            rst.insert(tmp1);
            rst.erase(rst.find(tmp2));
            lst.insert(tmp2);
        }
        if(*--rst.end() < *--lst.end()) {
            int tmp1 = *--lst.end(), tmp2 = *--rst.end();
            lst.erase(lst.find(tmp1));
            rst.insert(tmp1);
            rst.erase(rst.find(tmp2));
            lst.insert(tmp2);
        }
        if(i & 1)
            cout << *lst.begin() << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    while(t--) solve();
    return 0;
}
