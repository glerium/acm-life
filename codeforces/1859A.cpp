#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int maxn=500;
int t,n,a[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        int mx=-1,mxcnt=0;
        rep(i,1,n) {
            if(mx<a[i]){
                mx=a[i];
                mxcnt=1;
            }else if(a[i]==mx) mxcnt++;
        }
        if(mxcnt!=n){
            cout<<n-mxcnt<<' '<<mxcnt<<endl;
            rep(i,1,n) {
                if(a[i]!=mx)
                    cout<<a[i]<<' ';
            }
            cout<<endl;
            rep(i,1,mxcnt) cout<<mx<<' ';
            cout<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}