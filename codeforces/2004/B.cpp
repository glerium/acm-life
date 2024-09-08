#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int l,r,L,R; cin>>l>>r>>L>>R;
    if(l > L) {
        swap(l,L);
        swap(r,R);
    }
    if(L > r) cout << 1 << endl;
    else if(r >= R) {
        cout << (l < L) + (R != r) + (R - L) << endl;
    }else{
        cout << (l < L) + (R - r + 1) << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
