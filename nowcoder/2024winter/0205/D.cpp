#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn=5e3+10;
constexpr int maxm=maxn*maxn;
int t,n,m,k,head[maxn],ct;
ll dis[maxn];
struct Edge{
    int to,nxt;
    ll dis;
}a[maxm];
struct State{
    int i;
    ll dis;
    bool operator<(const State& rhs)const{
        return dis>rhs.dis;
    }
};
priority_queue<State> q;
void add(int x,int y,ll z) {
    a[++ct]={y,head[x],z};
    head[x]=ct;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n>>m>>k;
        for(int i=1;i<=m;i++) {
            int x; ll y; cin>>x>>y;
            for(int j=1;j<=n;j++) {
                int to=(j-x+n)%n;
                to=!to?n:to;
                add(j,to,y);
            }
        }
        for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f;
        dis[k]=0;
        q.push({k,0});
        while(!q.empty()) {
            auto now=q.top(); q.pop();
//             cout<<now.dis<<' '<<now.i<<endl;
            if(now.dis!=dis[now.i]) continue;
            for(int i=head[now.i];i;i=a[i].nxt) {
                if(dis[a[i].to]>now.dis+a[i].dis) {
                    dis[a[i].to]=now.dis+a[i].dis;
                    q.push({a[i].to,dis[a[i].to]});
                }
            }
        }
        cout<<dis[1]<<endl;
    }
}