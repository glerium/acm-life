#include <bits/stdc++.h>
using namespace std;
int n,k,x,a[207][207],b[207][207];
int main() {
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) cin>>a[i][j];
    int ima=0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j+=2)
            b[i][j]=a[i][j];
    }
    for(int j=2;j<=n;j+=2) {
        for(int i=1;i<=ima+1;i++) b[i][j]=x;
        for(int i=ima+2;i<=n;i++) b[i][j]=a[i-ima-1][j];
        ima=(ima+1)%k;
    }
    for(int i=1;i<=n;i++) {
        int s=0;
        for(int j=1;j<=n;j++) s+=b[i][j];
        cout<<s<<' ';
    }
}
