#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e3+10;
int n,m;
char ch[maxn][maxn];
map<int, vector<array<int,2>>> mp;
int main() {
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> (ch[i] + 1);
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++)
            mp[i+j].push_back({i,j});
    }
    for(int i=1;i<=n+m;i++) {
        set<char> st;
        for(auto j:mp[i]) {
            st.insert(ch[j[0]][j[1]]);
        }
        if(st.size() > 1) {
            cout << i-2 << endl;
            return 0;
        }
    }
    cout << n+m-1 << endl;
    return 0;
}