#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll calc(int n)
{
    return 1ll*n*(n+1)/2;
}
int main()
{
    int n;
    cin>>n;
    vector<int> a(n+2),b(n+2),pa(n+2),pb(n+2);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pa[a[i]]=i;
    }
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        pb[b[i]]=i;
    }
    long long ans=0;
    // mex = 1
    int l=pa[1],r=pb[1];
    if(l>r)swap(l,r);
    ans+=calc(l-1);
    ans+=calc(n-r);
    ans+=calc(r-l-1);
    // cerr<<ans<<'\n';
    for(int mex=2;mex<n;mex++)
    {
        int l2=pa[mex];
        int r2=pb[mex];
        if(l2>r2)swap(l2,r2);
        ll ans1=1,ans2=1;
        if((l<l2&&l2<r)||(l<r2&&r2<r))
        {
            ans1=0;
            ans2=0;
        }
        else if(r2<l)
        {
            ans1=abs(l-r2);
            ans2=abs(n-r)+1;
        }
        else if(l2>r)
        {
            ans1=abs(l-1)+1;
            ans2=abs(r-l2);
        }
        else
        {
            ans1=abs(l-l2);
            ans2=abs(r-r2);
        }
        l=min(l,l2);
        r=max(r,r2);
        ans+=(ans1*ans2);
        // cerr<<l<<' '<<r<<' '<<ans1<<' '<<ans2<<'\n';
    }
    ans+=1;
    cout<<ans<<'\n';
}