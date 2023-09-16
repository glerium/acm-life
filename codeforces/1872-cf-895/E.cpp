#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int _,n,a[maxn],ans0,ans1,q,xo[maxn];
char s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        cin>>(s+1);
        ans0=ans1=0;
        for(int i=1;i<=n;i++) {
            if(s[i]=='0') ans0^=a[i];
            else ans1^=a[i];
        }
        for(int i=1;i<=n;i++) xo[i]=xo[i-1]^a[i];
        cin>>q;
        for(int i=1;i<=q;i++) {
            int op,x,y;
            cin>>op;
            if(op==1){
                cin>>x>>y;
                int delta=xo[y]^xo[x-1];
                ans0^=delta;
                ans1^=delta;
            }else{
                cin>>x;
                if(x==0) cout<<ans0<<' ';
                else cout<<ans1<<' ';
            }
        }
        cout<<endl;
    }
}