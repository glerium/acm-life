#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k; cin >> n >> k;
    int a[n+5][n+5];
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j++)
            cin >> a[i][j];
    }
    vector<int> dp[n+5];
    dp[0] = {0};
    // for j in [1, i-2], merge dp[j][k] + a[j+2][i]
    // for j in [1, i-1], merge dp[j][k]
    for(int i=1;i<=n;i++) {
        priority_queue<array<int,3>> q;     // val, j, k
        q.push({dp[i-1][0], i-1, 0});
        for(int j=i-2;j>=-1;j--) {
            q.push({dp[max(0, j)][0] + a[j+2][i], j, 0});
        }
        while(!q.empty() && dp[i].size() < k) {
            auto [val, j, k] = q.top(); q.pop();
            dp[i].push_back(val);
            if(k >= dp[j].size() - 1) continue;
            if(j < 0) continue;
            if(j == i-1) 
                q.push({dp[j][k+1], j, k+1});
            else 
                q.push({dp[j][k+1] + a[j+2][i], j, k+1});
        }
    }
    for(auto i : dp[n])
        cout << i << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}