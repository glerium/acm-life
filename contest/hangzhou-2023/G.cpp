/*
 * Filename: i:\code\cpp\codeforces\gym-104976-hangzhou-2023\G.cpp
 * Path: i:\code\cpp\codeforces\gym-104976-hangzhou-2023
 * Created Date: Thursday, October 3rd 2024, 4:53:59 pm
 * Author: Glerium
 * 
 * Copyright (c) 2024  
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 3e3+10;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
struct Point {
    int x, y;
};
int n,m,k;
ll f[maxn][maxn];
bool snk[maxn][maxn], v[maxn][maxn];
deque<Point> q;
string mp[maxn];
int to[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
void dfs(int x, int y, ll step) {
    // if(v[x][y]) return;
    // v[x][y] = true;
    if(step >= f[x][y])
        return;
    f[x][y] = step;
    for(int i=0;i<4;i++) {
        int tx = x + to[i][0],
            ty = y + to[i][1];
        if(tx <= 0 || tx > n || ty <= 0 || ty > m)
            continue;
        if(snk[tx][ty]) continue;
        Point del = q.back();

        q.push_front({tx, ty});
        q.pop_back();
        snk[del.x][del.y] = false;

        dfs(tx, ty, step+1);

        snk[del.x][del.y] = true;
        q.push_back(del);
        q.pop_front();
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m >> k;
    memset(f, 0x3f, sizeof(f));
    for(int i=1,x,y;i<=k;i++) {
        cin >> x >> y;
        snk[x][y] = true;
        q.push_back({x, y});
    }
    for(int i=1;i<=n;i++) {
        cin >> mp[i];
        mp[i] = ' ' + mp[i];
    }
    Point hd = q.front();
    dfs(hd.x, hd.y, 0);
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            if(f[i][j] == inf)
                f[i][j] = 0;
            cout << f[i][j] << ' ';
            ans += f[i][j] * f[i][j];
        }
        cout << endl;
    }
    cout << ans << endl;
}
