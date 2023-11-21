#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=20;
const int n=15;
int t,a[maxn][maxn];
bool _check(int x,int y){
    return !(x<1||x>n||y<1||y>n);
}
bool check(int x,int y) {
    a[x][y]=1;
    for(int i=x-4;i<=x;i++) {
        bool ok=true;
        for(int j=i;j<=i+4;j++) {
            if(a[j][y]!=1||!_check(j,y)) {
                ok=false;
                break;
            }
        }
        if(ok) return true;
    }
    for(int i=y-4;i<=y;i++) {
        bool ok=true;
        for(int j=i;j<=i+4;j++) {
            if(a[x][j]!=1||!_check(x,j)) {
                ok=false;
                break;
            }
        }
        if(ok) return true;
    }
    for(int i=-4;i<=0;i++) {
        bool ok=true;
        for(int j=i;j<=i+4;j++) {
            int tx=x+j, ty=y+j;
            if(a[tx][ty]!=1||!_check(tx,ty)) {
                ok=false;
                break;
            }
        }
        if(ok) return true;
    }
    for(int i=-4;i<=0;i++) {
        bool ok=true;
        for(int j=i;j<=i+4;j++) {
            int tx=x+j, ty=y-j;
            if(a[tx][ty]!=1||!_check(tx,ty)) {
                ok=false;
                break;
            }
        }
        if(ok) return true;
    }
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        char ch;
        rep(i,1,15) {
            rep(j,1,15) {
                cin>>ch;
                a[i][j]=ch-'0';
            }
        }
        bool ok=false;
        rep(i,1,15) {
            rep(j,1,15) {
                if(a[i][j]==0){
                    ok|=check(i,j);
                    a[i][j]=0;
                    if(ok) goto end;
                }
            }
        }
end:    ;
        puts(ok?"Yes":"No");
    }
    return 0;
}