#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=10;
int t,n;
struct Cond{
    int x,y,z;
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].x>>a[i].y>>a[i].z;
        if(n==1) puts("Yes");
        else {
            if(a[1].x==a[2].x&&a[1].y==a[2].y) puts(a[1].z==a[2].z?"Yes":"No");
            else if(a[1].x==a[2].y&&a[1].y&&a[1].x) puts(a[1].z!=a[2].z?"Yes":"No");
            else puts("Yes");
        }
    }
}