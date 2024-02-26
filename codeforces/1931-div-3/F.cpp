#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n,k; cin>>k>>n;
    vector<vector<int>> a;
    for(int i=1;i<=n+1;i++) a.push_back(vector<int>(k+10));
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=k;j++) cin>>a[i][j];
    }
    vector<double> num(k+10);
    set<int> st;
    for(int i=2;i<=k;i++) {
        num[a[1][i]]=i;
        st.insert(a[1][i]);
    }
    int loss=-1;
    for(int i=1;i<=k;i++) if(!st.count(i)) loss=i;
    double mi=-1, mx=k+10;
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=k;j++) {
            if(a[i][j]!=loss) continue;
            if(j!=2) mi=max(mi,num[a[i][j-1]]+0.5);
            if(j!=k) mx=min(mx,num[a[i][j+1]]-0.5);
        }
    }
    if(mx<mi) {
        puts("No");
        goto end;
    }else num[loss]=(mx+mi)/2;
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=k;j++) {
            if(j!=2&&num[a[i][j]]<num[a[i][j-1]]||j!=k&&num[a[i][j]]>num[a[i][j+1]]) {
                puts("No");
                goto end;
            }
        }
    }
    puts("Yes");
end:;
}
int main() {
    int t; cin>>t;
    while(t--) solve();
    return 0;
}