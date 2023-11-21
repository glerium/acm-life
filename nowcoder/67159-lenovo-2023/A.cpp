#include <bits/stdc++.h>
#define int long long 
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
constexpr int maxn=2e5+10;
int t,n,ct[10],chosen[10];
vector<int> nw;
bitset<maxn> v;
signed main() {
    // ios::sync_with_stdio(false);
    cin>>t;
    assert(t<=100);
    while (t--) {
        cin>>n;
        assert(n<=200000);
        rep(i,0,9) ct[i]=chosen[i]=0;
        nw.clear();
        v.reset();
        rep(i,1,n) {
            int tmp; cin>>tmp;
            assert(tmp<=9);
            assert(tmp>=0);
            ct[tmp]++;
        }
        per(i,9,0) {
            if(i%3==0) chosen[i]=ct[i];
            else {
                chosen[i]=ct[i]/3*3;
                rep(j,1,ct[i]%3) nw.push_back(i);
            }
        }
        int nwcnt=nw.size();
        rep(i,0,nwcnt-1) {
            if(v[i]) continue;
            rep(j,i+1,nwcnt-1) {
                if(v[j]) continue;
                if((nw[i]+nw[j])%3==0) {
                    chosen[nw[i]]++;
                    chosen[nw[j]]++;
                    v[i]=v[j]=true;
                    break;
                }
            }
        }
        int chosen_cnt=0;
        rep(i,1,9) chosen_cnt+=chosen[i];
        if(chosen_cnt==0) cout<<(ct[0]?0:-1)<<endl;
        else {
            per(i,9,0) {
                rep(j,1,chosen[i])
                    cout<<i;
            }
            cout<<endl;
        }
    }
    return 0;
}