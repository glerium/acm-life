#include <bits/stdc++.h>
#define double long double
using namespace std; using ll = long long; int t_ = 1;
void solve()
{
    int n,m;
    double k;
    cin>>n>>m>>k;
    int r0;
    cin>>r0;
    vector<double> dp(500,-1);
    dp[0]=r0;
    vector<int> p(n);
    for(int i=0;i<n;i++) cin >> p[i];
    for(int i=0;i<n;i++)
    {
        for(int j=499;j>0;j--)
        {
            if(dp[j-1] >= 0)
                dp[j]=max(dp[j],(1-k)*dp[j-1]+k*p[i]);
        }
    }
    // for(int i=0;i<n;i++)println(fout,"{} {:.16f}",i+1,dp[i]);
    double ans = 0;
    for(int i=0;i<500;i++) {
        if(i + m >= n || i == 499) {
            ans = max(ans, dp[i]);
        }
    }
    cout<<fixed<<setprecision(12)<<ans<<'\n';
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
