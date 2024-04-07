#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    set<int> st;
    for(int i=0;i<s.size();i++) {
        if(s[i] == '1')
            st.insert(i);
    }
    if(st.size() % 2 == 1) {
        puts("NO");
        return;
    }
    if(st.size() > 2 || st.size() == 0) {
        puts("YES");
        return;
    }
    if(*(++st.begin()) - *st.begin() != 1) {
        puts("YES");
    }else{
        puts("NO");
    }
}
int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}