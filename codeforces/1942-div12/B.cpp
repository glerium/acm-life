#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
int t, n, a[maxn], p[maxn];
set<int> st;
int main() {
    ios::sync_with_stdio(false);
    cin >> t;
    while(t--) {
        st.clear();
        cin >> n;
        for(int i=1;i<=n;i++) cin >> a[i];
        int mex = 0;
        for(int i=1;i<=n;i++) {
            if(a[i] >= 0) p[i] = mex;
            else p[i] = mex - a[i];
            st.insert(p[i]);
            while(st.count(mex)) mex++;
        }
        for(int i=1;i<=n;i++) cout << p[i] << ' ';
        cout << endl;
    }
    return 0;
}