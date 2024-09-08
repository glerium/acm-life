#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5]; rep(i,1,n) cin >> a[i];
    int last = 0;
    deque<int> q;
    rep(i,1,n) q.push_back(i);
    int ans = 0;
    string s;
    last = 0;
    while(!q.empty() && (a[q.back()] > last || a[q.front()] > last)) {
        int ct = (a[q.back()] > last) + (a[q.front()] > last);
        if(ct == 0) break;
        else if(ct == 1) {
            if(a[q.back()] > last) {
                last = a[q.back()];
                q.pop_back();
                s += 'R';
            }else{
                last = a[q.front()];
                q.pop_front();
                s += 'L';
            }
            ans++;
        }else{
            if(a[q.back()] == a[q.front()]) {
                int ctl = 0, ctr = 0;
                int lastt = a[q.back()];
                rep(i,q.front()+1,q.back()) {
                    if(a[i] > lastt) {
                        lastt = a[i];
                        ctl++;
                    }else break;
                }
                lastt = a[q.front()];
                for(int i=q.back()-1;i>=q.front();i--) {
                    if(a[i] > lastt) {
                        lastt = a[i];
                        ctr++;
                    }else break;
                }
                if(ctl > ctr) {
                    last = a[q.front()];
                    q.pop_front();
                    s += 'L';
                }else{
                    last = a[q.back()];
                    q.pop_back();
                    s += 'R';
                }
            }
            else if(a[q.back()] > a[q.front()]) {
                last = a[q.front()];
                q.pop_front();
                s += 'L';
            }else{
                last = a[q.back()];
                q.pop_back();
                s += 'R';
            }
            ans++;
        }
    }
    cout << ans << endl << s << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
