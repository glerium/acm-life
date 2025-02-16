#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int n,a[maxn];
int ans = 0;
void process(int l, int r) {
    // cerr << l << ' ' << r << endl;
    int mn = *(min_element(a+l, a+r+1));
    rep(i,l,r) a[i] -= mn;
    ans++;
    int st = -1;
    vector<pair<int,int>> vec;
    rep(i,l,r) {
        if(a[i] == 0) {
            if(st != -1){
                vec.push_back({st, i-1});
                st = -1;
            }
        }else{
            if(st == -1)
                st = i;
        }
    }
    if(st != -1)
        vec.push_back({st, r});
    for(auto [x, y] : vec) {
        // cout << l << ' ' << r << ' ' << x << ' ' << y << endl;
        process(x, y);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    process(1, n);
    cout << ans << endl;
    return 0;
}
