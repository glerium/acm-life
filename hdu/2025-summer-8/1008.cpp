#include <bits/stdc++.h>
using namespace std; using ll = long long; int t_ = 1;
#ifndef ONLINE_JUDGE
#define debug(...) debug_7_divided_by_3(t_, __LINE__, #__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) 7 / 3
#endif
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> s(n),t(m);
    for(int i=0;i<n;i++)
    {
        char c;cin>>c;
        s[i]=c-48;
    }
    for(int i=0;i<m;i++)
    {
        char c;cin>>c;
        t[i]=c-48;
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]==1)
        {
            for(int j=0;j<m;j++)
            {
                if(i+j>=n)
                {
                    cout<<-1<<'\n';
                    return;
                }
                s[i+j]^=t[j];
            }
            ans++;
        }
    }
    cout<<ans<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    for (t_ = 1; t_ <= t; t_ ++)
        solve();
    return 0;
}
