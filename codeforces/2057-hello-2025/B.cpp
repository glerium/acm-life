#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,k; cin >> n >> k;
    map<int,int> ct;
    rep(i,1,n) {
        int tmp; cin >> tmp;
        ct[tmp]++;
    }
    multiset<int> st;
    for(auto [x,y] : ct) {
        st.insert(y);
    }
    int anss = st.size();
    for(auto i : st) {
        if(k >= i) {
            anss--;
            k -= i;
        }
    }
    cout << max(anss, 1) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
