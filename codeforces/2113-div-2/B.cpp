#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int w,h,a,b; cin >> w >> h >> a >> b;
    int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;
    int xx1 = x1 + a - 1, yy1 = y1 + b - 1;
    int xx2 = x2 + a - 1, yy2 = y2 + b - 1;
    if(x1 > xx2 && (x1 - xx2 - 1) % a == 0 || x2 > xx1 && (x2 - xx1 - 1) % a == 0) {
        cout << "Yes" << endl;
        return;
    }
    if(y1 > yy2 && (y1 - yy2 - 1) % b == 0 || y2 > yy1 && (y2 - yy1 - 1) % b == 0) {
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
