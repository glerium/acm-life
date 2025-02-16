#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,h,m; cin >> n >> h >> m;
    set<string> sa, sb, sc;
    rep(i,1,n) {
        string user_id; cin >> user_id;
        int yyyy, mm, dd, hh, MM, ss;
        scanf("%4d-%2d-%2d %2d:%2d:%2d", &yyyy, &mm, &dd, &hh, &MM, &ss);
        if(h == yyyy && m == mm) {
            if((hh >= 7 && hh <= 8) || (hh == 9 && MM == 0 && ss == 0) || 
               (hh >= 18 && hh <= 19) || (hh == 20 && MM == 0 && ss == 0)) {
                sa.insert(user_id);
            }else if((hh >= 11 && hh <= 12) || (hh == 13 && MM == 0 && ss == 0)) {
                sb.insert(user_id);
            }else if(hh >= 22 || hh == 0 || (hh == 1 && MM == 0 && ss == 0)) {
                sc.insert(user_id);
            }
        }
    }
    cout << sa.size() << ' ' << sb.size() << ' ' << sc.size() << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
