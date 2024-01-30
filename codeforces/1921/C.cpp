#include <bits/stdc++.h>
#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=2e5+10;
int _,n,f;
ll a,b,q[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin>>_;
    while(_--) {
        cin>>n>>f>>a>>b;
        rep(i,1,n) cin>>q[i];
        ll c=0;
        rep(i,1,n) c+=min(b,a*(q[i]-q[i-1]));
        puts(c<f?"YES":"NO");
    }
    return 0;
}