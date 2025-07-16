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
    int n = 10;
    rep(_,1,1) {
        cout << n << endl;
        rep(i,1,n) cout << rand() % n << ' ';
        cout << endl;
    }
    return 0;
}