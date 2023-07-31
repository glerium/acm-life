#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int n,m,q,row[maxn],col[maxn];
int ans,colc,rowc;
struct Op {
    bool row;
    int id;
    bool on;
}a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=1;i<=q;i++) {
        string x,z;
        int y;
        cin>>x>>y>>z;
        a[i].row = x[0]=='r';
        a[i].id = y;
        a[i].on = z[1]=='n';
        if(a[i].row) row[a[i].id] = i;
        else col[a[i].id] = i;
    }
    for(int i=q;i>=1;i--) {
        if(a[i].row&&i!=row[a[i].id]) continue;
        if(!a[i].row&&i!=col[a[i].id]) continue;
        if(a[i].row) {
            if(a[i].on) ans+=m-colc;
            rowc++;
        }else{
            if(a[i].on) ans+=n-rowc;
            colc++;
        }
    }
    cout<<ans<<endl;
    return 0;
}