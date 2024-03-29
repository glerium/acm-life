#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int a[10][10], n, T, p[100], m[10][10];
void step3() {
    int x=0, y=0;
    bool v[10][10] = {};
    auto check = [&](int xx, int yy) {
        if(xx < 0 || xx > 7 || yy < 0 || yy > 7) return false;
        if(v[xx][yy]) return false;
        return true;
    };
    for(int i=1;i<=n;i++) {
        m[x][y] = p[i];
        v[x][y] = true;
        if(check(x+1,y-1)) x++, y--;
        else if(check(x-1,y+1)) x--, y++;
        else if(x==0 || y==0 || x==7 || y==7) {
            if(x==0&&y==0) y++;
            else if(y==0) x++;
            else if(x==0) y++;
            else if(x==n) y++;
            else x++;
        }
    }
}
void step4() {
    rep(i,0,7) rep(j,0,7) m[i][j] *= a[i][j];
}
void step5() {
    double tt[10][10] = {};
    auto alpha = [&](int x) {
        if(x == 0) return sqrt(0.5);
        else return 1.0;
    };
    double pi = acos(-1);
    rep(i,0,7) {
        rep(j,0,7) {
            rep(ii,0,7) {
                rep(jj,0,7) {
                    tt[i][j] += alpha(ii) * alpha(jj) * m[ii][jj] * cos(pi/8*(i+0.5)*ii) * cos(pi/8*(j+0.5)*jj) / 4;
                }
            }
        }
    }
    rep(i,0,7) rep(j,0,7) {
        m[i][j] = round(tt[i][j] + 128);
        m[i][j] = min(255, max(m[i][j], 0));
    }
}
int main() {
    ios::sync_with_stdio(false);
    rep(i,0,7) rep(j,0,7) cin>>a[i][j];
    cin >> n >> T;
    rep(i,1,n) cin >> p[i];
    step3();
    
        // rep(i,0,7) {
        //     rep(j,0,7) cout << m[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl;

    if(T == 0) {
        rep(i,0,7) {
            rep(j,0,7) cout << m[i][j] << " "[j==7];
            cout << endl;
        }
        return 0;
    }
        // rep(i,0,7) {
        //     rep(j,0,7) cout << m[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl;

    step4();
    if(T == 1) {
        rep(i,0,7) {
            rep(j,0,7) cout << m[i][j] << " "[j==7];
            cout << endl;
        }
        return 0;
    }

        // rep(i,0,7) {
        //     rep(j,0,7) cout << m[i][j] << ' ';
        //     cout << endl;
        // }
        // cout << endl;

    step5();
    rep(i,0,7) {
        rep(j,0,7) cout << m[i][j] << " "[j==7];
        cout << endl;
    }
    return 0;
}