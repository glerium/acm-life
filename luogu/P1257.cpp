#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef pair<double,double> pdd;
const int maxn=1e4+10;
int n;
pdd p[maxn];
double dis(pdd x,pdd y) {
    return sqrt((x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second));
}
int main() {
    cin>>n;
    rep(i,1,n) cin>>p[i].first>>p[i].second;
    double ans=1e100;
    rep(i,1,n) {
        rep(j,i+1,n) {
            ans=min(ans,dis(p[i],p[j]));
        }
    }
    cout<<fixed<<setprecision(4)<<ans<<endl;
    return 0;
}