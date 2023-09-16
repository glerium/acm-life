#include <bits/stdc++.h>
using namespace std;
const int maxn=105;
int _,n,ct,ans;
struct Trap{
    int d,s;
    bool operator<(const Trap& rhs)const{
        return d<rhs.d;
    }
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        ct=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i].d>>a[i].s;
        sort(a+1,a+1+n);
        ans=INT_MAX;
        for(int i=1;i<=n&&a[i].d<=ans;i++) {
            ans = min(ans,a[i].d+(a[i].s-1)/2);
        }
        cout<<ans<<endl;
    }
    return 0;
}