#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

#define rep(i, o, p) for(int i = o; i <= p; i ++ )
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin >> n;
    double p[(n + 5)];
    rep(i, 1, n) cin >> p[i];
    double ans = 0;
    rep(i, 1, n){
        rep(j, 1, n) {
            if(i != j) ans += p[i] * p[j] / (p[i] + p[j]);
        }
    }
    printf("%.12lf", ans);
    return 0;
}
