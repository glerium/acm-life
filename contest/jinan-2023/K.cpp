// 双指针，同时用两个priority_queue动态维护子区间的中位数，并记录两个队列的数字和
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    int n; ll k;
    cin >> n >> k;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) a[i] -= i;
    multiset<int> st1;               // min -> mid (+1)
    multiset<int> st2;               // mid -> max
    int l=1, r=0, ans=0;
    ll sum1=0, sum2=0;
    while(true) {
        if(st1.empty()) {
            st1.insert(a[++r]);
            sum1 += a[r];
            continue;
        }
        ll mid = *st1.rbegin();
        ll opcnt = (st1.size() * mid - sum1) + (sum2 - st2.size() * mid);
        if(opcnt <= k) {
            ans = max(ans, r-l+1);
            r++;                        // 压入一个元素
            if(st2.empty() || a[r] <= *st2.begin()) {
                st1.insert(a[r]);
                sum1 += a[r];
            }else{
                st2.insert(a[r]);
                sum2 += a[r];
            }
            int len = r - l + 1;
            if(st1.size() > (len+1) / 2) {
                int tmp = *st1.rbegin();
                st1.erase(--st1.end());
                sum1 -= tmp;
                st2.insert(tmp);
                sum2 += tmp;
            }else if(st2.size() > (len+1) / 2 || st1.size() < st2.size()){
                int tmp = *st2.begin();
                st2.erase(st2.begin());
                sum2 -= tmp;
                st1.insert(tmp);
                sum1 += tmp;
            }
        }else{
            int rmv = a[l];
            l++;                        // 移出一个元素
            if(st1.count(rmv)) {
                st1.erase(st1.find(rmv));
                sum1 -= rmv;
            }else{
                st2.erase(st2.find(rmv));
                sum2 -= rmv;
            }
            int len = r - l + 1;
            if(st1.size() > (len+1) / 2) {
                int tmp = *st1.rbegin();
                st1.erase(--st1.end());
                sum1 -= tmp;
                st2.insert(tmp);
                sum2 += tmp;
            }else if(st2.size() > (len+1) / 2 || st1.size() < st2.size()){
                int tmp = *st2.begin();
                st2.erase(st2.begin());
                sum2 -= tmp;
                st1.insert(tmp);
                sum1 += tmp;
            }
        }
        if(l>n || r>n) break;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}