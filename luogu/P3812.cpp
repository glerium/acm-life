#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=107;
int n;
long long a[maxn],r[maxn];
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) {
        for(int j=50;j>=0;j--) {
            if(a[i]&(1ll<<j)) {
                if(r[j]==0) {
                    r[j]=a[i];
                    break;
                }else{
                    a[i]^=r[j];
                }
            }
        }
    }
    long long ans;
    bool first=true;
    for(int i=50;i>=0;i--) {
        if(first) {
            if(r[i]) {
                ans=r[i];
                first=false;
            }
        }else{
            if((ans&(1ll<<i))==0) {
                ans^=r[i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}