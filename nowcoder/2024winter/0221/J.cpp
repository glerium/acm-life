#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n; cin>>n;
    vector<array<int,2>> a(n+10);
    for(int i=1;i<=n;i++) cin>>a[i][0]>>a[i][1];
    vector<array<int,2>> b;
    int l=1, r=1e9;
    for(int i=1;i<=n;i++) {
        int x=a[i][0], y=a[i][1];
        if(y<l||x>r) {
            b.push_back({l,r});
            l=x, r=y;
        }else{
            l=max(l,x);
            r=min(r,y);
        }
    }
    b.push_back({l,r});
    vector<array<int,2>> f(b.size()+10);
    f[0][0]=f[0][1]=0;
    for(int i=1;i<b.size();i++) {
        f[i][0]=min(f[i-1][0]+abs(b[i][0]-b[i-1][0]),
                    f[i-1][1]+abs(b[i][0]-b[i-1][1]));
        f[i][1]=min(f[i-1][0]+abs(b[i][1]-b[i-1][0]),
                    f[i-1][1]+abs(b[i][1]-b[i-1][1]));
    }
    cout<<min(f[b.size()-1][0], f[b.size()-1][1])<<endl;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t=1;
    while(t--) solve();
    return 0;
}