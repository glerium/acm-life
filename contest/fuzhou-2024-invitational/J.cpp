#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int maxn = 1e5+10;

double f[400][200][400] = { };

int D(int k){
    if(k >= 10 + 18 + 40 + 70 + 120) return 1 + 2 + 5 + 10 + 20;
    if(k >= 10 + 18 + 40 + 70) return 1 + 2 + 5 + 10;
    if(k >= 10 + 18 + 40) return 1 + 2 + 5;
    if(k >= 10 + 18) return 1 + 2;
    if(k >= 10) return 1;
    return 0;
}

double P(int j, int q){
    double p[10], p6tot;
    if(j > 50)
        p6tot = 0.02 + 0.02 * (j - 50);
    else p6tot = 0.02;
    p[7] = p6tot * 0.35;
    p[6] = p6tot * 0.65;
    p[5] = (1 - p6tot) * 8 / 98;
    p[4] = (1 - p6tot) * 50 / 98;
    p[3] = (1 - p6tot) * 40 / 98;
    return p[q];
}

void solve()
{
    int x;
    cin >> x;
    f[0][0][0] = 1;
    double ans = 0;
    rep(i, 0, 350){
        rep(j, 0, 150){
            rep(k, 0, 390){
                if(i + 1 <= x + D(k)){
                    f[i + 1][j + 1][k] += P(j, 3) * f[i][j][k];
                    f[i + 1][j + 1][k + 1] += P(j, 4) * f[i][j][k];
                    f[i + 1][j + 1][k + 6] += P(j, 5) * f[i][j][k];
                    f[i + 1][0][k + 10] += P(j, 6) * f[i][j][k];
                    ans += P(j, 7) * f[i][j][k];
                }
            }
        }
    }
    printf("%.6lf", ans);
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    solve();
    return 0;
}