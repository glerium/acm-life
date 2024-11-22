#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a, b, d[15];
ll f[15][15];
void init(int pos, int pre, int az, int lim) {
    f
}

ll getans(int x) {
    int ct = 0;
    while(x) {
        d[++ct] = x % 10;
        x /= 10;
    }
    memset(f, -1, sizeof(f));
    return dfs(1, -1, 1)
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    cin >> a >> b;
    cout << getans(b) - getans(a - 1) << endl;
    return 0;
}