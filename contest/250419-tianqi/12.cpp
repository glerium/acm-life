#include <bits/stdc++.h>
#define int long long
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
int n; ll a, b; 
int t1[20], ct1, t2[20], ct2;
int r[20];
ll now;
vector<ll> ans;
void getans(int k, bool low, bool high) {
    if(k >= n) {
        ans.push_back(now);
        return;
    }
    int mi, mx;
    if(low)
        mi = t1[k+1];
    else
        mi = 0;
    if(high)
        mx = t2[k+1];
    else
        mx = 9;
    rep(i,mi,mx) {
        int kk = k+1;
        if(kk % 2 == 0 && i % 2 != 0) continue;
        if(kk % 5 == 0 && i % 5 != 0) continue;
        if(kk == 10 && i != 0) continue;
        if((now * 10 + i) % kk != 0) continue;
        r[kk] = i;
        now = now * 10 + i;
        bool nlow = low && (i == t1[kk]);
        bool nhigh = high && (i == t2[kk]);
        getans(kk, nlow, nhigh);
        now /= 10;
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> a >> b;
    {
        ll a_ = a, b_ = b;
        while(a_) {
            t1[++ct1] = a_ % 10;;
            a_ /= 10;
        }
        while(b_) {
            t2[++ct2] = b_ % 10;
            b_ /= 10;
        }
        for(int l=1,r=ct1;l<=r;l++,r--) {
            swap(t1[l], t1[r]);
        }
        for(int l=1,r=ct2;l<=r;l++,r--) {
            swap(t2[l], t2[r]);
        }
    }
    if(ct1 < n) {
        ct1 = n;
        t1[1] = 1;
        rep(i,2,n) t1[i] = 0;
    }
    if(ct2 > n) {
        ct2 = n;
        rep(i,1,n) t2[i] = 9;
    }
    getans(0, true, true);
    sort(ans.begin(), ans.end());
    if(ans.size()) {
        for(auto i : ans)
            cout << i << endl;
    }else{
        cout << "No Solution" << endl;
    }
    return 0;
}
