#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 10;
int t, n, a[maxn], b[maxn], idx[maxn], ct_u;
long long c, d;
map<int, int> ct;   // 数字，cnt
int main() {
    cin >> t;
    while(t--) {
        ct.clear();
        cin >> n >> c >> d;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            b[i] = a[i];
        }
        sort(b+1, b+1+n);     // 排序，准备离散化
        ct_u = unique(b+1, b+1+n)-b-1;
        for(int i=1;i<=n;i++) {
            if(ct.count(a[i])) ct[a[i]]++;
            else ct.insert(make_pair(a[i], 1));
        }
        auto it = ct.begin();
        for(int i=1;i<=ct_u;i++){
            idx[i] = it->first;
            it++;
        }
        long long ans = LONG_LONG_MAX;
        long long cost_last = 0;
        for(int i=1;i<=ct_u;i++) {
            if(i==1) 
                cost_last = cost_last + d * (idx[i] - idx[i-1] - 1)
                                      + c * (n - ct[idx[i]])
                                      + c * (ct[idx[i]] - 1);
            else
                cost_last = cost_last + d * (idx[i] - idx[i-1] - 1)
                                      - c * 1;
            ans = min(ans, cost_last);
            // cout << "cost:" << cost_last << endl;
        }
        ans = min(ans, 1ll * n * c + d);  // 删去所有再加上1
        cout << ans << endl;
    }
    return 0;
}