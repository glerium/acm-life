#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int maxn=1e3+10;
const int maxl=1e6+10;
int _,n,m,k;
int r[maxn][maxn];
string s;
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        rep(i,1,n) rep(j,1,m) r[i][j]=0;
        cin>>n>>m>>k>>s;
        {
            int h=0,v=0;
            for(auto i:s) {
                if(i=='U') h++;
                else if(i=='D') h--;
                else if(i=='L') v++;
                else if(i=='R') v--;
            }
            if(abs(h)>=n||abs(v)>=m) {
                if(k==0) cout<<n*m<<endl;
                else cout<<0<<endl;
                continue;
            }
        }
        int n0=1,n1=n,m0=1,m1=m;
        for(auto i:s) {
            if(i=='D') n0++,n1++;
            else if(i=='U') n0--,n1--;
            else if(i=='L') m0--,m1--;
            else if(i=='R') m0++,m1++;
            n0=max(n0,0);
            m0=max(m0,0);
            n1=min(n1,n);
            m1=min(m1,m);
        }
        int nn=n1-n0+1, mm=
    }
}