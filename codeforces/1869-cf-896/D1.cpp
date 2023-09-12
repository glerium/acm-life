#include <bits/stdc++.h>
#define yes puts("Yes")
#define no puts("No")
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
int n,t;
vector<int> pt; // power of two
int cta[50], ctm[50];
ll a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    for(int i=0;i<40;i++) pt.push_back(1ll<<i);
    while(t--) {
        for(int i=0;i<=45;i++) cta[i]=ctm[i]=0;
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        ll s = 0;
        for(int i=1;i<=n;i++) s+=a[i];
        if(s%n!=0){
            no;
            continue;
        }else{
            s/=n;
            bool ok=true;
            for(int i=1;i<=n;i++) {
                if(a[i]==s) continue;
                if(a[i]>s){
                    bool ok=false;
                    for(int j=0;j<=40;j++) {
                        for(int k=j+1;k<=40;k++) {
                            if((1ll<<k)-(1ll<<j)==a[i]-s) {
                                ok=true;
                                ctm[k]++;
                                cta[j]++;
                                break;
                            }
                        }
                        if(ok) break;
                    }
                    if(!ok) {
                        no;
                        goto end_else;
                    }
                }else{
                    bool ok=false;
                    for(int j=0;j<=40;j++) {
                        for(int k=j+1;k<=40;k++) {
                            if((1ll<<k)-(1ll<<j)==s-a[i]) {
                                ok=true;
                                ctm[j]++;
                                cta[k]++;
                                break;
                            }
                        }
                        if(ok) break;
                    }
                    if(!ok) {
                        no;
                        goto end_else;
                    }
                }
            }
            ok=true;
            for(int i=0;i<=40;i++) {
                if(cta[i]!=ctm[i]){
                    ok=false;
                    no;
                    break;
                }
            }
            if(ok) yes;

end_else:
            ;
        }
    }
    return 0;
}