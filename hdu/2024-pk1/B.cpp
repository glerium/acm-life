#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn=5;
int n,k,p,a[maxn];
ll ans[maxn],f[maxn][maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>k>>p;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        for(int j=0;j<k;j++)
            f[i][j] = f[i-1][(j-a[i]%k+k)%k];
        f[i][a[i]%k]++;
    }
    for(int i=1;i<=n;i++) {
        ans[i] = (ans[i-1] + a[i] / k) % p;
        for(int j=0;j<k;j++) {
            if(j+a[i]%k<k) continue;
            ans[i] = (ans[i] + f[i-1][j]) % p;
        }
    }
    ll ret = 0;
    for(int i=1;i<=n;i++) ret=(ret+ans[i])%p;
    cout << ret << endl;
}