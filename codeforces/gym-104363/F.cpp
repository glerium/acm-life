#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int n,head[maxn],cnt,son[maxn];
struct Edge{
    int to;
    int nxt;
}a[maxn];
void add(int x,int y) {
    a[++cnt] = (Edge){y,head[x]};
    head[x]=cnt;
}
void dfs(int x,int fa) {
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to==fa) continue;
        son[x]++;
        dfs(a[i].to,x);
    }
}
int main() {
    scanf("%d",&n);
    for(int i=2;i<=n;i++) {
        int tmp;
        scanf("%d",&tmp);
        add(tmp,i);
    }
    dfs(1,-1);
    int ans=0;
    for(int i=1;i<=n;i++) {
        ans += max(0,son[i]-1);
    }
    cout<<ans<<endl;
    return 0;
}