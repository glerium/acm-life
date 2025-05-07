#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)
    {
        string s;cin>>s;
        int b[3]={};
        for(int j=0;j<3;j++)cin>>b[j];
        for(int j=0;j<3;j++)if(b[j]==-1)b[j]=301;
        a[i]=*min_element(b,b+3);
    }
    sort(a.begin(),a.end());
    // for(int i=0;i<n;i++)cerr<<a[i]<<' ';
    int ans=0;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i];
        if(sum<=300)ans++;
        else break;
    }
    cout<<ans<<'\n'; 
}