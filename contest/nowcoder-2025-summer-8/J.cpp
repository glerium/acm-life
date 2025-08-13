#include <bits/stdc++.h>
using namespace std;
vector<int> get(int n)
{
    vector<int> a(n);
    int ceil=(n+2)/3;
    int tot=1;
    int tot2=2;
    for(int i=0;i<n;i++)
    {
        a[i]=tot;
        tot+=ceil;
        if(tot>n)
        {
            tot=tot2;
            tot2++;
        }
    }
    for(int i=max(0,n-5);i+2<n;i++)
    {
        array<int,3> b={a[i],a[i+1],a[i+2]};
        sort(b.begin(), b.end());
        if(b[0]+b[1]>b[2])
        {
            int idx=min_element(a.begin()+i,a.begin()+i+3)-a.begin();
            swap(a[0],a[idx]);
        }
    }
    reverse(a.begin(), a.end());
    // println("{}",a);
    return a;
}
void solve()
{
    int n,m;
    cin>>n>>m;
    m--;
    int len=(n-m-2);
    // cout<<len<<'\n';
    if(len==0)cout<<-1<<'\n';
    else
    {
        vector<int> ans=get(len);
        for(int i=n-m-1;i<=n;i++)ans.push_back(i);
        for(int i=0;i<n;i++)cout<<ans[i]<<" \n"[i==n-1];
        
    }     
} 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t--)solve();
    return 0;
}