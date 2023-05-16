#include <bits/stdc++.h>
using namespace std;
const int maxn=5e3+10;
int t,n,a[maxn];
int calc(int l,int r){
    vector<int> v,v2;
    for(int i=l;i<=r;i++) v.push_back(a[i]);
    v2=v;
    sort(v.begin(),v.end());
    int ret=0, from=-1, n=r-l;
    bool in=false;
    for(int i=0;i<n;i++) {
        if(from==-1) {
            if(v[i]!=v2[i]) {
                from=i;
                in=true;
            }
        }else{
            if(v[i]!=v2[i]&&in==false) {
                in=true;
                from=i;
            }else if(v[i]==v2[i]&&in==true&&i-from!=1) {
                in=false;
                ret+=i-1-from;
            }
        }
    }
    if(in) ret+=n-from;
    printf("l=%d, r=%d, ret=%d\n",l,r,ret);
    return ret;
}
int main() {
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=0;
        for(int i=1;i<=n;i++) {
            for(int j=i;j<=n;j++){
                ans+=calc(i,j);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}