#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=3e5+10;
int a[maxn],key[maxn],idx[maxn];
bool cmp(int x,int y) {
    if(key[x]!=key[y]) return key[x]<key[y];
    else return x>y;
}
void solve() {
    int n; cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) key[i]=a[i]+i;
    for(int i=1;i<=n;i++) idx[i]=i;
    sort(idx+1, idx+1+n, cmp);
    vector<int> ans;
    int now_idx=1;
    for(int i=1;i<=n;i++) {
        ans.push_back(now_idx + a[idx[i]]);
        now_idx++;
    }
    for(auto i:ans) cout<<i<<' ';
    cout<<endl;
}
int main() {
    int t; cin>>t;
    while(t--) solve();
}