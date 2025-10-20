#include <bits/stdc++.h>
using namespace std;
int f[20][20] = {};
int dp(int i, int j) {
    if(i < 0)
        return 0;
    if(f[i][j])
        return f[i][j];
    if(j == 0)
        return f[i][j] = 1;
    return f[i][j] = dp(i-1, j) + dp(i+1, j-1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << dp(0,n) << endl;

}