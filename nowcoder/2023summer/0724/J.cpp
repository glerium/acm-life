#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,m,head[maxn],in[maxn],out[maxn],cnt;
bool got;
vector<int> ans;
struct Edge{
    int to,nxt;
}a[maxn];
void add(int x,int y){
    a[++cnt]=(Edge){y,head[x]};
    head[x]=cnt;
}
void get_ans() {
    queue<int> q;
    bitset<maxn> v;
    for(int i=1;i<=n;i++) if(!in[i]) q.push(i);
    while(!q.empty()) {
        int t=q.front(); q.pop();
        if(v[t]) continue;
        v[t]=true;
        ans.push_back(t);
        for(int i=head[t];i;i=a[i].nxt) {
            if(v[a[i].to]) continue;
            in[a[i].to]--;
            if(!in[a[i].to]) q.push(a[i].to);
        }
    }
    got = ans.size()==n;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++) {
        int x,y; cin>>x>>y;
        add(x,y);
        out[x]++;
        in[y]++;
    }
    get_ans();
    if(got) {
        cout<<1<<endl;
        for(auto i : ans) cout<<i<<' ';
        cout<<endl;
    }else{
        cout<<2<<endl;
        for(int i=1;i<=n;i++) cout<<i<<' ';
        cout<<endl;
        for(int i=n;i>=1;i--) cout<<i<<' ';
        cout<<endl;
    }
    return 0;
}