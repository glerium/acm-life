#include <bits/stdc++.h>
using namespace std;
const int maxn=4e5+10;
int n,ct,head[maxn],deg[maxn];
bool vali[maxn];
map<int,set<int>> mp;
multiset<int> ans;
struct Edge{
    int to,nxt;
}a[maxn];
void add(int x,int y) {
    a[++ct]=(Edge){y,head[x]};
    head[x]=ct;
}
int main() {
    scanf("%d",&n);
    for(int i=1;i<=n-1;i++) {
        int x,y; scanf("%d%d",&x,&y);
        add(x,y);
        add(y,x);
        deg[x]++, deg[y]++;
    }
    {
        int maxx=0;
        for(int i=1;i<=n;i++) maxx=max(maxx,deg[i]);
        for(int i=1;i<=maxx;i++) mp.insert(make_pair(i,set<int>()));
    }
    for(int i=1;i<=n;i++) {
        mp[deg[i]].insert(i);
        vali[i]=1;
    }
    while(!mp[1].empty()) {
        int x = *(mp[1].begin());
        if(!vali[x]) {
            mp[1].erase(x);
            continue;
        }
        // printf("x=%d\n",x);
        int y=0;
        for(int i=head[x];i;i=a[i].nxt) {
            if(!vali[a[i].to]) continue;
            y=a[i].to;
            break;
        }
        // if(!y) {
        //     mp[1].erase(x);
        //     continue;
        // }
        vali[y]=false;
        // cout<<"Y: "<<y<<endl;
        int cnt=0;
        for(int i=head[y];i;i=a[i].nxt) {
        // printf("%ddd\n",mp[1].count(9));
            // printf("caught %d\n",a[i].to);
            if(!vali[a[i].to]) continue;
            cnt++;
            vali[a[i].to]=0;
            for(int j=head[a[i].to];j;j=a[j].nxt) {
                if(!vali[a[j].to]) continue;
                if(deg[a[j].to]>1) {
                    mp[deg[a[j].to]].erase(a[j].to);
                    deg[a[j].to]--;
                    mp[deg[a[j].to]].insert(a[j].to);
                } else vali[a[j].to]=0;
            }
        }
        ans.insert(cnt);
    }
    for(auto i:ans) printf("%d ",i);
    puts("");
    return 0;
}