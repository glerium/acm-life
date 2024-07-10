#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
typedef long long ll;
using namespace std;
struct Good {
    ll p,s;
    bool operator<(const Good& rhs)const{
        return p+s<rhs.p+rhs.s;
    }
}s[1005],t[1005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,b; cin>>n>>b;
    rep(i,1,n) cin>>s[i].p>>s[i].s;
    int anss = 0;
    rep(i,1,n) {
        rep(j,1,n) t[j] = s[j];
        t[i].p /= 2;
        sort(t+1,t+1+n);
        int ans = 0;
        ll sum = 0;
        rep(j,1,n) {
            if(sum + t[j].p + t[j].s <= b) {
                sum += t[j].p + t[j].s;
                ans++;
            }else break;
        }
        anss = max(anss,ans);
    }
    cout << anss << endl;
}