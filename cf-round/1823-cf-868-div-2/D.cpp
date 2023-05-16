#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5+10;
int t,n,k,a[30],c[30];
int main(){
    cin>>t;
    while(t--) {
        string s;
        cin>>n>>k;
        for(int i=1;i<=k;i++) cin>>a[i];
        for(int i=1;i<=k;i++) cin>>c[i];
        int idx=0;
        bool good=true;
        for(int i=1;i<=k;i++) {
            if(i>1&&(c[i]-c[i-1]>a[i]-a[i-1])) {
                good=false;
                break;
            }
            if(i==1&&c[i]>a[i]) {
                good=false;
                break;
            }
            if(i==1) {
                for(int j=1;j<=c[i]-3;j++) s.push_back('a');
                for(int j=c[i]-2;j<=a[i];j++) {
                    s.push_back('a'+idx);
                    idx=(idx+1)%3;
                }
            }else {
                for(int j=1;j<=c[i]-c[i-1];j++) s.push_back('c'+i-1);
                for(int j=a[i-1]+c[i]-c[i-1]+1;j<=a[i];j++) {
                    s.push_back('a'+idx);
                    idx=(idx+1)%3;
                }
            }
        }
        if(good) cout<<"YES"<<endl<<s<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}