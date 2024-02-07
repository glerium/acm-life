#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int n,m,k;
long double pa[maxn],pb[maxn];
vector<int> a[maxn],b[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) pa[i]=1;
    for(int i=1;i<=n;i++) pb[i]=1;
    for(int i=1;i<=k;i++) {
        int x,y; cin>>x>>y;
        a[x].push_back(y);
        b[y].push_back(x);
    }
    for(int i=0;i<n;i++) {
        for(auto j:a[i]) {
            pb[j]*=(1-1.0/a[i].size());
        }
    }
    for(int i=0;i<m;i++) {
        for(auto j:b[i]) {
            pa[j]*=(1-1.0/b[i].size());
        }
    }
    long double ans1=0,ans2=0;
    for(int i=0;i<n;i++) ans1+=1-pa[i];
    for(int i=0;i<m;i++) ans2+=1-pb[i];
    cout<<ans1<<' '<<ans2<<endl;
}