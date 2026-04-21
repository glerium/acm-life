#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    map<string,vector<string>> mp;
    rep(i,1,n) {
        string x,y; cin >> x >> y;
        mp[x].push_back(y);
    }
    for(auto [k, vec] : mp) {
        int m = vec.size();
        rep(i, 0, m - 5) {
            set<string> st;
            rep(j, i, i + 4)
                st.insert(vec[j]);
            if(st.size() == 5) {
                cout << "PENTA KILL!" << endl;
                return 0;
            }
        }
    }
    cout << "SAD:(" << endl;
}