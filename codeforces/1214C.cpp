    #include <bits/stdc++.h>
    #define endl '\n'
    #define rep(i,x,y) for(int i=x;i<=y;i++)
    using namespace std;
    typedef long long ll;
    constexpr int maxn = 2e5+10;
    constexpr ll mod = 998244353;
    void solve() {
        int n; cin >> n;
        if(n&1) {
            cout << "No" << endl;
            return;
        }
        stack<char> st;
        string s; cin >> s;
        for(auto i : s) {
        if(!st.empty() && st.top() == '(' && i == ')') st.pop();
            else st.push(i);
        }
        if(st.empty()) {
            cout << "Yes" << endl;
            return;
        }
        else if(st.size() == 2 && st.top() == '(') {
            st.pop();
            if(!st.empty() && st.top() == ')') {
                cout << "Yes" << endl;
                return;
            }
        }
        cout << "No" << endl;
    }
    int main() {
        // ios::sync_with_stdio(false);
        // cin.tie(nullptr);
        int t=1;
        while(t--) solve();
        return 0;
    }
