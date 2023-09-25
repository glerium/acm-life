#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
typedef unsigned long long ull;
using namespace std;
const ull base=19191001;
const int maxn=5e3+10;
int _,n;
ull p[maxn],hs[maxn];
char s[maxn];
void init() {
    n=strlen(s+1);
    p[0]=1;
    rep(i,1,n) p[i]=p[i-1]*base;
    rep(i,1,n) hs[i]=hs[i-1]*base+s[i];
}
ull get(int l,int r) {
    return hs[r]-hs[l-1]*p[r-l+1];
}
bool equal(int l1,int r1,int l2,int r2){
    return get(l1,r1)==get(l2,r2);
}
int main() {
    cin>>_;
    while(_--) {
        cin>>(s+1);
        init();
        int ans=0;
        rep(i,1,n-1) {
            int l1=i,r1=i,l2=i+1,r2=i+1;
            while(l1>=1&&r2<=n) {
                if(equal(l1,r1,l2,r2)) {
                    r1=l1-1,l2=r2+1;
                    ans++;
                    l1=r1,r2=l2;
                }else{
                    l1--,r2++;
                }
            }
        }
        cout<<ans<<endl;
    }
}