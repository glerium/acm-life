#include <iostream>
#include <climits>
using namespace std;
constexpr int maxn=507;
int n,m,q;
int f[2][3][2][3][maxn][maxn];    // pos:x,y; xdir:0(red)/1(der); xoffset:0/1/2; ydir; yoffset
char a[maxn][maxn];
void init() {
    char s[]="red";
    for(int xdir=0; xdir<=1; xdir++) {
        for(int xoff=0; xoff<=2; xoff++) {
            for(int ydir=0; ydir<=1; ydir++) {
                for(int yoff=0; yoff<=2; yoff++) {
                    auto ff=f[xdir][xoff][ydir][yoff];
                    for(int i=1; i<=n; i++) {
                        for(int j=1; j<=m; j++) {
                            int now=0;
                            now+=(xoff+i-1)*(xdir?-1:1);
                            now+=(yoff+j-1)*(ydir?-1:1);
                            now=(now%3+3)%3;
                            ff[i][j]=ff[i-1][j]+ff[i][j-1]-ff[i-1][j-1]+(a[i][j]!=s[now]);
                        }
                    }
                }
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++) cin>>(a[i]+1);
    init();
    while(q--) {
        int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
        if(x2-x1==1&&y2-y1==1) {
            if(a[x2][y2] == a[x1][y1] && a[x1][y2] == a[x2][y1] && a[x2][y2] != a[x1][y2]) {
                cout<<0<<endl;
                continue;
            }
        }
        int ans=INT_MAX;
        for(int xdir=0; xdir<=1; xdir++) {
            for(int xoff=0; xoff<=2; xoff++) {
                for(int ydir=0; ydir<=1; ydir++) {
                    for(int yoff=0; yoff<=2; yoff++) {
                        auto ff=f[xdir][xoff][ydir][yoff];
                        ans=min(ans, ff[x2][y2]-ff[x1-1][y2]-ff[x2][y1-1]+ff[x1-1][y1-1]);
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}