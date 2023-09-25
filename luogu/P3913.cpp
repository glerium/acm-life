#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,k,r[maxn],c[maxn];
int main() {
    cin>>n>>k;
    {
        int x,y;
        for(int i=1;i<=k;i++) {
            cin>>r[i]>>c[i];
        }
        
    }
    sort(r+1,r+1+k);
    sort(c+1,c+1+k);
    int a = unique(r+1,r+1+k)-r-1;
    int b = unique(c+1,c+1+k)-c-1;
    // cout<<a<<' '<<b<<endl;
    cout<<a*n+b*n-a*b<<endl;
}