#include <bits/stdc++.h>
using namespace std;
int n,m,a[10][10],ans=114514;
vector<int> v(100),v2(100);
map<vector<int>,int> mp;
int getp(int x,int y) {
    // printf("%d %d\n",x,y);
    return (x*m+y);
}
bool check(const vector<int>& v) {
    int sz=v.size();
    for(int i=0;i<sz;i++) if(v[i]!=i) return false;
    return true;
}
int ct=0;
void dfs1(vector<int> v, int s) {
    if(s>10) return;
    if(mp.count(v)&&mp[v]<=s) return;
    vector<int> vv(m*n);
    mp[v]=s;
    for(int x=0;x<=1;x++) {
        for(int y=0;y<=1;y++) {
            for(int i=0;i<n*m;i++) vv[i]=-1;
            for(int i=0;i<n-1;i++) {
                for(int j=0;j<m-1;j++) {
                    vv[getp(i+x,j+y)]=v[getp(n-2-i+x,m-2-j+y)];
                }
            }
            for(int i=0;i<n*m;i++) if(vv[i]==-1) vv[i]=v[i];
            dfs1(vv,s+1);
        }
    }
}
void dfs2(vector<int> v, int s) {
    if(s>10) return;
    if(mp.count(v)) {
        ans=min(ans,mp[v]+s);
        return;
    }
    vector<int> vv(n*m);
    for(int x=0;x<=1;x++) {
        for(int y=0;y<=1;y++) {
            for(int i=0;i<n*m;i++) vv[i]=-1;
            for(int i=0;i<n-1;i++) {
                for(int j=0;j<m-1;j++) {
                    vv[getp(i+x,j+y)]=v[getp(n-2-i+x,m-2-j+y)];
                }
            }
            for(int i=0;i<n*m;i++) if(vv[i]==-1) vv[i]=v[i];
            dfs2(vv,s+1);
        }
    }
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) cin>>a[i][j];
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) a[i][j]--;
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) v[getp(i-1,j-1)]=a[i][j];
    for(int i=0;i<n*m;i++) v2[i]=i;
    dfs1(v,0);
    // cout<<mp.size()<<endl;
    // cout<<mp[v2]<<endl;
    // for(auto i:mp) {
    //     if(i.second!=1) continue;
    //     for(int j=0;j<9;j++)
    //         cout<<i.first[j]<<' ';
    //     cout<<":"<<i.second<<' '<<endl;
    // }
    dfs2(v2,0);
    if(ans==114514) cout<<-1<<endl;
    else cout<<ans<<endl;
    return 0;
}