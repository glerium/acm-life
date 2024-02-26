#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,p; cin>>n>>p;
    vector<int> a(n+10);
    for(int i=1;i<=n;i++) cin>>a[i];
    if(a[p]!=9) {
        cout<<"0 0"<<endl;
        return;
    }
    int l=p-1,r=p+1,ctl=1,ctr=1;
    while(ctl&&l>=1||ctr&&r<=n) {
        while(ctl&&l>=1) {
            int trans=min(ctl,10-a[l]);
            ctl-=trans; a[l]+=trans;
            if(a[l]>=10) {
                ctl++;
                ctr++;
                l--;
            }
        }
        while(ctr&&r<=n) {
            int trans=min(ctr,10-a[r]);
            ctr-=trans; a[r]+=trans;
            if(a[r]>=10) {
                ctl++;
                ctr++;
                r++;
            }
        }
    }
    cout<<ctl<<' '<<ctr<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}