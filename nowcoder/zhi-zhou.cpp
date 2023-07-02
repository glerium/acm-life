#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int l,m;
struct Data{
    ll l,r;
    bool operator<(const Data& rhs)const{
        return l<rhs.l || l==rhs.l&&r<rhs.r;
    }
} a[maxn];
int main() {
    cin>>l>>m;
    for(int i=1;i<=m;i++) cin>>a[i].l>>a[i].r;
    sort(a+1,a+1+m);
    ll left=-1,right=-1;
    ll ans=0;
    for(int i=1;i<=m;i++) {
        if(left==-1&&right==-1) {
            left=a[i].l;
            right=a[i].r;
        }else if(a[i].l<=right) right=max(right,a[i].r);
        else {
            cout<<":"<<left<<' '<<right<<endl;
            ans+=right-left+1;
            left=a[i].l;
            right=a[i].r;
        }
    }
            // cout<<":"<<left<<' '<<right<<endl;
    ans+=a[m].r-left+1;
    cout<<l+1-ans<<endl;
    return 0;
}