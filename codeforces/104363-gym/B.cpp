#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3;
int n,q,f[maxn][maxn];
bitset<maxn> a;
void make() {
    memset(f,0x3f,sizeof(f));
    for(int l=1;l<=n;l++) {
        for(int i=1,j=l;j<=n;i++,j++) {
            if(l==1) f[i][j]=1;
            else {
                if(a[i+1]!=a[i]&&a[j]!=a[j-1]) f[i][j]=min(f[i][j],f[i+1][j-1]);
                bool yes=true;
                for(int k=i;k<j;k++) {
                    if(a[k]==a[k+1]) {
                        yes=false;
                        break;
                    }
                }
                if(yes) {
                    f[i][j]=1;
                    // cout<<"YES"<<' '<<i<<' '<<j<<endl;
                    continue;
                }
                // cout<<"NO "<<i<<' '<<j<<endl;
                for(int k=i+1;k<=j;k++) {
                    // cout<<i<<' '<<j<<' '<<k<<endl;
                    if(a[k-1]==a[k]) f[i][j]=min(f[i][j],f[i][k-1]+f[k][j]);
                    else f[i][j]=min(f[i][j],f[i][k-1]+f[k][j]-1);
                }
            }
        }
    }
    // for(int i=1;i<=n;i++) {
    //     for(int j=1;j<=n;j++) {
    //         if(i<=j) cout<<f[i][j]<<' ';
    //     }
    //     cout<<endl;
    // }
}
int main() {
    cin>>n>>q;
    {
        char ch;
        for(int i=1;i<=n;i++) {
            cin>>ch;
            a[i]=(ch=='1');
        }
    }
    make();
    while(q--) {
        char op; int x,y;
        cin>>op>>x>>y;
        if(op=='Q') cout<<f[x][y]<<endl;
        else {
            for(int i=x;i<=y;i++) a[i]=!a[i];
            make();
        }
    }
    return 0;
}