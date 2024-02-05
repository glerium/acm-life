#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll n,k,x;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>k>>x;
        ll mi=(1+k)*k/2, ma=(n+n-k+1)*k/2;
        if(mi<=x&&x<=ma) puts("YES");
        else puts("NO");
    }
    return 0;
}