#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define rep(i, o, p) for(int i = o; i <= p; i ++ )
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; 
    cin >> k;
    if(k == 0) {
        cout << "7\n1 5 2 7 3 6 4"; 
        return 0;
    }
    else if(k == 1) {
        cout << 6 << '\n' << "1 1 4 5 1 4\n";
        return 0;
    }
    k -= 1; 
    int tmp = 0; 
    int now = 1;
    vector <int> ans;
    while(k) {
        int x = k % 2; 
        if(x) {
            if(tmp) {
                rep(i, 1, tmp) ans.push_back(now);
                now ++ ;
            }
            ans.push_back(now);
            now ++; 
        }
        tmp ++; 
        k /= 2;
    }
    cout << ans.size() << '\n';
    rep(i, 0, ans.size() - 1) cout << ans[i] << " "[i == ans.size() - 1];
    return 0;
}
