#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> ans(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        if(u+1==v)ans[u]=1;
    }
    int sum=0;
    for(int i=1;i<=n;i++)if(ans[i])sum++;
    cout<<((sum==n-1)?"Yes":"No")<<'\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t; cin >> t;
    // while(t--) solve();
    solve();
    return 0;
}