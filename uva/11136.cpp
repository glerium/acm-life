#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    while(n) {
        multiset<int> st;
        long long ans = 0;
        for(int i=1;i<=n;i++) {
            int k; cin >> k;
            while(k--) {
                int tmp; cin >> tmp;
                st.insert(tmp);
            }
            ans += - *st.begin() + *--st.end();
            st.erase(st.begin());
            st.erase(--st.end());
        }
        cout << ans << endl;
        cin >> n;
    }
    return 0;
}