#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    int a[n+5][m+5];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> a[i][j];
        } 
    }
    map<int,vector<pair<int,int>>> mp;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            mp[a[i][j]].push_back({i,j});
        }
    }
    ll ans = 0;
    for(auto [k, v] : mp) {
        vector<int> vec;
        for(auto [i, j] : v)
            vec.push_back(i);
        sort(vec.begin(), vec.end());
        ll sum = 0;
        for(int i=0;i<vec.size();i++) {
            ans += vec[i] * i - sum;
            sum += vec[i];
        }

        vec.clear();
        for(auto [i, j] : v)
            vec.push_back(j);
        sort(vec.begin(), vec.end());
        sum = 0;
        for(int i=0;i<vec.size();i++) {
            ans += vec[i] * i - sum;
            sum += vec[i];
        }
    }
    cout << ans * 2 << endl;
    return 0;
}