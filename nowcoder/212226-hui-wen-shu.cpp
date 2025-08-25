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
    vector<int> a;
    int odd = -1;
    rep(i,0,9) {
        int x; cin >> x;
        if(x % 2 == 1) {
            if(odd == -1)
                odd = i;
            else {
                cout << -1;
                return;
            }
        }
        rep(_,1,x/2)
            a.push_back(i);
    }
    sort(a.begin(), a.end());
    if(a.empty()) {
        if(odd != -1)
            cout << (char)(odd + '0');
        else
            cout << -1;
        return;
    }
    if(a[0] == 0) {
        rep(i,0,a.size()-1) {
            if(a[i] != 0) {
                swap(a[0], a[i]);
                break;
            }
        }
        if(a[0] == 0) {
            cout << -1;
            return;
        }
    }
    string ans;
    for(auto i : a)
        ans += '0' + i;
    string fin;
    fin += ans;
    if(odd != -1) fin += '0' + odd;
    fin += string(ans.rbegin(), ans.rend());
    cout << fin;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}