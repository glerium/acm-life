#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int _,n,k,p[maxn],head[maxn],cnt,d[maxn];
bitset<maxn> v;
ll c[maxn];
struct Edge{
    int to,nxt;
}a[maxn<<1];
void add(int x,int y) {
    a[++cnt]={y,head[x]};
    head[x]=cnt;
}
ll dfs(int x) {
    // clog<<x<<endl;
    if(v[x]) return c[x];
    v[x]=true;
    if(!d[x]) return c[x];
    ll cost=0;
    for(int i=head[x];i;i=a[i].nxt)
        cost+=dfs(a[i].to);
    return c[x]=min(c[x],cost);
}
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cnt=0;
        rep(i,1,n) {
            head[i]=0;
        }
        v.reset();
        cin>>n>>k;
        rep(i,1,n) cin>>c[i];
        rep(i,1,k) {
            int k; cin>>k;
            c[k]=0;
        }
        rep(i,1,n) {
            int m; cin>>m;
            d[i]=m;
            rep(j,1,m) {
                int e; cin>>e;
                add(i,e);
            }
        }
        // cout<<"Ans = ";
        rep(i,1,n) cout<<dfs(i)<<' ';
        cout<<endl;
    }
    return 0;
}