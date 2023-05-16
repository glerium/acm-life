#include <bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int n,m,ct,f[maxn];
struct Edge{
    int x,y;
    int dis;
};
vector<vector<pair<int,int>>> a(maxn);
int f2[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int x,y,z;
        cin>>x>>y>>z;
        a[z].push_back(make_pair(x,y));
    }
    for(auto i : a) {
        for(auto j : i) f2[j.second]=0;
        for(auto j : i) f2[j.second]=max(f2[j.second],f[j.first]+1);
        for(auto j : i) f[j.second]=max(f[j.second],f2[j.second]);
    }
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}