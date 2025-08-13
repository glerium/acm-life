#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll NEG = (ll)-9e18;

struct Mat {
    ll a[4][4];
    Mat() {
        for(int i=0;i<4;i++) for(int j=0;j<4;j++) a[i][j]=NEG;
    }
};

Mat mul(const Mat &A, const Mat &B){
    Mat C;
    for(int i=0;i<4;i++){
        for(int k=0;k<4;k++){
            if (A.a[i][k]==NEG) continue;
            for(int j=0;j<4;j++){
                if (B.a[k][j]==NEG) continue;
                C.a[i][j] = max(C.a[i][j], A.a[i][k] + B.a[k][j]);
            }
        }
    }
    return C;
}

struct SegTree {
    int n;
    vector<Mat> st;
    SegTree(int _n=0){ init(_n); }
    void init(int _n){
        n = _n;
        st.assign(4*n+5, Mat());
    }
    static Mat leafMat(ll val){
        Mat M;
        for(int s=0;s<4;s++){
            // pick 0 -> end with 0, gain 0
            M.a[s][0] = max(M.a[s][0], 0LL);
            // pick 1 -> allowed only if s < 3
            if(s < 3){
                M.a[s][s+1] = max(M.a[s][s+1], val);
            }
        }
        return M;
    }
    void build(int p,int l,int r,const vector<ll> &arr){
        if(l==r){
            st[p] = leafMat(arr[l-1]);
            return;
        }
        int m=(l+r)>>1;
        build(p<<1,l,m,arr);
        build(p<<1|1,m+1,r,arr);
        st[p] = mul(st[p<<1], st[p<<1|1]);
    }
    void build(const vector<ll> &arr){
        if(n==0) return;
        build(1,1,n,arr);
    }
    void update(int p,int l,int r,int idx,ll val){
        if(l==r){
            st[p] = leafMat(val);
            return;
        }
        int m=(l+r)>>1;
        if(idx<=m) update(p<<1,l,m,idx,val);
        else update(p<<1|1,m+1,r,idx,val);
        st[p] = mul(st[p<<1], st[p<<1|1]);
    }
    void update(int idx, ll val){
        update(1,1,n,idx,val);
    }
    ll query_full_cycle(){
        Mat &M = st[1];
        ll ans = 0;
        bool any=false;
        for(int s=0;s<4;s++){
            if (M.a[s][s] != NEG){
                if(!any){ ans = M.a[s][s]; any=true; }
                else ans = max(ans, M.a[s][s]);
            }
        }
        if(!any) return 0; // if nothing valid (shouldn't happen) 
        return ans;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if(!(cin>>T)) return 0;
    while(T--){
        int n,q;
        cin>>n>>q;
        vector<ll> a(n);
        for(int i=0;i<n;i++) cin>>a[i];
        SegTree st(n);
        st.build(a);
        cout << st.query_full_cycle() << '\n';
        for(int i=0;i<q;i++){
            int x; ll v;
            cin>>x>>v;
            st.update(x, v);
            cout << st.query_full_cycle() << '\n';
        }
    }
    return 0;
}
