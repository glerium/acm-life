#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
int l,n,a[233],ans;
int getidx(int x,int y){
    return x*n+y;
}
void dfs(int x,int s) {
    if(x == n*n) {
        for(int i=0;i<n;i++) {
            int sm = 0;
            for(int j=0;j<n;j++)
                sm += a[getidx(i,j)];
            if(sm != l) return;
        }
        for(int i=0;i<n;i++) {
            int sm = 0;
            for(int j=0;j<n;j++)
                sm += a[getidx(j,i)];
            if(sm != l) return;
        }
        ans++;
        return;
    }
    // if(n != 4 || (x != 3 && x != 7 && x != 11))
        for(int i=0;i<=l;i++) {
            if(s+i > n*l) break;
            if(n == 4 && x == 3 && a[0] + a[1] + a[2] + i != l) continue;
            if(n == 4 && x == 7 && a[4] + a[5] + a[6] + i != l) continue;
            if(n == 4 && x == 11 && a[8] + a[9] + a[10] + i != l) continue;
            if(n == 4 && x == 12 && a[0] + a[4] + a[8] + i != l) continue;
            if(n == 4 && x == 13 && a[1] + a[5] + a[9] + i != l) continue;
            if(n == 4 && x == 14 && a[2] + a[6] + a[10] + i != l) continue;
            a[x] = i;
            dfs(x+1,s+i);
        }
    // else {
    //     a[x] = l-a[x-1]-a[x-2]-a[x-3];
    //     dfs(x+1, s + a[x]);
    // }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l >> n;
    // if(n == 4) {
    //     if(l == 4) cout << 10147 << endl;
    //     else if(l == 5) cout << 40176 << endl;
    //     else if(l == 6) cout << 132724 << endl;
    //     return 0;
    // }
    dfs(0,0);
    cout << ans << endl;
    return 0;
}