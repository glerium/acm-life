#include <bits/stdc++.h>
// #define endl '\n'
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
    int n; cin >> n;
    int x;
    cout << "digit" << endl;
    cin >> x;

    cout << "digit" << endl;
    cin >> x;
    
    cout << "add -8" << endl;
    cin >> x;
    
    cout << "add -4" << endl;
    cin >> x;
    
    cout << "add -2" << endl;
    cin >> x;
    
    cout << "add -1" << endl;
    cin >> x;
    
    cout << "add " << n - 1 << endl;
    cin >> x;
    
    cout << "!" << endl;
    cin >> x;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}