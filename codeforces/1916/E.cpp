#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=6e5+10;
int _,n,head[maxn],cnt,b[maxn],dep[maxn];
long long ans=0;
struct Edge{
    int to,nxt;
}a[maxn];
void add(int x,int y){
    a[++cnt]={y,head[x]};
    head[x]=cnt;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n;
        cnt=0;
        rep(i,1,n) head[i]=0;
        rep(i,2,n) {
            int x; cin>>x;
            add(x,i);
        }
        rep(i,1,n) cin>>b[i];
        
        cout<<ans<<endl;
    }
    return 0;
}