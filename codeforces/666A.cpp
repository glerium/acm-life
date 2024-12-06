#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    set<pair<int,string>> st;
    set<string> ans;
    function<void(int, string)> dfs = [&](int x, string bk) -> void {
        if(st.count({x, bk}))
            return;
        st.insert({x, bk});
        string tmp = s.substr(x-1, 2);
        if(x >= 7 && bk != tmp) {
            ans.insert(tmp);
            dfs(x-2, tmp);
        }
        tmp = s.substr(x-2, 3);
        if(x >= 8 && bk != tmp) {
            ans.insert(tmp);
            dfs(x-3, tmp);
        }
    };
    dfs(n, "");
    cout << ans.size() << endl;
    for(auto str : ans)
        cout << str << endl;
    return 0;
}