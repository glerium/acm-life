#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("in.txt", "w", stdout);
    srand(time(0));
    int n = 6;
    int t = 1000;
    cout << t << endl;
    rep(_,1,t) {
        cout << n << endl;
        rep(i,1,n) cout << rand() % 5 + 1 << ' ';
        cout << endl;
    }
    return 0;
}