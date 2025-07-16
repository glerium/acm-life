#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
void solve()
{
    int n,m;
    cin>>n>>m;
    ll l,r;
    cin>>l>>r;
    auto a=vector(n+2,vector(m+2,'0'));
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    auto vis=vector(n+2,vector(m+2,array<int,2>{0,0}));
    auto dis=vector(n+2,vector(m+2,array<ll,2>{int(1e9),int(1e9)}));
    queue<array<ll,3>> q;
    vector<pair<int,int>> f={{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    q.push({1,1,0});
    dis[1][1][0]=0;
    while(!q.empty())
    {
        auto [x,y,d]=q.front();
        q.pop();
        if(vis[x][y][d&1])continue;
        vis[x][y][d&1]=1;
        for(auto &[dx,dy]:f)
        {
            if(a[x+dx][y+dy]=='1')
            {
                dis[x+dx][y+dy][(d+1)&1]=min(dis[x+dx][y+dy][(d+1)&1],d+1);
                q.push({x+dx,y+dy,d+1});
            }
        }
    }
    if(l==r)
    {
        if(r%2==0)
        {
            if(dis[n][m][0]==int(1e9))
                cout<<-1<<'\n';
            else cout<<(dis[n][m][0]+r-1)/r<<'\n';    
        }
        else if(r%2==1)
        {
            ll ans1=1e9,ans2=1e9;
            if(dis[n][m][1]!=1e9)
                ans1=(dis[n][m][1]+r-1)/r;
            if(dis[n][m][0]!=1e9)
                ans2=(dis[n][m][0]+r-1)/r;
            if(ans1%2==0)ans1++;
            if(ans2%2==1)ans2++;
            if(min(ans1,ans2)>=1e9)cout<<-1<<'\n';
            else cout<<min(ans1,ans2)<<'\n';
        }
    }
    else
    {
        if(min(dis[n][m][0],dis[n][m][1])==int(1e9))cout<<-1<<'\n';
        else cout<<(0ll+min(dis[n][m][0],dis[n][m][1])+r-1)/r<<'\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int t;cin>>t;while(t--)solve();
    return 0;
}