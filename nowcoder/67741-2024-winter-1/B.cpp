#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1e5+10;
constexpr int pt[6][2]={{-1,1},{1,-1},{-1,-1},{1,1},{1,0},{-1,0}};
int t,n,r[maxn],c[maxn];
// map<int,int> mp;
set<pair<int,int>> st;
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        st.clear();
        rep(i,1,n) cin>>r[i]>>c[i];
        int ans=3;
        rep(i,1,n) {
            if(r[i]==1&&c[i]==-1||r[i]==1&&c[i]==1||r[i]==2&&c[i]==0)
                ans--;
        }
        int al=2,ar=2;
        rep(i,1,n) st.insert(make_pair(r[i],c[i]));
        rep(i,1,n) {
            if(c[i]<0) {
                rep(j,0,5) {
                    if(st.count({r[i]+pt[j][0],c[i]+pt[j][1]}))
                        al=0;
                }
                al=min(al,1);
            } else if(c[i]>0) {
                rep(j,0,5) {
                    if(st.count({r[i]+pt[j][0],c[i]+pt[j][1]}))
                        ar=0;
                }
                ar=min(ar,1);
            } else {
                al=min(al,1);
                ar=min(ar,1);
            }

        }
        ans=min(ans,al+ar);
        cout<<ans<<endl;
    }
    return 0;
}