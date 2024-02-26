#include <bits/stdc++.h>
using namespace std;
int n,m; 
vector<int> a(200009);
int st[200009][25];
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    string s; cin>>s;

    for(int i=1;i<=n;i++) st[i][0]=a[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=20;j++)
            st[i][j]=1;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=20;j++) {
            if(i+(1<<j)-1>n) continue;
            st[i][j]=st[i][j-1]*st[i+(1<<(j-1))][j-1]%m;
        }
    }

    auto query = [](int l,int r) -> int {
        int ret = 1;
        for(int j=20;j>=0;j--) {
            if(l+(1<<j)-1>r) continue;
            ret = ret*st[l][j]%m;
            l+=(1<<j);
        }
        return ret;
    };
    int l=1,r=n;
    for(auto op:s) {
        cout<<query(l,r)<<' ';
        if(op=='L') l++;
        else r--;
    }
    cout<<endl;
}
int main() {
    int t; cin>>t;
    while(t--) solve();
    return 0;
}