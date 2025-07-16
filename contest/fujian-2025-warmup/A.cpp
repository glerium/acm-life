#include <bits/stdc++.h>
using namespace std;
#define rep(i, o, p) for(int i = o; i <= p; i++)
int main() 
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> t(4);
    int ans = 0;
    int cnt = 0;
    rep(i, 1, n) {
        cin >> a[i];
        if(a[i] == a[i - 1]) {
            cnt ++;
        }
        else {
            t.push_back(cnt);
            cnt = 1;
        }
    }
    t.push_back(cnt);
    rep(i,1,4) t.push_back(0);
    // for(auto i : t) cout << i << '\n';
    rep(i, 1, t.size() - 1) ans = max(ans, t[i]);
    int b = (a[1] == 1) ? 1 : 2;
    for(int i = 1; i  + 1 <= t.size()- 1; i ++ ) ans = max(ans, t[i] + t[i + 1]);
    for(int i = b; i + 3 <= t.size()- 1; i += 2 ) ans = max(ans, t[i] + t[i + 1] + t[i + 2] + t[i + 3]);
    cout << ans << '\n';
}