#include <bits/stdc++.h>
using namespace std;
int a[50][50];
int main() {
    int n;
    cin>>n;
    int x=1,y=n/2+1;
    a[x][y]=1;
    for(int i=2;i<=n*n;i++) {
        if(x==1&&y!=n) x=n,y++;
        else if(x!=1&&y==n) x--,y=1;
        else if(x==1&&y==n) x++;
        else if(x!=1&&y!=n) {
            if(!a[x-1][y+1]) x--,y++;
            else x++;
        }
        a[x][y]=i;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            cout<<a[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}