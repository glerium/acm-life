#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    if(n <= 2001) 
        cout << "{h:";
    else
        cout << "{d:";
    for(int i=1;i<=n;i++) cout << i << ",}"[i==n];
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; t = 1;
    while(t--) solve();
    return 0;
}
