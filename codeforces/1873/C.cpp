#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int t;
const int v[10][10] = {
    {1,1,1,1,1,1,1,1,1,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,5,5,4,3,2,1},
    {1,2,3,4,4,4,4,3,2,1},
    {1,2,3,3,3,3,3,3,2,1},
    {1,2,2,2,2,2,2,2,2,1},
    {1,1,1,1,1,1,1,1,1,1}
};
char c[20][20];
int main() {
    cin>>t;
    while(t--) {
        rep(i,0,9) rep(j,0,9) cin>>c[i][j];
        int ans=0;
        rep(i,0,9) rep(j,0,9) {
            if(c[i][j]=='X') ans+=v[i][j];
        }
        cout<<ans<<endl;
    }
    return 0;
}