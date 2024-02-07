#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=60;
int t,n,head[maxn];
bool f[maxn][maxn];
struct Cond{
    int x,y,z;
}c[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>c[i].x>>c[i].y>>c[i].z;
        bool found=false;
        for(int i=1;i<=3;i++) {
            for(int j=1;j<=3;j++) {
                for(int k=1;k<=3;k++){
                    bool ok=true;
                    for(int ii=1;ii<=n;ii++) {
                        int x,y;
                        if(c[ii].x==1) x=i;
                        else if(c[ii].x==2) x=j;
                        else x=k;
                        if(c[ii].y==1) y=i;
                        else if(c[ii].y==2) y=j;
                        else y=k;
                        if(c[ii].z==1) ok&=x<y;
                        else ok&=x>=y;
                    }
                    if(ok) {
                        found=true;
                        puts("Yes");
                        goto end;
                    }
                }
            }
        }
        puts("No");
end:    ;
    }
}