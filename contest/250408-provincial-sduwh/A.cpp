#include <bits/stdc++.h>
using namespace std;
int main()
{
    int c,n;
    cin>>c>>n;
    vector<int> a(n+2,1e9);
    for(int i=1;i<=n;i++)cin>>a[i];
    auto check=[&](int x)->bool
    {
        int tmp=0;
        for(int i=0;i<=n+1;i++)
        {
            if(a[i]<x)tmp++;
            else tmp=0;
            if(tmp>c)return false;
        }  
        return true;
    };
    int l=-100,r=100;
    int ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {l=mid+1;ans=mid;}
        else r=mid-1;
    }
    cout<<ans<<'\n';
}