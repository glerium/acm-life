#include <bits/stdc++.h>
using namespace std;
const int maxn=107;
int t,n,l[maxn];
int main(){
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>l[i];
        bool found=false;
        for(int i=n;i>=0;i--) {
            int ct=0;   //ct right
            for(int j=1;j<=n;j++) if(l[j]<=i) ct++;
            if(ct==n-i) {
                found=true;
                cout<<i<<endl;
                break;
            }
        }
        if(!found) cout<<-1<<endl;
    }
    return 0;
}