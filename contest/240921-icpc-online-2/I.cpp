#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
void solve()
{
    vector<int> a(32);
    ull n;cin>>n;
    for(int i=0;i<32;i++)
        a[i]=(n&(1ULL<<i))!=0;
    // for(int i=0;i<32;i++)
    //     cout<<a[i]<<" \n"[i%8==7];
    int p=32;
    for(int i=31;i>=0;i--)
    {
        if(a[i]==1)
        {
            a[p-1]=1;
            for(int j=p-2;j>=i;j--)
                a[j]=-1;
            p=i;
        }
    }
    bool ok=1;
    for(int i=0;i<31;i++)
        if(a[i]==0&&a[i+1]==0)
        ok=0;
    if(ok==0)
    {
        cout<<"NO\n";
        return;
    }
    else
    {
        cout<<"YES\n";
        for(int i=0;i<32;i++)
            cout<<a[i]<<" \n"[i%8==7];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;while(t--)solve();
    return 0;
}