#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// len lastd ex san 4 8
ll f[20][10][4][2][2][2];
void init() {
    for(int i=0;i<=9;i++) {
        if(i == 4)
            f[1][i][1][0][1][0] = 1;
        else if(i == 8)
            f[1][i][1][0][0][1] = 1;
        else
            f[1][i][1][0][0][0] = 1;
    }
    for(int i=2;i<=12;i++) {
        for(int j=0;j<=9;j++) {             // now d
            for(int k=0;k<=9;k++) {         // last d
                if(j != k) {
                    for(int a=0;a<=1;a++) {
                        for(int b=0;b<=1;b++) {
                            for(int c=0;c<=1;c++) {
                                for(int l=1;l<=3;l++) {     // last len
                                    if(j == 4)
                                        f[i][j][1][a][1][c] += f[i-1][k][l][a][b][c];
                                    else if(j == 8)
                                        f[i][j][1][a][b][1] += f[i-1][k][l][a][b][c];
                                    else
                                        f[i][j][1][a][b][c] += f[i-1][k][l][a][b][c];
                                }
                            }
                        }
                    }
                }else{
                    for(int a=0;a<=1;a++) {
                        for(int b=0;b<=1;b++) {
                            for(int c=0;c<=1;c++) {
                                for(int l=1;l<=3;l++) {
                                    if(l+1 >= 3) {
                                        if(j == 4)
                                            f[i][j][3][1][1][c] += f[i-1][k][l][a][b][c];
                                        else if(j == 8)
                                            f[i][j][3][1][b][1] += f[i-1][k][l][a][b][c];
                                        else
                                            f[i][j][3][1][b][c] += f[i-1][k][l][a][b][c];
                                    }else{
                                        if(j == 4)
                                            f[i][j][l+1][a][1][c] += f[i-1][k][l][a][b][c];
                                        else if(j == 8)
                                            f[i][j][l+1][a][b][1] += f[i-1][k][l][a][b][c];
                                        else
                                            f[i][j][l+1][a][b][c] += f[i-1][k][l][a][b][c];
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
ll getf(ll x) {
    int d[15] = {};
    int len = 0;
    while(x) {
        d[++len] = x % 10;
        x /= 10;
    }
    ll ans = 0;

    // == len && d < a[len]
    for(int j=0;j<d[len];j++) {
        for(int l=1;l<=3;l++) {
            for(int a=0;a<=1;a++) {
                for(int b=0;b<=1;b++) {
                    for(int c=0;c<=1;c++) {
                        if(!(a && !(b && c)))
                            continue;
                        ans += f[len][j][l][a][b][c];
                    }
                }
            }
        }
    }


    // == len && d == a[len]
    int w4 = false, w8 = false, maxl = 1, curl = 1;
    for(int i=len-1;i>=1;i--) {
        w4 |= d[i+1] == 4;
        w8 |= d[i+1] == 8;
        for(int j=0;j<d[i];j++) {
            for(int l=1;l<=3;l++) {
                for(int a=0;a<=1;a++) {
                    for(int b=0;b<=1;b++) {
                        for(int c=0;c<=1;c++) {
                            if(!((a || (max(maxl, j == d[i+1] ? curl + 1 : 1) >= 3)) && (!((b | w4) && (c | w8)))))
                                continue;
                            ans += f[i][j][l][a][b][c];
                        }
                    }
                }
            }
        }
        curl = d[i+1] == d[i] ? curl + 1 : 1;
        maxl = max(maxl, curl);
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    init();
    ll l, r;
    cin >> l >> r;
    cout << getf(r+1) - getf(l) << endl;
    return 0;
}
